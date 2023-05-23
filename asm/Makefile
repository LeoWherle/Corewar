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

NAME = asm

SRC =	src/asm_main.c	\
		src/free_lists.c	\
		src/compiler/command_to_data.c	\
		src/compiler/add_param.c	\
		src/compiler/replace_label.c	\
		src/compiler/get_params.c	\
		src/compiler/print_compile_code.c	\
		src/parsing/code_parser.c \
		src/parsing/put_info_to_list.c 		\
		src/parsing/fill_header.c	\
		src/parsing/check_label.c	\

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

.PHONY: all clean fclean re debug gprof perf lib_build
