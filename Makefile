# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 20:28:41 by arlarzil          #+#    #+#              #
#    Updated: 2023/12/12 21:53:44 by arlarzil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_COMMON_DIR 		=	common/
SRC_CHECKER_DIR		=	checker_src/
SRC_PUSHSWAP_DIR	=	pushswap/

SRC_COMMON 		=	check_dubs		\
					check_number	\
					free_and_exit	\
					ft_atoi			\
					init			\
					push			\
					rotate			\
					rrotate			\
					swap			\
					utils			\
					is_sorted		\
					ft_split		\
					ft_strdup		\
					parse			\

SRC_CHECKER		=	get_next_line	\
					ft_strcmp		\
					main			\

SRC_PUSHSWAP 	=	main			\
					sort			\
					first_phase		\
					first_phase_bis	\
					second_phase	\
					utils			\
					debug			\

SRC_TO_FILENAME_COMMON		= $(addsuffix .c, $(addprefix $(SRC_COMMON_DIR), $(SRC_COMMON)))
SRC_TO_FILENAME_CHECKER		= $(addsuffix .c, $(addprefix $(SRC_CHECKER_DIR), $(SRC_CHECKER)))
SRC_TO_FILENAME_PUSHSWAP	= $(addsuffix .c, $(addprefix $(SRC_PUSHSWAP_DIR), $(SRC_PUSHSWAP)))

OBJ_COMMON		=	$(SRC_TO_FILENAME_COMMON:.c=.o)
OBJ_CHECKER		=	$(SRC_TO_FILENAME_CHECKER:.c=.o)
OBJ_PUSHSWAP	=	$(SRC_TO_FILENAME_PUSHSWAP:.c=.o)

OBJ				=	$(OBJ_PUSHSWAP) $(OBJ_COMMON) $(OBJ_CHECKER)
OBJ_BONUS		=	$(OBJ_COMMON) $(OBJ_CHECKER)
OBJ_MAIN		=	$(OBJ_COMMON) $(OBJ_PUSHSWAP)

NAME 	= push_swap

BONUS_NAME	= checker

CC 	= cc

CFLAGS 	= -Wall -Wextra -Werror -Icommon -g3

all: $(NAME)
bonus:	$(BONUS_NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ_COMMON) $(OBJ_PUSHSWAP)
	$(CC) -o $(NAME) $(OBJ_MAIN) $(CFLAGS)

$(BONUS_NAME): $(OBJ_COMMON) $(OBJ_CHECKER)
	$(CC) -o $(BONUS_NAME) $(OBJ_BONUS) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

auteur:
	echo $(USER) > auteur

.PHONY: fclean all re clean
