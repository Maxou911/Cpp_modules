# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 13:42:56 by maalwis           #+#    #+#              #
#    Updated: 2026/01/12 18:02:56 by maalwis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AForm
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ_DIR = Object_files

SRC =	Sources/Bureaucrat.cpp \
		Sources/main.cpp \
		Sources/AForm.cpp \
		Sources/PresidentialPardonForm.cpp \
		Sources/RobotomyRequestForm.cpp \
		Sources/ShrubberyCreationForm.cpp \

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f *_shrubbery
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re