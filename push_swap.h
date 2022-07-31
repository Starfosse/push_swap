/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:18:01 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/09 17:22:43 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

# define INT_INF 2147483648

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_stack
{
	long int		*v;
	int				size;
}					t_stack;

void		ft_choice_swap(t_list *list_a);
void		ft_clean(t_list **list_a);
void		ft_putstr(char *str);
long int	ft_latoi(const char	*nptr);
int			ft_check_argv(char *str);
int			ft_check_int(long int content);
int			ft_check_list(t_list *list_a);
void		ft_swap(t_list **list_a, char *str);
void		ft_swap_a_b(t_list **list_a, t_list **list_b);
void		ft_push(t_list **list_a, t_list **list_b, char *str);
void		ft_rotate(t_list **list_a, char *str);
void		ft_rotate_a_b(t_list **list_a, t_list **list_b);
void		ft_reverse_rotate(t_list **list_a, char *str);
void		ft_reverse_rotate_a_b(t_list **list_a, t_list **list_b);
void		ft_push_swap1(t_list *list_a);
int			in_order(t_list *list_a);
void		ft_separate(t_list **la, t_list **lb, long int *answer, int l);
int			is_in_answer(t_list *liste1, long int *answer, int length);
int			no_more_answer(t_list *liste1, long int *answer, int length);
int			ft_choice_rotate(t_list **list_a, long int nbr);
void		ft_smallest(t_list **list_b);
int			ft_find_smaller(t_list **list_a);
void		ft_positif(int *tab, t_list **list_a, t_list **list_b);
void		ft_negatif(int *tab, t_list **list_a, t_list **list_b);
void		ft_negatif_positif(int *tab, t_list **list_a, t_list **list_b);
int			ft_next_big(t_list **list_a);
int			ft_is_biggest(t_list **list_a, long int nbr);
int			ft_count(int i, int j);
int			ft_count2(int i, int j);
int			ft_choice(int **tab, int size);
int			ft_posa(t_list **list_a, long int nbr);
int			ft_posb(t_list **list_b, long int nbr);
int			**ft_save_pos(t_list **list_a, t_list **list_b);
void		ft_push_swap(t_list *list_a);
void		push_swap1(t_list *list_a);
void		ft_sort_little(t_list **list_a);
void		ft_sort_little2(t_list **list_a, t_list **list_b);
int			ft_is_smallest(t_list **list_a, long int nbr);
void		ft_smallest_little(t_list **list_a);
int			ft_one_last(t_list **list_a, long int nbr);
int			ft_one_last2(t_list **list_a, long int nbr);
void		ft_second(t_list **list_a, t_list **list_b);
void		ft_first(t_list **list_a, t_list **list_b);
int			ft_next_small(t_list **list_a);
int			lis3(long int *A, int size);
long int	*lis(long int *A, int size);
long int	*lis2(long int *A, int size, int lis_length, long int *index);
int			multiple_args(t_list **list, char **argv);
int			one_arg(t_list **list, char *argv);
void		clean_split(char **split);
void		clean_tab(int **tab, int size);
void		ft_clean(t_list **list_a);
long int	*list_to_tab(t_list *list_a, int size);
int			msg_error(t_list **list_a);
void		ft_sort_little4(t_list **list_a, t_list **list_b);

#endif
