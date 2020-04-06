/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 09:23:15 by paul              #+#    #+#             */
/*   Updated: 2020/04/06 09:25:07 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/struct.h"
#include "../../libft/includes/prototypes.h"

void	ft_loop_dumped(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX])
{
	while (vm->cycle <= (size_t)vm->opt.d[1] && vm->nb_process > 1)
	{
		ft_printf("It is now cycle %zu\n", vm->cycle);
		ft_exec_cycle(vm, tab, vm->cycle);
		ft_loading_check_processus(vm, vm->cycle);
		if (vm->period[0] == CYCLE_TO_DIE)
			ft_check(vm, tab);
		vm->cycle += 1;
		vm->period[0] += 1;
	}
	ft_dump(vm->vm);
}

void	ft_loop_std(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX])
{
	while (vm->nb_process > 1)
	{
		ft_printf("It is now cycle %zu\n", vm->cycle);
		ft_exec_cycle(vm, tab, vm->cycle);
		ft_loading_check_processus(vm, vm->cycle);
		if (vm->period[0] == CYCLE_TO_DIE)
			ft_check(vm, tab);
		vm->cycle += 1;
		vm->period[0] += 1;
	}
}