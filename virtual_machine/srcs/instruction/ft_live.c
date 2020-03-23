/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:35:27 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/23 17:26:07 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"

void	ft_live(t_process *process, t_vm *vm)
{
	int			nb_player;
	int			param;

	nb_player = vm->nb_player * (-1);
	param = vm->param[0][0];
	if (param < 0 && param >= nb_player)
		printf("un processus dit que le joueur %d(%s) est en vie.\n", -1 * vm->param[0][0], vm->player_list[-1 * vm->param[0][0] - 1].name);
	process->cycle_last_live = vm->cycle;
}
