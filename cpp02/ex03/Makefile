# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 13:20:49 by maalwis           #+#    #+#              #
#    Updated: 2025/10/24 14:11:44 by maalwis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Point
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ_DIR = Object_files

SRC = \
	main.cpp \
	Fixed.cpp \
	Max_And_Min.cpp \
	Operateur_Arithmetiques.cpp \
	Operateur_Compare.cpp \
	Operateur_Incr_Decr.cpp \
	Point.cpp \
	bsp.cpp \

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
