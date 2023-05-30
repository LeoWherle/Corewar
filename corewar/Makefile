##
## EPITECH PROJECT, 2023
## 42sh
## File description:
## Makefile
##

BEGINL		= 	\033[A
CLEARL		= 	\033[2K
COL_END		= 	\033[0m
CLEAR_COL	=	\033[2K\033[A
GRAY		=	\033[1;30m
RED			=	\033[1;31m
GREEN 		= 	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
PURPLE		=	\033[1;35m
CYAN		=	\033[1;36m
WHITE		=	\033[1;37m

RESET		=	\033[0m

NAME = corewar

SRC = src/main.c \
	  src/args/args_init.c \
	  src/args/args_dump.c \
	  src/args/args_prog_nb.c \
	  src/args/args_adress.c \
	  src/args/args_champ.c \
	  src/args/args_champ_error.c \
	  src/args/args_help.c \
	  src/champions/champion_init.c \
	  src/champions/champion_list_create.c \
	  src/processes/process_init.c \
	  src/processes/process_list_create.c \
	  src/display/term_bff_print.c \
	  src/display/debug_print_all.c \
	  src/vm/arena_load.c \
	  src/vm/core_loop.c \
	  src/vm/core_cleanup.c \
	  src/vm/vm_init.c \
	  src/get_arg/get_coding_byte.c	\
	  src/get_arg/param_getter.c	\
	  src/get_arg/param_setter.c	\
	  src/instructions/instruction_exec.c \
	  src/instructions/instruction_getter.c \
	  src/commands/cmd_add.c	\
	  src/commands/cmd_aff.c \
	  src/commands/cmd_and.c \
	  src/commands/cmd_fork.c \
	  src/commands/cmd_ld.c \
	  src/commands/cmd_ldi.c \
	  src/commands/cmd_lfork.c \
	  src/commands/cmd_live.c \
	  src/commands/cmd_lld.c \
	  src/commands/cmd_lldi.c \
	  src/commands/cmd_or.c \
	  src/commands/cmd_st.c \
	  src/commands/cmd_sti.c \
	  src/commands/cmd_sub.c \
	  src/commands/cmd_xor.c \
	  src/commands/cmd_zjmp.c \

TEST_CRIT	=	\

SRC_CRIT = $(SRC)

OBJ = 	$(SRC:.c=.o)

MAKE  = make --no-print-directory

LIBS = ../lib/clist ../lib/op ../lib/cbuffer ../lib/mystr ../lib/serrorh
LIBINC = $(addsuffix /include, $(addprefix -I, $(LIBS)))
LIB_FLAGS = -L../lib -lclist -lop -lcbuffer -lmystr -lserrorh

CFLAGS = -W -Wall -Wextra -Iinclude -I../include $(LIBINC)
LDFLAGS = $(LIB_FLAGS)
CRITFLAGS = -lcriterion --coverage

FILE_AMOUNT = $(shell echo $(SRC) | wc -w | sed -e 's/ //g')
CURRENT_FILES = $(shell find src/ -type f -name "*.o" | wc -l | sed -e 's/ //g')
CURRENT_FILE = $(shell echo "$$(( $(CURRENT_FILES) + 1 ))")
PERCENT = $(shell echo "$$(( $(CURRENT_FILE) * 10 / $(FILE_AMOUNT) ))")
PERCENT_LEFT = $(shell echo "$$(( 10 - $(PERCENT) ))")

%.o: %.c
	@$(CC) $(CFLAGS) $^ -c -o $@
	@echo -en "$(CLEARL)$(BLUE)building$(RESET): [$(GREEN)"
	@for i in `seq 1 $(PERCENT)`; do \
		echo -n "█"; \
	done
	@for i in `seq 1 $(PERCENT_LEFT)`; do \
		echo -n " "; \
	done
	@echo -en  "$(RESET)] ($(CURRENT_FILE)/$(FILE_AMOUNT))"
	@echo -e " [$(CYAN)$(notdir $^)$(RESET)]$(BEGINL)"

$(NAME): lib_build	$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo -e "$(CLEARL)$(GREEN)✓ Compiled $(NAME)$(RESET)$(COL_END)"

all:	$(NAME)

lib_build:
	@for i in $(LIBS); do $(MAKE) -C $$i ; done

clean:
	@rm -f $(OBJ)
	@rm -f unit-tests
	@rm -f *~
	@rm -f #*#
	@rm -f *.gcno*
	@rm -f *.gcda*
	@for i in $(LIBS); do $(MAKE) -C $$i clean; done
	@echo -e "$(CLEARL)$(YELLOW)♻️  Cleaned$(RESET)$(COL_END)"

fclean: clean
	@rm -f $(NAME)
	@rm -f unit-tests
	@for i in $(LIBS); do $(MAKE) -C $$i fclean; done
	@echo -e "$(CLEARL)$(CLEAR_COL)$(YELLOW)♻️  Fcleaned$(RESET)"

re: fclean all

debug: CFLAGS += -g3
debug: CFLAGS += -DDEBUG
debug: lib_build $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LDFLAGS) -g3
	@echo -e "$(CLEARL)$(YELLOW)⚙️  Debug Mode$(RESET)"

cdebug: fclean debug

gprof: CFLAGS += -pg
gprof: lib_build $(OBJ)
	@rm -f gmon.out gprof.txt
	@gcc -o $(NAME) $(OBJ) $(LDFLAGS) -pg
	@echo -e "$(CLEARL)$(YELLOW)⚙️  Gprof Mode$(RESET)"
#	@./$(NAME)
#	@gprof $(NAME) gmon.out > gprof.txt
#	@cat gprof.txt

perf: CFLAGS += -O3
perf: lib_build $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LDFLAGS) -O3
	@echo -e "$(CLEARL)$(BLUE)⚙️  Performance Mode$(RESET)"
	@bash -c "time ./$(NAME)"

bonus: lib_build $(OBJ)
	@ar rc libmycorewar.a $(OBJ)

.PHONY: all clean fclean re debug gprof perf lib_build
