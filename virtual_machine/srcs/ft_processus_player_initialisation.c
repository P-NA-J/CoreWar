/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processus_player_initialisation.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 10:06:40 by paul              #+#    #+#             */
/*   Updated: 2020/04/23 11:27:04 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/prototypes.h"
#include "../includes/tab.h"
#include "../includes/debug.h"
#include <stdbool.h>

static int		ft_processus_create_player(t_vm *vm, const int count, const int nb_player)
{
	t_process	*processus;

	if (!(processus = ft_processus_create(count + 1, (MEM_SIZE / nb_player) * count)))
			return (false);
	processus->registre[0] = -(count + 1);
	ft_processus_list_add(vm, processus);
	ft_processus_tab_add(processus, vm, STAND_BY);
	return (true);
}

int		ft_processus_player_initialisation(t_vm *vm)
{
	int	count;
	int	nb_player;

	nb_player = vm->nb_player;
	count = 0;
	while (count < nb_player)
		if (!(ft_processus_create_player(vm, count++, nb_player)))
			return (false);
	return (true);
}