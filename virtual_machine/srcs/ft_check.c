/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 10:23:05 by paul              #+#    #+#             */
/*   Updated: 2020/03/23 18:59:37 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/virtual_machine.h"
#include "../includes/prototypes.h"

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

void		ft_is_alive(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX])
{
	size_t	i;

	i = 0;
	while (i < vm->nb_process)
	{
		if (vm->process_list[i]->cycle_last_live < vm->cycle - vm->cycles_to_die)
		{
			ft_rm_processus(vm, *(tab + vm->process_list[i]->tab_places), vm->process_list[i]);
			vm->nb_process -= 1;
		}
		i += 1;
	}
}

void	ft_reset_period(t_vm *vm)
{
	vm->period[0] = 0;
	vm->period[1] = vm->cycles_to_die;
}

void	ft_check(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX])
{
	ft_is_alive(vm, tab);
	if (ft_check_decreasing(vm) == MAX_CHECKS)
		vm->cycles_to_die -= CYCLE_DELTA;
	ft_reset_period(vm);
}