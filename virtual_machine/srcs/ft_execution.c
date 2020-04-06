/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:09:45 by pauljull          #+#    #+#             */
/*   Updated: 2020/04/03 15:47:15 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tab.h"
#include "../includes/debug.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"

int	ft_skip_one_parameter_field(t_vm *vm, int to_skip, const int j, const uint8_t opcode)
{
	if (vm->param[j][1] == REG_BIT)
		to_skip += 1;
	else if (vm->param[j][1] == IND_BIT)
		to_skip += 2;
	else if (vm->param[j][1] == DIR_BIT)
		to_skip += g_tab_instruction[opcode].dir_size;
	return (to_skip);
}

/*
**	Fonction qui va deplacer le PC lorsque l'instruction a été executer.
*/

void	ft_skip_instruction_sequency(t_process *process, t_vm *vm)
{
	int	to_skip;
	int	nb_param;
	int	j;
	int i;

	to_skip = 0;
	if (g_tab_instruction[process->opcode].ocp == TRUE)
		to_skip = 1;
	nb_param = g_tab_instruction[process->opcode].nb_param;
	j = 0;
	while (j < nb_param)
		to_skip = ft_skip_one_parameter_field(vm, to_skip, j++, process->opcode);
	ft_printf("ADV %d (%#.4x -> %#.4x)", to_skip + 1, process->pc, process->pc + to_skip + 1);
	i = 0;
	while (i <= to_skip)
		ft_printf( " %.2x", vm->vm[(process->pc + i++) % MEM_SIZE]);
	ft_printf("\n");
	ft_move_pc(process, to_skip + 1);
}

/*
**	Fonction qui execute l'instruction correspondante a l'opcode contenu dans process.
*/

void	ft_exec_instruction(t_process *process, t_vm *vm)
{
	unsigned char	to_exec;

	to_exec = ft_get_param_type(process, vm);
	if (to_exec == TRUE)
	{
		g_tab_instruction[process->opcode].ft_instruction(process, vm);
		bzero(vm->param, sizeof(vm->param));
	}
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
