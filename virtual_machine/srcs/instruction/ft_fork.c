/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:34:37 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/23 16:45:19 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

void	ft_fork(t_process *process, t_vm *vm)
{
	t_process	*new_process;

	if (!(new_process = ft_cpy_processus(process)))
		exit(0);
	new_process->pc = process->pc + (vm->param[0][0] % IDX_MOD);
	new_process->opcode = vm->vm[new_process->pc];
	ft_add_process(vm->tab + g_tab_instruction[new_process->opcode].cycle_to_exec, new_process);
	ft_add_process_list(vm, new_process);
}
