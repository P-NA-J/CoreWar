/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:09:45 by pauljull          #+#    #+#             */
/*   Updated: 2020/04/06 10:39:40 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tab.h"
#include "../includes/debug.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"

/*
**	Fonction qui execute l'instruction correspondante a l'opcode contenu dans process.
*/

void	ft_exec_instruction(t_process *process, t_vm *vm)
{
	unsigned char	to_exec;

	to_exec = ft_get_param_type(process, vm);
	if (to_exec == TRUE)
		g_tab_instruction[process->opcode].ft_instruction(process, vm);
	else
		ft_skip_bad_ocp_parsing();
	ft_bzero(vm->param, sizeof(vm->param));
}

/*
**	Fonction qui va executer les processus qui doivent etre execute a ce cycle.
*/

void	ft_exec_processus(t_process *tab[1024], size_t cycle, t_vm *vm)
{
	while (tab[cycle % 1000] != NULL)
	{
		ft_exec_instruction(tab[cycle % 1000], vm);
		ft_loading_try_processus(vm, tab[cycle % 1000], cycle);
	}
}

/*
**	Fonction qui gere le déroulement d'un cycle.
*/

void	ft_exec_cycle(t_vm *vm, t_process *tab[1024], size_t cycle)
{
	if (tab[cycle % 1000] != NULL)
		ft_exec_processus(tab, cycle, vm);
}
