/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processus_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 10:02:38 by paul              #+#    #+#             */
/*   Updated: 2020/04/03 14:49:24 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/prototypes.h"
#include "../includes/tab.h"
#include <stdlib.h>

/*
void	ft_processus_tab_front_add(t_process **tab, t_process *process, int cycle_dest)
{
	process->next = tab[cycle_dest];
	tab[cycle_dest] = process;
}

void	ft_processus_tab_core_add(t_process *process, t_process *tmp)
{
	while (tmp->next && (tmp->next->no > process->no))
		tmp = tmp->next;
	process->next = tmp->next;
	tmp->next = process;
}

void	ft_processus_tab_add(t_process *process, t_process *tab[1024], t_vm *vm)
{
	if (tab[vm->cycle % 1000] == NULL || (tab[vm->cycle % 1000]->no < process->no))
		ft_processus_tab_front_add(tab, process, vm->cycle + g_tab_instruction[process->opcode].cycle_to_exec);
	else
		ft_processus_tab_core_add(process, tab[vm->cycle % 1000]);
}
*/
void	ft_processus_list_add(t_vm *vm, t_process *process)
{
	size_t	i;

	vm->nb_process += 1;
	if (vm->nb_process > vm->nb_max_process)
		vm->process_list = realloc(vm->process_list, vm->nb_max_process * 2);
	i = 0;
	while (vm->process_list[i] != NULL)
		i += 1;
	vm->process_list[i] = process;
}

t_process	*ft_processus_tab_front_add(t_process *tab, t_process *process)
{
	process->next = tab;
	return (process);
}

void	ft_processus_tab_core_add(t_process *process, t_process *tmp)
{
	while (tmp->next && (tmp->next->no > process->no))
		tmp = tmp->next;
	process->next = tmp->next;
	tmp->next = process;
}

void	ft_processus_tab_add(t_process *process, t_vm *vm, size_t cycle)
{
	process->tab_places = cycle;
	if (vm->tab[cycle] == NULL || (vm->tab[cycle]->no < process->no))
		vm->tab[cycle] = ft_processus_tab_front_add(vm->tab[cycle], process);
	else
		ft_processus_tab_core_add(process, vm->tab[cycle]);
}