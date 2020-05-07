/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:09:20 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/07 08:56:54 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/tab.h"
#include "../includes/prototypes.h"
#include "../includes/debug.h"
#include "../../libft/includes/prototypes.h"
#include <stdbool.h>

void	ft_loading_processus(t_vm *vm, t_process *process, size_t cycle)
{
	int	cycle_to_add;

	process->opcode = vm->vm[process->pc % MEM_SIZE] - 1;
	cycle_to_add = g_tab_instruction[process->opcode].cycle_to_exec;
	ft_process_move(process, vm, cycle % 1000, (cycle + cycle_to_add) % 1000);
}

void	ft_loading_try_processus(t_vm *vm, t_process *process, size_t cycle)
{
	if (vm->vm[process->pc % MEM_SIZE] == 0 || vm->vm[process->pc % MEM_SIZE] > 16)
	{
		ft_move_pc(process, 1);
		if (process->tab_places != STAND_BY)
			ft_process_move(process, vm, cycle % 1000, STAND_BY);
	}
	else
		ft_loading_processus(vm, process, cycle);
}

void	ft_loading_standby_processus(t_vm *vm, t_process *process, size_t cycle)
{
	int	dest;

	process->opcode = vm->vm[process->pc % MEM_SIZE] - 1;
	dest = cycle + g_tab_instruction[process->opcode].cycle_to_exec;
	ft_process_move(process, vm, STAND_BY, dest % 1000);
}

int	ft_loading_try_standby_processus(t_vm *vm, t_process *process, size_t cycle)
{
	if (vm->vm[process->pc % MEM_SIZE] == 0 || vm->vm[process->pc % MEM_SIZE] > 16)
	{
		ft_move_pc(process, 1);
		return (true);
	}
	else
		ft_loading_standby_processus(vm, process, cycle);
	return (false);
}

void	ft_loading_check_processus(t_vm *vm, size_t cycle)
{
	t_process *head;

	head = vm->tab[STAND_BY];
	while (vm->tab[STAND_BY] != NULL)
	{
		if (ft_loading_try_standby_processus(vm, vm->tab[STAND_BY], cycle) == true)
			vm->tab[STAND_BY] = vm->tab[STAND_BY]->next;
		else if (head->tab_places != STAND_BY)
			head = vm->tab[STAND_BY];
	}
	vm->tab[STAND_BY] = head;
}
