# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 16:37:27 by mait-aad          #+#    #+#              #
#    Updated: 2022/03/24 18:34:08 by mait-aad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES=server
NAMEC=client
FLAGS2= -Wall -Wextra -Werror
RM=rm -f
SRCC = client.c\
	ft_atoi.c\
	ft_putnbr_fd.c
SRCS =  server.c ft_atoi.c ft_putnbr_fd.c
	
all : $(NAMEC) $(NAMES)
$(NAMEC):
		$(CC) $(FLAGS2) $(SRCC) -o $(NAMEC)
$(NAMES):
		$(CC) $(FLAGS2) $(SRCS) -o $(NAMES)


fclean: clean
		rm -f $(NAMES) $(NAMEC)

clean:
		rm -f *.o

re: fclean all
.PHONY: fclean clean re all