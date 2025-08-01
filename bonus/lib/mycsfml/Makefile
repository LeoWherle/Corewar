##
## EPITECH PROJECT, 2023
## Public_Library
## File description:
## Template Makefile for a library
##

Y				=	\033[1;33m
B				=	\033[1;34m
G				=	\033[1;32m
R				=	\033[1;31m
RST				=	\033[0m

SRCS			=		canvas/canvas_event.c		\
				canvas/canvas_factory.c		\
				canvas/canvas_update.c		\
				cursor.c					\
				scene/scene_event.c			\
				scene/scene_factory.c		\
				scene/scene_update.c		\
				gratools.c					\
				tools.c						\
				panel/panel_factory.c		\
				panel/panel_hover.c			\
				panel/panel_resize.c		\
				panel/panel_select.c		\
				panel/panel_tests.c			\
				panel/panel.c				\
				rtrans/rtrans_bar_factory.c	\
				rtrans/rtrans_factory.c		\
				rtrans/rtrans_update.c		\
				params/hyper_param.c		\
				params/param_load.c			\
				program/program_event.c		\
				program/program_execute.c	\
				program/program_factory.c	\
				program/program_start.c		\
				ui_panels/button_factory.c	\
				ui_panels/button_utilities.c\
				ui_panels/draggable_factory.c		\
				ui_panels/draggable_update.c		\
				ui_panels/dropdown.c		\
				ui_panels/input_factory.c	\
				ui_panels/input_update.c	\
				ui_panels/empty.c			\
				ui_panels/flex.c			\
				ui_panels/none.c			\
				ui_panels/option_factory.c	\
				ui_panels/option_update.c	\
				ui_panels/slider.c			\
				ui_panels/start_factory.c	\
				ui_panels/start_update.c	\
				ui_panels/text.c			\
				ui_panels/videofoos.c		\
				ui_panels/value_crtl.c		\
				ui_panels/butt_mfoos.c		\
				ui_panels/butt_gfoos.c		\
				ui_panels/butt_user_foos.c

CFLAGS			=	-W -Wall -Wextra -Wpedantic -Iinclude

LNAME			=	libmycsfml.a

SRCS			:=	$(addprefix src/, $(SRCS))

OBJS			=	$(SRCS:.c=.o)

THEME			=

$(LNAME):	$(OBJS)
	@ar rcs $@ $(OBJS)
	@printf "\n$(G)$(LNAME) $(Y)[$(G)✓$(Y)]$(RST)\n"

all:		$(LNAME)

%.o:		%.c
	@gcc -o $@ -c $< $(CFLAGS) $(THEME)
	@printf "$(Y)$(notdir $(@:.o=))[$(G)✓$(Y)]$(RST) "

clean:
	@rm -f $(OBJS) vgcore.* coding-style-reports.log
	@rm -f src/vgcore.*
	@printf "$(Y)Temp_$(LNAME)_files[$(R)✗$(Y)]$(RST) "

fclean:		clean
	@rm -f $(LNAME) debug
	@printf "\n$(R)$(LNAME) $(Y)[$(R)✗$(Y)]$(RST)\n"

re:			fclean all

debug:		CFLAGS += -g3
debug:		re
	@printf "\n$(G)$@ $(Y)[$(G)✓$(Y)]$(RST)"

.PHONY: all clean fclean re
