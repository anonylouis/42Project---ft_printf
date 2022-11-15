GCC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS_DIR=./srcs/
SOURCES = 
SRCS = $(addprefix $(SRCS_DIR), $(SOURCES))

OBJS_DIR=./objs/
OBJECTS = ${SOURCES:.c=.o}
OBJS = $(addprefix $(OBJS_DIR), $(SOURCES))

HEADERS_DIR = ./includes/
HEADERS_FILES = 
HDRS = $(addprefix $(HEADERS_DIR), $(HEADERS_FILES))

all : $(NAME)

$(NAME) :	$(OBJS)
			ar rcs $(NAME) $^

clean : 
		rm -f $(OBJS)

fclean :	clean 
			rm -f $(NAME)

re :	fclean all

bonus : all

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.c $(HDRS)
					mkdir -p $(OBJS_DIR)
					$(GCC) $(FLAGS) -MMD -I $(HEADERS_DIR) -o $@ -c $< 

.PHONY : all re clean fclean
