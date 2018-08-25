# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/25 13:10:56 by dabeloos          #+#    #+#              #
#    Updated: 2018/08/25 13:21:23 by dabeloos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= eval_expr

C_FILES		= ft_opp.c ft_string_conversion.c eval_expr.c

O_FILES		= ft_opp.o ft_string_conversion.o eval_expr.o

$(NAME):
			gcc -o $(NAME) -Wall -Wextra -Werror $(C_FILES)

all:		$(NAME)

clean:
			rm -f $(O_FILES)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
