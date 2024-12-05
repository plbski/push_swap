#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../pushswap.h"
# include <limits.h>

int		checker_init(t_game *game);
int		checker_alpha(char **temp);
int		checker_input(t_stack *lista);
char	*ft_strjoin_free(char *s1, char *s2);
int		is_sorted(t_stack *stack);
int		alloc_lists(t_game *game);
int		alloc_stacks(t_game *game);

#endif