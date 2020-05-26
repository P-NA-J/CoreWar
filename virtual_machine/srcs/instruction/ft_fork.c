/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:34:37 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/25 20:34:32 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../../libft/includes/prototypes.h"
#include "../../includes/debug.h"

static void	ft_verbose(t_process *process, uint32_t param, size_t pc)
{
	ft_printf("P%5zu | %s ", process->no, g_tab_instruction[process->opcode].name);
	ft_printf("%hd (%zu)\n", param, pc);
//	ft_printf("%hd (%zu) carry = %d\n", param, pc, process->carry);
}

void	ft_fork(t_process *process, t_vm *vm)
{
	t_process	*new_process;
	short		param;
	size_t		pc;
	size_t		no;

	param = vm->param[0][0];
	pc = (process->pc + (param % IDX_MOD)) % MEM_SIZE;
	no = vm->last_process + 1;
	vm->last_process += 1;
	if (!(new_process = ft_processus_cpy(process, pc, no)))
		exit(0);
	ft_verbose(process, vm->param[0][0], new_process->pc);
	if (vm->vm[new_process->pc % MEM_SIZE] == 0 || vm->vm[new_process->pc % MEM_SIZE] > 16)
	{
		new_process->opcode = 100;
		ft_processus_tab_add(new_process, vm, (vm->cycle + 1) % 1024);
		new_process->pc += 1;
	}
	else
	{
		new_process->opcode = vm->vm[new_process->pc] - 1;
		ft_processus_tab_add(new_process, vm, (vm->cycle + g_tab_instruction[new_process->opcode].cycle_to_exec) % 1024);
	}
	new_process->cycle_last_live = vm->cycle;
	ft_processus_list_add(vm, new_process);
	ft_skip_instruction_sequency(process, vm);
}
