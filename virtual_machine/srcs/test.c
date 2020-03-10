/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:31:14 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/10 08:55:07 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/struct.h"
#include "../includes/debug.h"
#include "../includes/prototypes.h"

/*
**	Fonction qui déplace correctement le PC d'une certaine valeur.
*/

void	ft_move_pc(t_process *process, int value)
{
	process->pc = (process->pc + value) % MEM_SIZE;
}

int	main()
{
	t_vm			vm;
	size_t			cycles;
	t_process		*tab[CYCLE_WAIT_MAX];

	ft_create_vm(&vm);
	bzero(tab, sizeof(tab));
	if (!ft_create_processus_list(2, tab, &vm))
		return (ft_error());
	cycles = 0;
	while (cycles < CYCLE_MAX + 1)
	{
		printf("cycle %zu\n", cycles);
		ft_exec_cycle(&vm, tab, cycles);
		cycles += 1;
		printf("----------------------------------------\n");
	}
	return (0);
}