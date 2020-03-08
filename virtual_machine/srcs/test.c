/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:31:14 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/05 17:35:20 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/struct.h"
#include "../includes/debug.h"
#include "../includes/prototypes.h"

int	ft_error(void)
{
	puts("Error.");
	return (0);
}

void	ft_loading_processus()
{
	
}

void	ft_check_loading_processus()
{
	
}


void	ft_exec_cycle(unsigned char vm[MEM_SIZE], t_process *process_list, t_process *tab[1024], size_t cycle)
{
	if (tab[cycle] != NULL)
		ft_exec_processus(tab, cycle, vm);
	ft_check_loading_processus();
}

int	main()
{
	unsigned char	vm[MEM_SIZE];
	size_t			cycles;
	t_process		*process_list;
	t_process		*tab[CYCLE_WAIT_MAX];

	process_list = NULL;
	ft_create_vm(vm);
	if (!ft_create_processus_list(2, &process_list))
		return (ft_error());
	bzero(tab, sizeof(tab));
	ft_debug_processus_list(process_list);
	cycles = 0;
	while (cycles < CYCLE_MAX)
	{
		ft_exec_cycle(vm, process_list, tab, cycles);
		cycles += 1;
	}
	return (0);
}