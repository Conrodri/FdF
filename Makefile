# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/05/27 20:28:55 by vicaster     #+#   ##    ##    #+#        #
#    Updated: 2019/06/07 17:59:11 by vicaster    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#	Rappel des variables automatiques:
#	$@ : produit (ou but) de la règle
#	$< : nom de la première dépendance (ou source)
#	$? : toutes les dépendances plus récentes que le but
#	$^ : toutes les dépendances
#	$+ : idem mais chaque dépendance apparait autant de fois qu'elle est cité
#	et l'ordre d'apparition est conservé.

##############################################################################
##								COULEURS									##
##############################################################################

DEFAULT =\033[0m
HIGHLIGHT =\033[1m
UNDERLINE =\033[4m
BLINK =\033[5m
BLACK =\033[30m
RED =\033[31m
GREEN =\033[32m
YELLOW =\033[33m
BLUE =\033[34m
PURPLE =\033[35m
CYAN =\033[36m
WHITE =\033[37m

##############################################################################
##								MAKEFILE									##
##############################################################################

INC = /usr/X11/include
HT = x86_64
DOCP = do_cp

NAME = fdf
CC = gcc
FLAG1 = -Wall -Wextra -Werror
FLAG2 = -fsanitize=address -g
CFLAGS = -I $(INC) -O3 -I minilibx
MINIFLAG = -lmlx -framework OpenGL -framework AppKit
INCLIB = $(INC)/../lib
LIBFT = ./libft/libft.a
LFTDIR = libft
RM = /bin/rm

SRC = srcs/main.c srcs/tools.c srcs/map.c srcs/bresenham.c srcs/parallele.c srcs/ft_key.c

OBJ = $(SRC:.c=.o)


all : LFTC $(NAME)

LFTC:
	@$(MAKE) -C $(LFTDIR)

$(NAME) : $(OBJ) srcs/fdf.h $(LIBFT) Makefile
	@$(CC) $(FLAG1) -o $(NAME) -I minilibx -L minilibx $(SRC) $(MINIFLAG) $(LIBFT)
	@echo "${DEFAULT}\n${PURPLE} ----------------------\n|->   ${GREEN}$(NAME) compiled ${PURPLE}    |\n ----------------------${DEFAULT}"

clean :
	@$(MAKE) -C $(LFTDIR) $@
	@$(RM) -rf $(OBJ)
	@echo "${PURPLE}|-> ${RED}objects removed${DEFAULT}"

fclean: clean
	@$(MAKE) -C $(LFTDIR) $@
	@$(RM) -f $(NAME)
	@echo "${PURPLE}|-> ${RED}$(NAME) deleted${DEFAULT}"

re : fclean all

rc: re
	@make clean

libft:
	@cd $(LFTDIR) && make rc

.SILENT: $(OBJ)
.PHONY: all clean fclean re rc libft
