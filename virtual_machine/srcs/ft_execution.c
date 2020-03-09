/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:09:45 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/08 18:12:16 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tab.h"

/*
**	Fonction qui va deplacer le PC lorsque l'instruction a été executer.
*/

void	ft_skip_instruction_sequency(t_process *process, t_vm *vm)
{
	int	to_skip;
	int	nb_param;
	int	j;

	to_skip = 1;
	nb_param = tab_instruction[process->opcode].nb_param;
	j = 0;
	while (j < nb_param)
	{
		if (vm->param[j][1] == REG_CODE)
			to_skip += 1;
		else if (vm->param[j][1] == IND_CODE)
			to_skip += 2;
		else if (vm->param[j][1] == DIR_CODE)
			to_skip += tab_instruction[process->opcode].dir_size;
		j += 1;
	}
	ft_move_pc(process, to_skip);
}

/*
**	Fonction qui execute l'instruction correspondante a l'opcode contenu dans process.
*/

void	ft_exec_instruction(t_process *process, t_vm *vm)
{
	unsigned char	to_exec;
	unsigned char	op_code;

	to_exec = ft_get_param_type(process, vm);
	printf("to_exec = [ %d ]\n", to_exec);
	op_code = process->opcode;
	if (to_exec == TRUE)
	{
		tab_instruction[op_code].ft_instruction(process, vm);
		ft_skip_instruction_sequency(process, vm);
	}
}

/*
**	Fonction qui va executer les processus qui doivent etre execute a ce cycle.
*/

void	ft_exec_processus(t_process *tab[1024], size_t cycle, t_vm *vm)
{
	while (tab[cycle % 1024] != NULL)
	{
		printf("J'execute une instruction.\n");
		ft_exec_instruction(tab[cycle % 1024], vm);
		tab[cycle % 1024] = tab[cycle % 1024]->next;
	}
}

/*
**	Fonction qui gere le déroulement d'un cycle.
*/

void	ft_exec_cycle(t_vm *vm, t_process *process_list, t_process *tab[1024], size_t cycle)
{
	if (tab[cycle % 1024] != NULL)
		ft_exec_processus(tab, cycle, vm);
	ft_check_loading_tab_processus(process_list->begin, vm, tab, cycle);
}