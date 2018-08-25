/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 10:58:03 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/25 14:31:32 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_opp.h"

t_opp	g_opptab[] =
{
	{"+", &ft_add},
	{"-", &ft_sub},
	{"*", &ft_mul},
	{"/", &ft_div},
	{"%", &ft_mod}
};

char	*ft_first_lowest_op(char *expr)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (expr[++i] != '\0' && ((expr[i] != '+' && expr[i] != '-') ||
				count > 0))
	{
		if (expr[i] == '(')
			count++;
		else if (expr[i] == ')')
			count--;
	}
	if (expr[i] != '\0')
		return (expr + i);
	i = -1;
	while (expr[++i] != '\0' && ((expr[i] != '/' && expr[i] != '*' &&
			expr[i] != '%') || count > 0))
	{
		if (expr[i] == '(')
			count++;
		else if (expr[i] == ')')
			count--;
	}
	return ((expr[i] != '\0') ? expr + i : NULL);
}

int		ft_is_big_parenthesis(char *expr, int start, int end)
{
	int	big_parenthesis;
	int l;

	big_parenthesis = 0;
	if (expr[start] == '(')
	{
		l = 0;
		while (expr[++l + start] != '\0')
		{
			if (expr[start + l] == '(')
				big_parenthesis--;
			else if (expr[start + l] == ')')
				big_parenthesis++;
			if (big_parenthesis > 0 && start + l != end)
			{
				big_parenthesis = 0;
				break ;
			}
		}
	}
	return (big_parenthesis);
}

char	*ft_cut_parenthesis(char *expr)
{
	int	start;
	int	end;
	int	l;

	start = 0;
	while (expr[start] == ' ')
		start++;
	l = ft_strlen(expr);
	end = l - 1;
	while (expr[end] == ' ')
		end--;
	if (ft_is_big_parenthesis(expr, start, end) == 1)
		return (ft_strncpy(expr + start + 1, end - start - 1));
	else
		return (ft_strncpy(expr + start, end + 1 - start));
}

int		compute_expr(char *str, char *op)
{
	int i;
	int	length;

	i = 0;
	while (g_opptab[i].op[0] != op[0])
		i++;
	length = op - str;
	return (g_opptab[i].f(eval_expr(ft_strncpy(str, length)),
				eval_expr(op + 1)));
}

int		eval_expr(char *str)
{
	char *expr;
	char *op;

	expr = ft_cut_parenthesis(str);
	op = ft_first_lowest_op(expr);
	if (op == NULL)
		return (ft_atoi(expr));
	else
		return (compute_expr(expr, op));
}
