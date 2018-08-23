NAME		= fractol

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

# INCLUDES
INC_PATH	= ./includes/ \
			  ./mlx/ \
			  /System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/

LIB			= -L ./mlx -lmlx \
			  -lpthread

# SOURCES
SRC_NAME	= fractal.c \
			  main.c \
			  color.c \
			  complex_util.c \
			  complex_math.c \
			  struct_utils.c \
			  hook.c \
			  hook_bis.c \
			  str_utils.c \
			  thread.c \
			  fractol.c

SRC_PATH	= ./srcs/

# OBJECTS
OBJ_NAME	= $(SRC_NAME:.c=.o)
OBJ_PATH	= ./objs/

# PREFIXES
SRC 		= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ 		= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC 		= $(addprefix -I, $(INC_PATH))

#color
YELLOW		= "\\033[33m"
BLUE		= "\\033[34m"
RED			= "\\033[31m"
WHITE		= "\\033[0m"
CYAN		= "\\033[36m"
GREEN		= "\\033[32m"
BOLD		= "\\033[1m"
PINK		= "\\033[95m"

OK			= $(CYAN)OK$(WHITE)
WAIT		= $(RED)WAIT$(WHITE)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) 
	@printf "\rCompiling project $(WAIT)"
	@$(CC) $(CFLAGS) $(OBJ) $(INC) -framework OpenGL -framework AppKit -o \
		$(NAME) $(LIB)
	@printf "\rCompiling project $(OK)   \n"
 
$(OBJ) : | $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir objs

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "\rCompiling $< into object file.. $(WAIT)"
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@printf "\rCompiling $< into object file.. $(OK)   \n"

clean : 
	@rm -rf $(OBJ_PATH)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

run : all 
	@clear
	./fractol Julia
