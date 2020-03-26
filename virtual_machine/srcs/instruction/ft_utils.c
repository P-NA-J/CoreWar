/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 09:34:14 by paul              #+#    #+#             */
/*   Updated: 2020/03/26 14:13:19 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../includes/op.h"

uint32_t		ft_convert_to_int(unsigned char tab[4])
{
	uint32_t		result;
	int		index;

	result = 0;
	index = 0;
	while (index < 4)
	{
		result |= tab[index];
		if (index < 3)
			result <<= 8;
		index++;
	}
	return (result);
}

void	ft_convert_to_char(t_vm *vm, int reg, int pos)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		vm->vm[pos % MEM_SIZE] = reg;
		pos--;
		reg >>= 8;
		i += 1;
	}
}

int		ft_parameter_recover_value(t_vm *vm, size_t pc, uint32_t tab[2])
{
	if (tab[1] == IND_BIT)
		return (ft_value_from_address(pc, tab[0], vm));
	return (tab[0]);
}

int		ft_value_from_address(size_t pc, int indirect, t_vm *vm)
{
	int param;
	int pos;

	pos = (pc + (indirect % IDX_MOD)) % MEM_SIZE;
	param = ft_convert_to_int(vm->vm + pos);
	return (param);
}