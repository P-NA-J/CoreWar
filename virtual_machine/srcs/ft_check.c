/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 10:23:05 by paul              #+#    #+#             */
/*   Updated: 2020/03/18 10:24:01 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/virtual_machine.h"

int	ft_check_decreasing(t_vm *vm)
{
	if (vm->nb_live >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->no_decrease_check = 0;
	}
	else
		vm->no_decrease_check += 1;
	return (vm->no_decrease_check);
}

int		ft_is_alive(t_vm *vm)
{
	int	i;
	int	alive;

	alive = 0;
	i = 0;
	while (i < 4)
	{
		if (vm->process_list[i]->cycle_last_live == vm->period[1])
			alive += 1;
		else
			ft_rm_champs();
		i += 1;
	}
	return (alive);
}

int		ft_check(t_vm *vm)
{
	if (ft_is_alive(vm) == 1)
		return (true);
	if (ft_check_decreasing(vm) == MAX_CHECKS)
		vm->cycles_to_die -= CYCLE_DELTA;
	ft_reset_period(vm);
	return (false);
}