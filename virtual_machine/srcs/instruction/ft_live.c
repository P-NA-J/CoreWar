/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:35:27 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/20 10:58:39 by paul             ###   ########.fr       */
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
		ft_write_player_alive();
	process->cycle_last_live = vm->cycle;
	process->nb_live += 1;
	process->nb_live_period += 1;
	vm->nb_live += 1;
}
