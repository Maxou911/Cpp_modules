# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 13:35:51 by maalwis           #+#    #+#              #
#    Updated: 2025/12/17 13:35:52 by maalwis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Makefile à la racine

DIRS = ex00 ex01 ex02 ex03

all:
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir clean; \
	done

fclean:
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir fclean; \
	done

re:
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir re; \
	done
