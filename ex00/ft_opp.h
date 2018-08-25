/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 10:36:01 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/25 12:50:10 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPP_H
# define FT_OPP_H
# include <unistd.h>
# include <stdlib.h>

void			ft_putchar(char c);
void			ft_putnbr(int nb);
int				ft_strlen(char *src);
int				ft_atoi(char *str);
char			*ft_strncpy(char *str, int n);
char			*ft_first_lowest_op(char *expr);
char			*ft_cut_parenthesis(char *expr);
int				compute_expr(char *str, char *op);
int				eval_expr(char *str);
typedef struct	s_opp
{
	char		*op;
	int			(*f)(int, int);
}				t_opp;
int				ft_sub(int a, int b);
int				ft_add(int a, int b);
int				ft_mul(int a, int b);
int				ft_div(int a, int b);
int				ft_mod(int a, int b);
#endif