CC := clang

CFLAGS := -Wall -Wextra -Werror

LIB := libft/libftprintf.a

PATH_LIB = libft/

PATH_VM = virtual_machine/
PATH_ASM = asm_dir/

NAME_VM := corewar

SRC_VM = ft_place_player.c
SRC_VM += main.c
SRC_VM += ft_print_intro.c
SRC_VM += ft_free.c
SRC_VM += ft_option.c
SRC_VM += ft_dump.c
SRC_VM += ft_error.c
SRC_VM += ft_execution.c
SRC_VM += ft_loading.c
SRC_VM += ft_parameter.c
SRC_VM += ft_parameter_check.c
SRC_VM += ft_processus_add.c
SRC_VM += ft_processus_creation.c
SRC_VM += ft_processus_delete.c
SRC_VM += ft_processus_move.c
SRC_VM += ft_processus_player_initialisation.c
SRC_VM += ft_check.c
SRC_VM += ft_tab_instruction.c
SRC_VM += ft_parsing.c
SRC_VM += ft_insertion_vm.c
SRC_VM += ft_core_loop.c
SRC_VM += ft_initialisation.c
SRC_VM += ft_recover_value.c
SRC_VM += ft_skip.c
SRC_VM += ft_conversion.c
SRC_VM += instruction/ft_convert.c
SRC_VM += instruction/ft_add.c
SRC_VM += instruction/ft_aff.c
SRC_VM += instruction/ft_and.c
SRC_VM += instruction/ft_fork.c
SRC_VM += instruction/ft_ld.c
SRC_VM += instruction/ft_ldi.c
SRC_VM += instruction/ft_lfork.c
SRC_VM += instruction/ft_live.c
SRC_VM += instruction/ft_lld.c
SRC_VM += instruction/ft_lldi.c
SRC_VM += instruction/ft_or.c
SRC_VM += instruction/ft_st.c
SRC_VM += instruction/ft_sti.c
SRC_VM += instruction/ft_sub.c
SRC_VM += instruction/ft_xor.c
SRC_VM += instruction/ft_zjmp.c
SRC_VM += instruction/ft_utils.c

OBJ_VM = $(SRC_VM:.c=.o)
PATH_SRC_VM = $(addprefix virtual_machine/srcs/, $(SRC_VM))
PATH_OBJ_VM = $(addprefix virtual_machine/obj/, $(OBJ_VM))

all: libft_comp obj_dir_vm $(NAME_VM)
	make -C asm_dir install
	make -C asm_dir
	mv asm_dir/asm .

$(NAME_VM) : $(PATH_OBJ_VM)
	$(CC) $(CFLAGS) -o $(NAME_VM) $(PATH_OBJ_VM) $(LIB)

libft_comp:
	make -C $(PATH_LIB)

obj_dir_vm:
	if ! [ -d "virtual_machine/obj/" ]; then mkdir virtual_machine/obj ; fi
	if ! [ -d "virtual_machine/obj/instruction" ]; then mkdir virtual_machine/obj/instruction ; fi

$(addprefix virtual_machine/obj/, %.o): $(addprefix virtual_machine/srcs/, %.c)
	$(CC) $(CFLAGS) -c $< -o $@

clean_asm :
	make -C asm_dir clean
	echo "asm OBJ have been deleted"

clean_vm :
	rm -rf $(PATH_OBJ_VM)

fclean_asm :
	make -C asm_dir fclean

fclean_vm : clean_vm
	rm -f $(NAME_VM)

lib_clean:
	make clean -C $(PATH_LIB)
	make -C asm_dir/jlib clean

lib_fclean:
	make fclean -C $(PATH_LIB)
	make -C asm_dir/jlib fclean

clean: clean_vm clean_asm lib_clean

fclean: lib_fclean fclean_vm fclean_asm

re_asm :
	make -C asm_dir re_install
	make -C asm_dir re

re_vm : fclean_vm lib_fclean all

re: fclean all

.PHONY : re re_vm re_asm fclean clean lib_fclean lib_clean fclean_vm fclean_asm clean_vm clean_asm obj_dir_vm obj_dir_asm libft_comp
