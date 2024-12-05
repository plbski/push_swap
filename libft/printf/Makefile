NAME = libftprintf.a
LIBC = ar rcs
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)

SRC = ft_printf.c ft_printdec.c ft_printptr.c ft_printunsigned.c ft_puthex.c

$(NAME): $(OBJS) $(LIBFT)
	@$(LIBC) $(NAME) $(OBJS)

.c.o:
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

clean:
	@echo "-> Cleaning printf object files.."
	@$(RM) $(OBJS) 

fclean: clean
	@echo "-> Removing archive..."
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 