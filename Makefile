CC := clang

CFLAGS := -Wall -Wextra -Werror

LIB := libft/libftprintf.a

PATH_LIB = libft/

PATH_VM = virtual_machine/
PATH_ASM = asm_dir/

NAME_ASM := asm
NAME_VM := corewar

SRC_ASM =	args.c
SRC_ASM += assemble.c
SRC_ASM += check_inst.c
SRC_ASM += check_param.c
SRC_ASM += disass.c
SRC_ASM += disass_lst_file.c
SRC_ASM += disass_utils.c
SRC_ASM += dump.c
SRC_ASM += error_args.c
SRC_ASM += error_cmd_format.c
SRC_ASM += error_cmd_global.c
SRC_ASM += error_global.c
SRC_ASM += error_inst.c
SRC_ASM += error_label.c
SRC_ASM += free.c
SRC_ASM += header.c
SRC_ASM += label.c
SRC_ASM += label_call.c
SRC_ASM += line.c
SRC_ASM += main.c
SRC_ASM += op.c
SRC_ASM += options.c
SRC_ASM += param.c
SRC_ASM += parse_disass.c
SRC_ASM += parse_inst.c
SRC_ASM += utils.c
SRC_ASM += utils_2.c
SRC_ASM += utils_error.c
SRC_ASM += print/buff.c
SRC_ASM += print/colors.c
SRC_ASM += print/conv_cs.c
SRC_ASM += print/conv_di.c
SRC_ASM += print/conv_f.c
SRC_ASM += print/conv_lcls.c
SRC_ASM += print/conv_oux.c
SRC_ASM += print/conv_p.c
SRC_ASM += print/flags.c
SRC_ASM += print/ft_dprintf.c
SRC_ASM += print/ft_memdup.c
SRC_ASM += print/ft_memjoin.c
SRC_ASM += print/ft_printf.c
SRC_ASM += print/ftoa_binary.c
SRC_ASM += print/ftoa_bint.c
SRC_ASM += print/ftoa_calc.c
SRC_ASM += print/ftoa_list.c
SRC_ASM += print/get_next_line.c
SRC_ASM += print/utils.c

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

OBJ_ASM = $(SRC_ASM:.c=.o)
PATH_SRC_ASM = $(addprefix asm_dir/srcs/, $(SRC_ASM))
PATH_OBJ_ASM = $(addprefix asm_dir/obj/, $(OBJ_ASM))

OBJ_VM = $(SRC_VM:.c=.o)
PATH_SRC_VM = $(addprefix virtual_machine/srcs/, $(SRC_VM))
PATH_OBJ_VM = $(addprefix virtual_machine/obj/, $(OBJ_VM))

all: libft_comp obj_dir_vm obj_dir_asm $(NAME_VM) $(NAME_ASM)

$(NAME_VM) : $(PATH_OBJ_VM)
	$(CC) $(CFLAGS) -o $(NAME_VM) $(PATH_OBJ_VM) $(LIB)

$(NAME_ASM): $(PATH_OBJ_ASM)
	$(CC) $(CFLAGS) -o $(NAME_ASM) $(PATH_OBJ_ASM) $(LIB)
	echo "asm has been created"

libft_comp:
	make -C $(PATH_LIB)

obj_dir_asm:
	if ! [ -d "asm_dir/obj/" ]; then mkdir asm_dir/obj ; fi
	if ! [ -d "asm_dir/obj/print/" ]; then mkdir asm_dir/obj/print ; fi

obj_dir_vm:
	if ! [ -d "virtual_machine/obj/" ]; then mkdir virtual_machine/obj ; fi
	if ! [ -d "virtual_machine/obj/instruction" ]; then mkdir virtual_machine/obj/instruction ; fi

$(addprefix asm_dir/obj/, %.o): $(addprefix asm_dir/srcs/, %.c)
	$(CC) $(CFLAGS) -c $< -o $@

$(addprefix virtual_machine/obj/, %.o): $(addprefix virtual_machine/srcs/, %.c)
	$(CC) $(CFLAGS) -c $< -o $@

clean_asm :
	rm -f $(PATH_OBJ_ASM)
	echo "asm OBJ have been deleted"

clean_vm :
	rm -rf $(PATH_OBJ_VM)

fclean_asm : clean_asm
	rm -f $(NAME_ASM)

fclean_vm : clean_vm
	rm -f $(NAME_VM)

lib_clean:
	make clean -C $(PATH_LIB)

lib_fclean:
	make fclean -C $(PATH_LIB)

clean: clean_vm clean_asm lib_clean

fclean: lib_fclean fclean_vm fclean_asm

re_asm : fclean_asm lib_fclean all

re_vm : fclean_vm lib_fclean all

re: fclean all

.PHONY : re re_vm re_asm fclean clean lib_fclean lib_clean fclean_vm fclean_asm clean_vm clean_asm obj_dir_vm obj_dir_asm libft_comp
