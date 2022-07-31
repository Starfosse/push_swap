/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <abouleau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:07:07 by abouleau          #+#    #+#             */
/*   Updated: 2022/07/13 20:07:07 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int			do_instructs1(char *line, t_list **list_a, t_list **list_b);
int			do_instructs2(char *line, t_list **list_a, t_list **list_b);
int			do_instructs3(char *line, t_list **list_a, t_list **list_b);
int			do_instructs4(char *line, t_list **list_a, t_list **list_b);
size_t		ft_strlen2(char *str);
char		*ft_strjoin2(char *s1, char *s2);
char		*ft_strchr2(char *s, int c);
char		*get_next_line(int fd);
char		*get_read(int fd, char *save);
char		*get_line(char *save);
char		*get_save(char *save);
int			msg_error(t_list **list_a);
int			multiple_args(t_list **list, char **argv);
int			one_arg(t_list **list, char *argv);
void		clean_split(char **split);
void		ft_clean(t_list **list_a);
int			in_order(t_list *list_a);
void		ft_swap1(t_list **list_a);
void		ft_rotate1(t_list **list_a);
void		ft_reverse_rotate1(t_list **list_a);
void		ft_push1(t_list **list_a, t_list **list_b);
void		ft_reverse_rotate_a_b1(t_list **list_a, t_list **list_b);
void		ft_rotate_a_b1(t_list **list_a, t_list **list_b);
void		ft_swap_a_b1(t_list **list_a, t_list **list_b);
long int	ft_latoi(const char	*nptr);
int			ft_check_list(t_list *list_a);
int			ft_check_int(long int content);
int			ft_check_argv(char *str);

#endif
