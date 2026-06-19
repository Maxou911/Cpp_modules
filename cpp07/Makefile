# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 12:19:39 by maalwis           #+#    #+#              #
#    Updated: 2026/01/16 12:19:42 by maalwis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile à la racine

DIRS = ex00 ex01 ex02

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
