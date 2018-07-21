NAME = fractol

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

# INCLUDES
INC_PATH = ./includes/ \
		   ./mlx/
LIB = -L ./mlx -lmlx

# SOURCES
SRC_NAME = mandel.c \
		   julias.c \
		   burnin.c \
		   tripe.c \
		   newton.c \
		   main.c \
		   color.c \
		   complex.c \
		   keyhook.c \
		   str_utils.c \
		   fractol.c

SRC_PATH = ./srcs/

# OBJECTS
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./objs/

# PREFIXES
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))


.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) 
	@$(CC) $(CFLAGS) $(OBJ) $(INC) -framework OpenGL -framework AppKit -o \
		$(NAME) $(LIB)
 
$(OBJ) : | $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir objs

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "[\033[92m..\033[0m] Compiling $< into object file.."
	@tput cuu1;tput el;
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "$(ok)  Compiling $< into object file.."

clean : 
	@rm -rf $(OBJ_PATH)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

run : all 
	./fractol Julia
