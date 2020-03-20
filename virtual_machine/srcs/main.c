/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:31:14 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/20 16:37:04 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/virtual_machine.h"
#include "../includes/struct.h"
#include "../includes/debug.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/libft.h"

void	ft_init(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX])
{
	ft_bzero(vm, sizeof(vm[0]));
	ft_bzero(tab, sizeof(CYCLE_WAIT_MAX * sizeof(t_process *)));
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->nb_max_process = 64;
}

int		main(int ac, char **av)
{
	t_vm			vm;
	t_process		*tab[CYCLE_WAIT_MAX];

	ft_init(&vm, tab);
	if (ft_parse(ac - 1, av + 1, &vm))
		return (false);
	if (!ft_create_processus_list(vm.nb_player, tab, &vm))
		return (false);
	ft_debug_processus_list(vm.process_list, vm.nb_max_process);
	return (0);
}

/*
int		main(int ac, char **av)
{
	t_vm			vm;
	size_t			cycles;
	t_process		*tab[CYCLE_WAIT_MAX];

	ft_bzero(&vm, sizeof(vm));
	ft_parse(ac - 1, av + 1, vm.vm);
	bzero(tab, sizeof(tab));
	if (!ft_create_processus_list(1, tab, &vm))
		return (ft_error());
	cycles = 0;
	vm.cycles_to_die = CYCLE_TO_DIE;
	while (vm.nb_champs_left > 1)
	{
		ft_exec_cycle(&vm, tab, cycles);
		if (vm.period[0] == 0 && ft_check(&vm) == true)
			return (ft_print_winner(&vm));
		cycles += 1;
		vm.period[0] -= 1;
	}
	ft_print_winner();
	return (0);
}
*/
