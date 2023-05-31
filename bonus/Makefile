##
## EPITECH PROJECT, 2023
## B-CPE-200-TLS-2-1-corewar-lucien.pineau
## File description:
## Makefile for the bonus binary
##

NAME			=	bonus

SRCS			=	demo_content.c	\
					demo_game.c		\
					demo_main.c		\
					demo_interface.c\
					user_param.c\
					vm_container.c

LIBS = ../lib/clist ../lib/op ../lib/cbuffer ../lib/mystr ../lib/serrorh

LIBINC = $(addsuffix /include, $(addprefix -I, $(LIBS)))

LIB_FLAGS = -L../lib -lclist -lop -lcbuffer -lmystr -lserrorh

LIBINC			=	$(addsuffix /include, $(addprefix -I../lib/, $(LIBS)))

LIBINC			+=	 -Ilib/mycsfml/include -I../corewar/include

CFLAGS = -W -Wall -Wextra -Iinclude -I../include $(LIBINC)

CSFML		=	-lcsfml-audio -lcsfml-graphics -lcsfml-window -lcsfml-system

LDFLAGS			=	-Llib/mycsfml -lmycsfml -L../corewar -lmycorewar $(LIB_FLAGS)

SRCS			:=	$(addprefix src/, $(SRCS))

OBJS			=	$(SRCS:.c=.o)

Y				=	\033[1;33m
B				=	\033[1;34m
G				=	\033[1;32m
R				=	\033[1;31m
RST				=	\033[0m

BONUSLIB		=	lib/mycsfml/libmycsfml.a

THEME			=

$(NAME):	$(BONUSLIB) $(OBJS)
	@gcc -o $@ $^ $(CFLAGS) $(LDFLAGS) $(CSFML)
	@printf "\n$(G)$(NAME) $(Y)[$(G)✓$(Y)]$(RST)\n"

all:		$(NAME)

%.o:		%.c
	@gcc -o $@ -c $< $(CFLAGS) $(LDFLAGS) $(THEME)
	@printf "$(Y)$(notdir $(@:.o=))[$(G)✓$(Y)]$(RST) "

clean:
	@make -C lib/mycsfml fclean
	@rm -f $(OBJS) vgcore.* coding-style-reports.log
	@rm -f src/vgcore.*
	@printf "$(Y)Temp_$(NAME)_files[$(R)✗$(Y)]$(RST) "

fclean:		clean
	@rm -f $(NAME) debug btests
	@printf "\n$(R)$(NAME) $(Y)[$(R)✗$(Y)]$(RST)\n"

re:			fclean all

debug:		CFLAGS += -g3
debug:		clean $(OBJS)
	@gcc -o $@ $(OBJS) $(CFLAGS)
	@printf "\n$(G)$@ $(Y)[$(G)✓$(Y)]$(RST)\n"

val_run:	debug
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$<

$(BONUSLIB):
	@make -C lib/mycsfml THEME=$(THEME)

.PHONY: all clean fclean re val_run
