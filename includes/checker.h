/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:02:53 by jamendoe          #+#    #+#             */
/*   Updated: 2023/06/05 10:02:56 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H

# define INT 0
# define NOT_INT 1

# define SORT_ASC 0
# define SORT_DES 1

# define SORT_NO -1
# define SORT_YES 1

# define NO_DUPLICATES 0
# define DUPLICATES 1

# define MIN 0
# define MAX 1
# define TWO_ELM 2
# define MIN_STACK 3
# define MIN_STACKB 5

# define STACK_A 97
# define STACK_B 98
# define BOTH_SWAP 115
# define BOTH_REV 114
# define NO_WRITE 110

# define RANK_0 0
# define RANK_1 1
# define RANK_2 2

# define NEGATIVE -1
# define POSITIVE 1

# define MIN_POS "-2147483648"
# define MAX_POS "2147483647"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node{
	int				number;
	int				rank;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_move{
	int	total;
	int	a;
	int	b;
}	t_move;

typedef struct s_action{
	char			*mv;
	struct s_action	*next;
}	t_action;

t_node		*ft_make_stack_from_str(char *str);
int			ft_validate_arg(char *str);
void		ft_exit_stderror(void);
int			ft_str_is_int(char *nptr);
int			ft_test_str_int(char *nptr, int i, int len, char *max_min);
t_node		*ft_create_stack(int size, char **array);
t_node		*ft_create_node_stack(char *arg);
t_node		*ft_make_stack(t_node *stack, t_node *number);
void		ft_clean_array(int size, char **array);
int			ft_str_len(int argc, char **argv);
char		*ft_make_str(int size, int argc, char **argv);
void		ft_create_rank(t_node **stack);
int			ft_count_node_stack(t_node *stack);
int			ft_node_position(t_node **stack, t_node *current, int size_stack);
void		ft_test_asc_dup(t_node **stack_a, int size);
int			ft_test_duplicates(t_node *stack, int size);
int			ft_stack_is_sorted(t_node *stack, int type_sort);
void		ft_clean_stack_a(t_node **stack);
void		ft_sort_evaluation(t_node **stack_a, t_node **stack_b);
t_action	*ft_get_instructions(void);
t_action	*ft_create_action_list(t_action **evaluation, char **inst);
void		ft_do_instr(t_node **stack_a, t_node **stack_b, t_action *inst);
void		ft_swap(t_node **stack, char stack_letter);
void		ft_both_swap(t_node **stack_a, t_node **stack_b, char stack_letter);
void		ft_push(t_node **stack_a, t_node **stack_b, char stack_letter);
void		ft_push_with_stack(t_node **stack_a, t_node **stack_b);
void		ft_write_push(char stack_letter);
void		ft_do_instr_rot(t_node **stack_a, t_node **stack_b, t_action *inst);
void		ft_rotate(t_node **stack, char stack_letter);
void		ft_both_rotate(t_node **a, t_node **b, char stack_letter);
void		ft_reverse_rotate(t_node **stack, char stack_letter);
void		ft_both_reverse_rotate(t_node **a, t_node **b, char stack_letter);
void		ft_clean_inst_list(t_action **list);
void		ft_test_int(char **str, int size, char *sent);

#endif
