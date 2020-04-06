/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:31:14 by pauljull          #+#    #+#             */
/*   Updated: 2020/04/06 10:26:19 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/struct.h"
#include "../../libft/includes/prototypes.h"
#include "../includes/op.h"
#include "../includes/struct.h"
#include "../includes/debug.h"
#include "../includes/prototypes.h"
#include <stdlib.h>
#include <stdbool.h>

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

int		ft_recover_value_param(uint8_t vm[MEM_SIZE], uint32_t param[2], t_process *process)
{
	int parameter;

	if (param[1] == IND_BIT)
		parameter = ft_get_value_ram(vm + process->pc + (param[1] % IDX_MOD), 4);
	else if (param[1] == REG_BIT)
		parameter = process->registre[param[0] - 1];
	else
		parameter = param[0];
	return (parameter);
}

int		main(int ac, char **av)
{
	t_vm			vm;

	if (ft_initialisation(&vm) == false)
		return (false);
	if (ft_parse(ac - 1, av + 1, &vm))
		return (false);
	if (!ft_processus_player_initialisation(&vm))
		return (false);
/*	if (vm.opt.d[0] == true)
		ft_loop_dumped(&vm, vm.tab);
	else
		ft_loop_std(&vm, vm.tab);
*/	return (0);
}

