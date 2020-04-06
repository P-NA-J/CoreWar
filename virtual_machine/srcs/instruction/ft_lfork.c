/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:35:18 by pauljull          #+#    #+#             */
/*   Updated: 2020/04/03 14:08:23 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../includes/debug.h"
#include "../../../libft/includes/prototypes.h"
/*
static void	ft_verbose(t_process *process, uint32_t param)
{
	ft_printf("P%4d | %s ", process->no, g_tab_instruction[process->opcode].name);
	ft_printf("%hd\n", param);
}
*/
void	ft_lfork(t_process *process, t_vm *vm)
{
	t_process	*new_process;
	short		param;
	size_t		no;
	size_t		pc;

	param = vm->param[0][0];
	no = vm->nb_process + 1;
	pc = (process->pc + param) % MEM_SIZE;
	if (!(new_process = ft_processus_cpy(process, param, no)))
		exit(0);
/*	new_process->opcode = vm->vm[new_process->pc];
	ft_add_process(vm->tab + g_tab_instruction[new_process->opcode].cycle_to_exec, new_process);
	ft_add_process_list(vm, new_process);
	ft_verbose(process, vm->param[0][0]);
	ft_skip_instruction_sequency(process, vm);
*/}
