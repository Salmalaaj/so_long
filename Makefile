# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 08:03:26 by slaajour          #+#    #+#              #
#    Updated: 2022/07/05 05:02:56 by slaajour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = so_long.c so_long_utils.c checkin_map.c get_next_line.c ft_split.c animation.c moves.c moves_again.c ft_itoa.c init_protection.c init_protection2.c display_image.c

SRCS_BONUS = ft_itoa.c animation.c so_long.c so_long_utils.c checkin_map.c get_next_line.c ft_split.c moves.c moves_again.c init_protection.c init_protection2.c display_image_bonus.c

FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit 
OBJS	= 	$(SRCS:.c=.o)

DEBUG = -fsanitize=address -g

NAME	= 	so_long
RM		= 	@rm -f

all:	$(NAME)

$(NAME):
	@cc $(FLAGS) $(SRCS) -o $(NAME) $(DEBUG)

bonus:
	@cc $(FLAGS) $(SRCS_BONUS) -o $(NAME) $(DEBUG)

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all