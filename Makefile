CC := clang

CFLAGS := -Wall -Wextra -Werror -g3 -fsanitize=address,undefined

LIB := libft/libftprintf.a

PATH_LIB = libft/

NAME_ASM := asm

SRC_ASM := op.c init.c \
		   buffer_management.c \
		   scan.c main.c

OBJ_ASM = $(ASMSRC:.c=.o)
PATH_SRC_ASM = $(addprefix asm/src/, $(SRC))
PATH_OBJ_ASM = $(addprefix asm/obj/, $(OBJ))

NAME := corewar

SRC = main.c
SRC += ft_place_player.c
SRC += ft_print_intro.c
SRC += ft_free.c
SRC += ft_option.c
SRC += ft_dump.c
SRC += ft_error.c
SRC += ft_execution.c
SRC += ft_loading.c
SRC += ft_parameter.c
SRC += ft_parameter_check.c
SRC += ft_processus_add.c
SRC += ft_processus_creation.c
SRC += ft_processus_delete.c
SRC += ft_processus_move.c
SRC += ft_processus_player_initialisation.c
SRC += ft_check.c
SRC += ft_tab_instruction.c
SRC += ft_parsing.c
SRC += ft_insertion_vm.c
SRC += ft_core_loop.c
SRC += ft_initialisation.c
SRC += ft_recover_value.c
SRC += ft_skip.c
SRC += ft_conversion.c
SRC += instruction/ft_add.c
SRC += instruction/ft_aff.c
SRC += instruction/ft_and.c
SRC += instruction/ft_fork.c
SRC += instruction/ft_ld.c
SRC += instruction/ft_ldi.c
SRC += instruction/ft_lfork.c
SRC += instruction/ft_live.c
SRC += instruction/ft_lld.c
SRC += instruction/ft_lldi.c
SRC += instruction/ft_or.c
SRC += instruction/ft_st.c
SRC += instruction/ft_sti.c
SRC += instruction/ft_sub.c
SRC +=instruction/ft_xor.c
SRC +=instruction/ft_zjmp.c
SRC +=instruction/ft_utils.c

OBJ = $(SRC:.c=.o)
PATH_SRC = $(addprefix virtual_machine/srcs/, $(SRC))
PATH_OBJ = $(addprefix virtual_machine/obj/, $(OBJ))

all: $(NAME) $(NAME_ASM) libft_comp

libft_comp:
	@make -C $(PATH_LIB)

obj_dir_asm:
	if ! [ -d "asm/obj/" ]; then mkdir asm/obj ; fi

$(NAME_ASM):  libft_comp obj_dir_asm $(PATH_OBJ_ASM)
	@$(CC) $(CFLAGS) -o $(NAME_ASM) $(PATH_OBJ_ASM) $(LIB)
	@echo "asm has been created"

$(addprefix asm/obj/, %.o): $(addprefix asm/src/, %.c)
	@$(CC) $(CFLAGS) -c $< -o $@

clean_asm : lib_clean
	@rm -f $(PATH_OBJ_ASM)
	@echo "asm OBJ have been deleted"

fclean_asm : clean_asm
	@rm -f $(NAME_ASM)

re_asm : fclean_asm all

obj_dir:
	if ! [ -d "virtual_machine/obj/" ]; then mkdir virtual_machine/obj ; fi
	if ! [ -d "virtual_machine/obj/instruction" ]; then mkdir virtual_machine/obj/instruction ; fi

$(NAME) : libft_comp obj_dir $(PATH_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(PATH_OBJ) $(LIB)

$(addprefix virtual_machine/obj/, %.o): $(addprefix virtual_machine/srcs/, %.c)
	$(CC) $(CFLAGS) -c $< -o $@

clean_vm : lib_clean
	rm -rf $(PATH_OBJ)

fclean_vm : clean lib_fclean
	rm -f $(NAME)

lib_clean:
	@make clean -C $(PATH_LIB)

lib_fclean:
	@make fclean -C $(PATH_LIB)

clean: clean_vm clean_asm lib_clean

fclean: lib_fclean fclean_vm fclean_asm

.PHONY : libft clean fclean re comp lib_clean lib_fclean
