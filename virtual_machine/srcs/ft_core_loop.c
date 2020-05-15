/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 09:23:15 by paul              #+#    #+#             */
/*   Updated: 2020/05/14 18:23:45 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/struct.h"
#include "../../libft/includes/prototypes.h"
#include "../includes/debug.h"

void	ft_loop_dumped(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX])
{
	while (vm->cycle <= vm->opt.d[1] && vm->nb_process > 1)
	{
//		ft_loading_check_processus(vm, vm->cycle);
		ft_exec_cycle(vm, tab, vm->cycle);
		if (vm->period[0] == vm->period[1])
			ft_check(vm, tab);
		vm->cycle += 1;
		vm->period[0] += 1;
		ft_printf("It is now cycle %zu\n", vm->cycle);
	}
	ft_dump(vm->vm);
}

void	ft_loop_std(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX])
{
	while (vm->nb_process > 1)
	{
//		ft_loading_check_processus(vm, vm->cycle);
		ft_exec_cycle(vm, tab, vm->cycle);
		if (vm->period[0] == vm->period[1])
			ft_check(vm, tab);
		vm->cycle += 1;
		vm->period[0] += 1;
		ft_printf("It is now cycle %zu\n", vm->cycle);
	}
	ft_printf("The winner is |%d|\n", vm->process_list[0]->registre[0]);
	ft_debug_processus_list(vm->process_list, vm->nb_process);
}