/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:35:27 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 10:00:32 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"

void	ft_live(t_process *process, t_vm *vm)
{
	int			nb_player;
	int			param;

	nb_player = vm->nb_player;
	param = vm->param[0][0];
	printf("-------------------------------- nb_player %d | param %d\n", nb_player, param);
	if (param > 0 && param <= nb_player)
		printf("un processus dit que le joueur %d(%s) est en vie.\n", vm->param[0][0], vm->player_list[vm->param[0][0] - 1].name);
	process->cycle_last_live = vm->cycle;
	vm->nb_live += 1;
	vm->last_champ_alive = vm->player_list[vm->param[0][0] - 1].index_player;
}
