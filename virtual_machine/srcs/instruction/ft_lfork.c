/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:35:18 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/26 13:57:28 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

void	ft_lfork(t_process *process, t_vm *vm)
{
	t_process	*new_process;
	short		param;

	param = vm->param[0][0];
	if (!(new_process = ft_cpy_processus(process)))
		exit(0);
	new_process->pc = param;
	new_process->opcode = vm->vm[new_process->pc];
	ft_add_process(vm->tab + g_tab_instruction[new_process->opcode].cycle_to_exec, new_process);
	ft_add_process_list(vm, new_process);
}
