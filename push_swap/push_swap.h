/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:20:06 by hthant            #+#    #+#             */
/*   Updated: 2024/11/03 17:54:10 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

// from utils.c

void				ft_free_stack(t_stack **stack);
void				ft_free(char **value);
int					is_sorted(t_stack **stack);
char				**args_help(int ac, char **av, char **args, char **temp);
void				sort_3_helper(t_stack **stack_a, int min_index);

// from check_args.c
int					ft_check_args(int argc, char **argv);
int					ft_check_numbers(char *str);
int					ft_duplicate(int num, char **argv, int i);
char				**ft_args(int ac, char **av);
int					array_count(int ac, char **av);

// from t_stack.c
t_stack				*ft_lastnode(t_stack *head);
t_stack				*create_node(int value);
int					ft_stacksize(t_stack *head);
void				ft_lstadd_b(t_stack **stack, t_stack *new);
void				ft_print_stack(t_stack *stack);

// from index_check
t_stack				*get_mini(t_stack **stack);
void				asign_index(t_stack **stack);

// from src
int					push(t_stack **to_stack, t_stack **from_stack);
int					pa(t_stack **stack_a, t_stack **stack_b);
int					pb(t_stack **stack_a, t_stack **stack_b);

int					reverse(t_stack **stack);
int					rra(t_stack **stack_a);
int					rrb(t_stack **stack_b);
int					rrr(t_stack **stack_a, t_stack **stack_b);

int					rotate(t_stack **stack);
int					ra(t_stack **stack_a);
int					rb(t_stack **stack_b);
int					rr(t_stack **stack_a, t_stack **stack_b);

int					swap(t_stack **stack);
int					sa(t_stack **stack_a);
int					sb(t_stack **stacK_b);
int					ss(t_stack **stack_a, t_stack **stack_b);

// redix_sort
int					get_max_bit(t_stack **stack);
void				radix_sort(t_stack **stack_a, t_stack **stack_b);

// from non_complex
int					get_min_index(t_stack *stack);
void				sort_3(t_stack **stack_a);
void				sort_4(t_stack **stack_a, t_stack **stack_b);
void				sort_5(t_stack **stack_a, t_stack **stack_b, int size);
void				non_complex_sort(t_stack **stack_a, t_stack **stack_b);

#endif
