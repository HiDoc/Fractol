#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/29 21:32:58 by wescande          #+#    #+#             *#
#*   Updated: 2017/02/15 21:08:25 by wescande         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME		=	libmlx.a

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -O3

LEN_NAME	=	`printf "%s" $(NAME) |wc -c`
DELTA		=	$$(echo "$$(tput cols)-32-$(LEN_NAME)"|bc)

UNAME		=	$(shell uname)

SRC_DIR		=	srcs/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

CONF_FILE	=	minilibx.conf

SRC_BASE	= \
mlx_new_window.c\
mlx_destroy_window.c\
mlx_flush_event.c\
mlx_put_image_to_window.c\
mlx_int_anti_resize_win.c\
mlx_int_get_visual.c\
mlx_int_do_nothing.c\
mlx_hook.c\
mlx_loop.c\
mlx_get_data_addr.c\
mlx_clear_window.c\
mlx_int_wait_first_expose.c\
mlx_expose_hook.c\
mlx_xpm.c\
mlx_string_put.c\
mlx_pixel_put.c\
mlx_destroy_image.c\
mlx_rgb.c\
mlx_get_color_value.c\
mlx_loop_hook.c\
mlx_init.c\
mlx_int_set_win_event_mask.c\
mlx_mouse_hook.c\
mlx_int_param_event.c\
mlx_new_image.c\
mlx_int_str_to_wordtab.c\
mlx_key_hook.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
DIR			=	$(sort $(dir $(OBJS)))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

SHELL		:=	bash

all:
	@$(MAKE) -j $(NAME)

ifeq ($(UNAME), Darwin)
$(NAME):
	@touch $(NAME)
	@printf "\r\033[38;5;117m✓ MAKE $(NAME)\033[0m\033[K\n"
endif

ifeq ($(UNAME), Linux)
-include $(CONF_FILE)

$(CONF_FILE): configure
	@./configure

$(NAME):		$(CONF_FILE) $(OBJ_DIR) $(OBJS) Makefile
	@ar rcs $(NAME) $(OBJS)
	@printf "\r\033[38;5;117m✓ MAKE $(NAME)\033[0m\033[K\n"
endif

$(DIR) :
	@mkdir -p $@

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB) - 1))))
	@$(eval COLOR=$(shell list=(160 196 202 208 215 221 226 227 190 154 118 82 46); index=$$(($(PERCENT) * $${#list[@]} / 100)); echo "$${list[$$index]}"))
	@printf "\r\033[38;5;%dm⌛ [%s]: %2d%% `printf '█%.0s' {0..$(DONE)}`%*s❙%*.*s\033[0m\033[K" $(COLOR) $(NAME) $(PERCENT) $(TO_DO) "" $(DELTA) $(DELTA) "$(shell echo "$@" | sed 's/^.*\///')"
	@$(CC) $(FLAGS) -MMD -c $< -o $@\
		-I$(INC_DIR) \
		-I$(INC)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

clean :
	@if [ -e $(OBJ_DIR) ]; \
	then \
		rm -rf $(OBJ_DIR); \
		printf "\r\033[38;5;202m✗ clean $(NAME).\033[0m\033[K\n"; \
	fi;

fclean :		clean
	@if [ -e $(CONF_FILE) ]; \
	then \
		rm -rf $(CONF_FILE); \
	fi;
	@if [ -e $(NAME) ]; \
	then \
		rm -rf $(NAME); \
		printf "\r\033[38;5;196m✗ fclean $(NAME).\033[0m\033[K\n"; \
	fi;

re : fclean
	@$(MAKE) -j $(NAME)

.PHONY :		fclean clean re

-include $(OBJS:.o=.d)
