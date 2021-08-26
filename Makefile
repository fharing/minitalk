# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fharing <fharing@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 11:38:18 by fharing           #+#    #+#              #
#    Updated: 2021/08/24 16:34:57 by fharing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar cr
NAME_CL = client
NAME = server
SOURCES_SRV = ./src/server.c ./src/ft_putnbr_fd.c
SOURCES_CL = ./src/client.c ./src/ft_atoi.c ./src/ft_isspace.c ./src/ft_isdigit.c ./src/ft_itoa.c ./src/ft_strlen.c
OBJECTS_SRV = $(SOURCES_SRV:.c=.o)
OBJECTS_CL = $(SOURCES_CL:.c=.o)

#build everything
all: $(NAME)

#compile all files
$(NAME): $(OBJECTS_SRV) $(OBJECTS_CL)
	$(CC) $(CFLAGS) $(OBJECTS_SRV) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJECTS_CL) -o $(NAME_CL)

#removes all *.o files
clean:
	$(RM) $(OBJECTS_SRV) $(OBJECTS_CL)

#removes all *.o files + libft.a + libmlx.a
fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_CL)

#removes all *.o files + libft.a + libmlx.a and rebuild everything
re: fclean all
