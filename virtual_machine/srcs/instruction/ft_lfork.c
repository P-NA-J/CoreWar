/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:35:18 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/07 12:41:16 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../includes/debug.h"
#include "../../../libft/includes/prototypes.h"

static void	ft_verbose(t_process *process, uint32_t param)
{
	ft_printf("P%5d | %s ", process->no, g_tab_instruction[process->opcode].name);
	ft_printf("%hd\n", param);
}

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
	new_process->opcode = vm->vm[new_process->pc];
	ft_processus_tab_add(new_process, vm, (vm->cycle + g_tab_instruction[new_process->opcode].cycle_to_exec) % 1000);
	ft_processus_list_add(vm, new_process);
	ft_verbose(process, vm->param[0][0]);
	ft_skip_instruction_sequency(process, vm);
}
