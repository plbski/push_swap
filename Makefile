NAME = push_swap
CHECKER = checker
CC = cc
RM = rm -rf
FLAGS = -Werror -Wextra -Wall -g3

SRC = $(MAIN_SRC) $(OP_SRC) $(ALGO_SRC)
MAIN_SRC = main.c init.c utils.c input_check.c

ALGO = algo1.c best_move.c rot.c
ALGO_SRC = $(addprefix algo/, $(ALGO))

OP = operation.c pusha.c pushb.c
OP_SRC = $(addprefix op/, $(OP))

BONUS_SRC = checker.c checker_input.c checker_init.c checker_utils.c
BONUS_FILES = $(addprefix bonus/, $(BONUS_SRC))

SHARED_FILES = init.c utils.c input_check.c $(OP_SRC)
SHARED_OBJS = $(SHARED_FILES:.c=.o)

LIBFT_A = libft.a
LIBFT_DIR = libft/
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_A))
PRINTF_A = libftprintf.a
PRINTF_DIR = libft/printf/
PRINTF = $(addprefix $(PRINTF_DIR), $(PRINTF_A))
OBJS = *.o
BONUS_OBJS = $(BONUS_FILES:.c=.o)

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY) " - Making libft..." $(NONE)
	@make bonus -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(GRAY) " - Compiling $(NAME)..." $(NONE)
	cc $(FLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJS): $(SRC)
	@echo $(CURSIVE)$(GRAY) " - Making object files..." $(NONE)
	@$(CC) $(FLAGS) -c $(SRC)

$(CHECKER): $(BONUS_OBJS) $(SHARED_OBJS)
	@echo $(CURSIVE)$(GRAY) " - Compiling checker..." $(NONE)
	@$(CC) $(FLAGS) $(BONUS_OBJS) $(SHARED_OBJS) $(LIBFT) $(PRINTF) -o $(CHECKER)
	@echo $(GREEN)"- Checker Compiled -"$(NONE)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME) $(CHECKER)

clean:
	@echo $(CURSIVE)$(GRAY) " -> Cleaning object files.." $(NONE)
	@$(RM) $(OBJS)
	@$(RM) $(BONUS_OBJS)
	@$(RM) $(SHARED_OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) " -> Removing $(NAME) and $(CHECKER)..." $(NONE)
	@$(RM) $(NAME)
	@$(RM) $(CHECKER)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus