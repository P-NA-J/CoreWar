/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processus_player_initialisation.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 10:06:40 by paul              #+#    #+#             */
/*   Updated: 2020/04/03 15:36:47 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/prototypes.h"
#include "../includes/tab.h"
#include "../includes/debug.h"

int		ft_processus_player_initialisation(t_vm *vm)
{
	int	count;
	int	nb_player;
	t_process	*processus;

	nb_player = vm->nb_player;
	count = 0;
	while (count < nb_player)
	{
		if (!(processus = ft_processus_create(count + 1, (MEM_SIZE / nb_player) * count)))
			return (0);
		processus->registre[0] = -(count + 1);
		ft_processus_list_add(vm, processus);
		ft_processus_tab_add(processus, vm, STAND_BY);
		count += 1;
	}
	return (1);
}