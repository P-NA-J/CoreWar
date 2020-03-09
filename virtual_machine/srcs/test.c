/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:31:14 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/08 18:12:21 by pauljull         ###   ########.fr       */
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
	t_process		*process_list;
	t_process		*tab[CYCLE_WAIT_MAX];

	process_list = NULL;
	ft_create_vm(&vm);
	bzero(tab, sizeof(tab));
	if (!ft_create_processus_list(2, &process_list))
		return (ft_error());
//	ft_debug_processus_list(process_list);
	cycles = 0;
	while (cycles < CYCLE_MAX)
	{
		printf("NEW CYCLE BEGINNING.\n");
		ft_exec_cycle(&vm, process_list, tab, cycles);
		cycles += 1;
	}
	return (0);
}