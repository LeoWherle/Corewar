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

NAME = both

MAKE  = make --no-print-directory

LIBS = lib/clist lib/op lib/cbuffer lib/mystr lib/serrorh
LIBINC = $(addsuffix /include, $(addprefix -I, $(LIBS)))
LIB_FLAGS = -Llib -lclist -lop -lcbuffer -lmystr -lserrorh

CFLAGS = -W -Wall -Wextra -Iinclude $(LIBINC)
LDFLAGS = $(LIB_FLAGS)
CRITFLAGS = -lcriterion --coverage

$(NAME): lib_build	$(OBJ)
	@$(MAKE) -C corewar
	@$(MAKE) -C asm

all:	$(NAME)

lib_build:
	@for i in $(LIBS); do $(MAKE) -C $$i ; done

clean:
	@$(MAKE) -C corewar clean
	@$(MAKE) -C asm clean
	@$(MAKE) -C bonus clean

fclean: clean
	@$(MAKE) -C corewar fclean
	@$(MAKE) -C asm fclean
	@$(MAKE) -C bonus fclean

re: fclean all

cdebug: fclean debug

debug: CFLAGS += -g3
debug: CFLAGS += -DDEBUG
debug: lib_build $(OBJ)
	@$(MAKE) -C corewar debug
	@$(MAKE) -C asm debug

gprof: CFLAGS += -pg
gprof: lib_build $(OBJ)
	@$(MAKE) -C corewar gprof
	@$(MAKE) -C asm gprof

perf: CFLAGS += -O3
perf: lib_build $(OBJ)
	@$(MAKE) -C corewar perf
	@$(MAKE) -C asm perf

tests_run:
	@for i in $(LIBS); do $(MAKE) -C $$i tests_run; done

bonus: lib_build
	@$(MAKE) -C corewar bonus -s
	@$(MAKE) -C bonus -s
	@./bonus/bonus assets/champions/42.cor assets/champions/fenix.cor assets/champions/ebola.cor assets/champions/octobrerouge.cor

random-build: lib_build
	@$(MAKE) -C bonus fclean
	@$(MAKE) -C corewar bonus
	@$(MAKE) -C bonus

.PHONY: all clean fclean re debug gprof perf tests_run lib_build bonus
