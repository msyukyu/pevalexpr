# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/25 13:10:56 by dabeloos          #+#    #+#              #
#    Updated: 2018/08/26 14:53:07 by dabeloos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= eval_expr

C_FILES		= main.c ft_opp.c ft_string_conversion.c eval_expr.c

FLAGS		= -Wall -Wextra -Werror

$(NAME):
			gcc -o $(NAME) $(FLAGS) $(C_FILES)

all:		$(NAME)

clean:
			rm -f $(NAME)

fclean:		clean

re:			fclean all
