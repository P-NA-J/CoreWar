/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:31:14 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/23 18:20:58 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/virtual_machine.h"
#include "../includes/struct.h"
#include "../includes/debug.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/libft.h"

int		ft_get_value_ram(uint8_t vm[4], int	len)
{
	int	i;
	int	res;

	i = 0;
	while (i < len)
	{
		res = vm[i];
		if (i < len - 1)
			res <<= 8;
		i += 1;
	}
	return (res);
}

int		ft_recover_value_param(uint32_t param[2], t_process *process)
{
	if (param[1] == IND_BIT)
		param = ft_get_value_ram(process->pc + (param[1] % IDX_MOD));
	else if (param[1] == REG_BIT)
		param = process->registre[param[0] - 1];
	else
		param = param[0];
	return (param);
}

int	ft_init(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX])
{
	ft_bzero(vm, sizeof(vm[0]));
	ft_bzero(tab, CYCLE_WAIT_MAX * sizeof(t_process *));
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->nb_max_process = 64;
	if (!(vm->process_list = (t_process **)ft_memalloc(sizeof(t_process *) * 64)))
		return (false);
	return (true);
}

void	ft_loop_dumped(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX])
{
	while (vm->cycle < (size_t)vm->opt.d[1] || vm->nb_champs_left > 1)
	{
		ft_exec_cycle(vm, tab, vm->cycle);
		if (vm->period[0] == CYCLE_TO_DIE)
			ft_check(vm, tab);
		vm->cycle += 1;
		vm->period[0] += 1;
	}
	ft_dump(vm->vm);
}

void	ft_loop_std(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX])
{
	while (vm->nb_champs_left > 1)
	{
		ft_exec_cycle(vm, tab, vm->cycle);
		if (vm->period[0] == CYCLE_TO_DIE)
			ft_check(vm, tab);
		vm->cycle += 1;
		vm->period[0] += 1;
	}
}

int		main(int ac, char **av)
{
	t_vm			vm;

	if (ft_init(&vm, vm.tab) == false)
		return (false);
	if (ft_parse(ac - 1, av + 1, &vm))
		return (false);
	if (!ft_create_processus_list(vm.nb_player, vm.tab, &vm))
		return (false);
	if (vm.opt.d[0] == true)
		ft_loop_dumped(&vm, vm.tab);
	else
		ft_loop_std(&vm, vm.tab);
	return (0);
}

/*
int		main(int ac, char **av)
{
	t_vm			vm;
	size_t			cycles;
	t_process		*tab[CYCLE_WAIT_MAX];

	ft_bzero(&vm, sizeof(vm));
	ft_parse(ac - 1, av + 1, &vm);
	bzero(tab, sizeof(tab));
	if (!ft_create_processus_list(1, tab, &vm))
		return (false);
	cycles = 0;
	vm.cycles_to_die = CYCLE_TO_DIE;
	while (cycles < 1500)
	{
		ft_exec_cycle(&vm, tab, cycles);
//		if (vm.period[0] == 0 && ft_check(&vm) == true)
//			return (ft_print_winner(&vm));
		cycles += 1;
//		vm.period[0] -= 1;
	}
//	ft_print_winner();
	return (0);
}
*/
