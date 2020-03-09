/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:09:20 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/08 18:18:51 by pauljull         ###   ########.fr       */
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

	process->opcode = vm->vm[process->pc];
	cycle_to_add = tab_instruction[vm->vm[process->pc]].cycle_to_exec;
	process->cycle_left = cycle_to_add;
	tab[(cycle + cycle_to_add) % 1024] = ft_process_move(process, tab, cycle, cycle_to_add);
	ft_debug_processus_list(tab[cycle]);
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	ft_debug_processus_list(tab[cycle + cycle_to_add]);
}

void	ft_check_loading_processus(t_vm *vm, t_process *process, t_process *tab[1024], size_t cycle)
{
	printf("[[ LOADING CHECKING ... ]]\n");
	if (vm->vm[process->pc] >= 16)
	{
		printf("[[ MOVING PC ]]\n");
		ft_move_pc(process, 1);
	}
	else
	{
		printf("[[ LOADING IN PROGRESS ... ]]\n");
		ft_loading_processus(vm, process, tab, cycle);
	}
}

void	ft_check_loading_tab_processus(t_process *process_list, t_vm *vm, t_process *tab[1024], size_t cycle)
{
	printf("cycle = [[ %zu ]]\n", cycle);
	while (process_list != NULL)
	{
		printf("Processus { %p }\n", process_list);
		if (process_list->cycle_left == 0)
			ft_check_loading_processus(vm, process_list, tab, cycle);
		process_list = process_list->next;
	}
	printf("\n");
}