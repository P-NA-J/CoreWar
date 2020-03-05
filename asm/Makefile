# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboitier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 18:42:15 by aboitier          #+#    #+#              #
#    Updated: 2020/03/04 22:22:39 by aboitier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				= gcc
NAME 			= asm
CFLAG 			= -Wall -Wextra -Werror 
#LIB			= libft/libft.a

SRC				= op.c  					\
				  main.c						\
				


OBJ 			= $(SRC:.c=.o)
PATH_SRC		= $(addprefix src/, $(SRC))
PATH_OBJ		= $(addprefix obj/, $(OBJ))

all: $(NAME) #libft_comp

libft_comp:
	@make -C libft

$(NAME)	: $(PATH_OBJ) 							#(libft_comp)
	@$(CC) $(CFLAG) -o $(NAME) $(PATH_OBJ) 		#$(LIB)
	@echo "asm has been created"

$(addprefix obj/, %.o): $(addprefix src/, %.c)
	@$(CC) $(CFLAG) -c $< -o $@

clean : #lib_clean
	@rm -f $(PATH_OBJ)

fclean : clean #lib_fclean
	@rm -f $(EXE)

re: fclean all

run: re 
	@./$(NAME) tetet.s


.PHONY: clean fclean re 
