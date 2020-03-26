/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danglass <danglass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:36:31 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/26 17:33:17 by danglass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"

uint32_t		ft_convert2bytes_to_int(unsigned char tab[4])
{
	uint32_t		result;
	int		index;

	result = 0;
	index = 0;
	while (index < 2)
	{
		result |= tab[index];
		if (index < 1)
			result <<= 8;
		index++;
	}
	return (result);
}

void	ft_lld(t_process *process, t_vm *vm)
{
	int	param_1;
	int	param_2;

	param_1 = vm->param[0][0];
	param_2 = vm->param[1][0];
	if (DIR_BIT == vm->param[0][1])
		process->registre[param_2 - 1] = param_1;
	else if (IND_BIT == vm->param[0][1])
	{
		process->registre[param_2 - 1] =
		ft_convert2bytes_to_int(vm->vm + param_1);
	}
	process->carry = (process->carry == 1 ? 0 : 1);
}
