/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:35:27 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 19:53:01 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../../libft/includes/prototypes.h"

void	ft_live(t_process *process, t_vm *vm)
{
	int			nb_player;
	int			param;

	nb_player = vm->nb_player;
	param = vm->param[0][0] * (-1);
	if (param > 0 && param <= nb_player)
	{
		ft_printf("un processus dit que le joueur %d(%s) est en vie.\n", param, vm->player_list[param - 1].name);
		process->cycle_last_live = vm->cycle;
		vm->nb_live += 1;
		vm->last_champ_alive = vm->player_list[param - 1].index_player;
	}
}
