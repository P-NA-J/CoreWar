/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processus_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 10:02:54 by paul              #+#    #+#             */
/*   Updated: 2020/04/03 15:29:39 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/prototypes.h"
#include "../includes/op.h"

/*
**	Fonction qui déplace correctement le PC d'une certaine valeur.
*/

void	ft_move_pc(t_process *process, int value)
{
	int	new_pc;

	new_pc = process->pc + value;
	if (new_pc < 0)
		new_pc = MEM_SIZE + (value % MEM_SIZE);
	else
		new_pc = new_pc % MEM_SIZE;
	process->pc = new_pc;
}

void	ft_process_move(t_process *process, t_vm *vm, int src, int dest)
{
	t_process	*tmp;

	dest = dest % 1000;
	tmp = vm->tab[dest];
	vm->tab[src] = process->next;
	ft_processus_tab_add(process, vm, dest);
}
