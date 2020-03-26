/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:09:20 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 20:06:34 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/tab.h"
#include "../includes/prototypes.h"
#include "../includes/debug.h"

void	ft_reset_begin_process_list(t_process *process_list)
{
	t_process	*tmp;

	tmp = process_list;
	while (process_list)
	{
		process_list->begin = tmp;
		process_list = process_list->next;
	}
}

void	ft_loading_processus(t_vm *vm, t_process *process, t_process *tab[1024], size_t cycle)
{
	int	cycle_to_add;

	process->opcode = vm->vm[process->pc] - 1;
	cycle_to_add = g_tab_instruction[process->opcode].cycle_to_exec;
	tab[(cycle + cycle_to_add) % 1024] = ft_process_move(process, tab, cycle, cycle_to_add);
}

void	ft_check_loading_processus(t_vm *vm, t_process *process, t_process *tab[1024], size_t cycle)
{
	if (vm->vm[process->pc % MEM_SIZE] == 0 || vm->vm[process->pc % MEM_SIZE] > 16)
	{
		ft_move_pc(process, 1);
		tab[1010] = ft_process_move(process, tab, cycle, 1010 - cycle);
	}
	else
		ft_loading_processus(vm, process, tab, cycle);
}
