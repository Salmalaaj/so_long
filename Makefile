# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 08:03:26 by slaajour          #+#    #+#              #
#    Updated: 2022/07/02 19:11:10 by slaajour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = so_long.c so_long_utils.c checkin_map.c get_next_line.c ft_split.c animation.c moves.c moves_again.c ft_itoa.c

FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit 
OBJS	= 	$(SRCS:.c=.o)

DEBUG = -fsanitize=address -g

NAME	= 	so_long
RM		= 	@rm -f

all:	$(NAME)

$(NAME):
	@cc $(FLAGS) $(SRCS) -o $(NAME)

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all