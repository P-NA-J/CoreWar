/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:31:14 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/16 21:17:02 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/struct.h"
#include "../includes/debug.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/libft.h"

/*
**	Fonction qui déplace correctement le PC d'une certaine valeur.
*/

void	ft_move_pc(t_process *process, int value)
{
	process->pc = (process->pc + value) % MEM_SIZE;
}

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
	while (cycles < 1000)
	{
		ft_exec_cycle(&vm, tab, cycles);
		cycles += 1;
	}
	return (0);
}
