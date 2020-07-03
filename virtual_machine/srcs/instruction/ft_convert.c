/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 16:25:07 by paul              #+#    #+#             */
/*   Updated: 2020/06/16 16:29:35 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../../libft/includes/prototypes.h"
#include "../../includes/op.h"

uint32_t		ft_convert_ram_to_int(t_vm *vm, int pos)
{
	uint32_t	result;
	int			index;

	result = 0;
	index = 0;
	while (index < 4)
	{
		result |= vm->vm[pos % MEM_SIZE];
		if (index < 3)
			result <<= 8;
		index++;
		pos += 1;
	}
	return (result);
}

uint32_t		ft_convert_to_int(unsigned char tab[4])
{
	uint32_t	result;
	int			index;

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

void			ft_convert_to_char(t_vm *vm, int reg, int pos)
{
	int			i;

	i = 0;
	pos = (pos >= 0 ? pos : MEM_SIZE + pos);
	while (i < 4)
	{
		vm->vm[pos % MEM_SIZE] = reg;
		pos = (pos > 0 ? pos - 1 : MEM_SIZE + (pos - 1));
		reg >>= 8;
		i += 1;
	}
}
