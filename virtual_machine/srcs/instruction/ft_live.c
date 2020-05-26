/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:35:27 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/25 19:35:47 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../../libft/includes/prototypes.h"
#include "../../includes/debug.h"

static void	ft_verbose(t_process *process, int param)
{
	ft_printf("P%5d | %s ", process->no,
	g_tab_instruction[process->opcode].name);
	ft_printf("%d\n", param);
//	ft_printf("%d carry = %d\n", param, process->carry);
}

void	ft_live(t_process *process, t_vm *vm)
{
	int			nb_player;
	int			param;

	if (process->no == 1290)
	{
		ft_printf("Splendiiiiiiiiiide\n");
		exit(0);
	}
	nb_player = vm->nb_player;
	param = vm->param[0][0] * (-1);
	ft_verbose(process, vm->param[0][0]);
	process->cycle_last_live = vm->cycle;
	vm->nb_live += 1;
	if (param > 0 && param <= nb_player)
	{
//		ft_printf("un processus dit que le joueur %d(%s) est en vie.\n", param, vm->player_list[param - 1].name);
		ft_printf("Player %d (%s) is said to be alive\n", param, vm->player_list[param - 1].name);
		vm->last_champ_alive = vm->player_list[param - 1].index_player;
	}
	ft_skip_instruction_sequency(process, vm);
}
