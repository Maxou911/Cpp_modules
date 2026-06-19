# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/26 18:04:32 by maalwis           #+#    #+#              #
#    Updated: 2025/11/21 17:04:21 by maalwis          ###   ########.fr        #
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
