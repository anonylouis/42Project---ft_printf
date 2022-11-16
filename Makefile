GCC = gcc
FLAGS = -Wall -Wextra -Werror -g
NAME = libftprintf.a

SRCS_DIR = ./srcs/
SOURCES = ft_printf.c var.c print_var.c
SRCS = $(addprefix $(SRCS_DIR), $(SOURCES))

OBJS_DIR = ./objs/
OBJECTS = ${SOURCES:.c=.o}
OBJS = $(addprefix $(OBJS_DIR), $(OBJECTS))

HEADERS_DIR = ./includes/
HEADERS_FILES = ft_printf.h
HDRS = $(addprefix $(HEADERS_DIR), $(HEADERS_FILES))

all : $(NAME)

$(NAME) :	$(OBJS)
			ar rcs $(NAME) $^

clean : 
		rm -f $(OBJS)

fclean :	clean 
			rm -f $(NAME) printf

re :	fclean all

bonus : all

test :	all
		$(GCC) $(FLAGS) -Wno-overflow -Wno-format -o printf test.c $(NAME)

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.c $(HDRS)
					mkdir -p $(OBJS_DIR)
					$(GCC) $(FLAGS) -MMD -I $(HEADERS_DIR) -o $@ -c $< 

.PHONY : all re clean fclean
