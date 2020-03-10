EXE = corewar
CC = clang 
CFLAG = -Wall -Werror -Wextra
LIB = libft/libft.a

SRC =	test.c
SRC +=	ft_dump.c
SRC +=	ft_error.c
SRC +=	ft_execution.c
SRC +=	ft_instruction.c
SRC +=	ft_loading.c
SRC +=	ft_parameter.c
SRC +=	ft_processus_management.c
SRC +=	ft_virtual_machine.c
SRC +=	ft_debug.c
SRC +=	op.c

OBJ = $(SRC:.c=.o)
PATH_SRC = $(addprefix srcs/, $(SRC))
PATH_OBJ = $(addprefix obj/, $(OBJ))
PATH_HEADERS = $(addprefix includes/, $(HEADERS))

all: $(EXE)

obj_dir:
	@if ! [ -d "obj/" ]; then mkdir obj ; fi

$(EXE) : obj_dir $(PATH_OBJ)
	@$(CC) $(CFLAG) -o $(EXE) $(PATH_OBJ)

$(addprefix obj/, %.o): $(addprefix srcs/, %.c)
	@$(CC) $(CFLAG) -c $< -o $@

#lib_clean:
#	@make clean -C libft/

#lib_fclean:
#	@make fclean -C libft/

clean:
	@rm -f $(PATH_OBJ)

fclean: clean
	@rm -f $(EXE)

re: fclean all

.PHONY : libft clean fclean re comp lib_clean lib_fclean