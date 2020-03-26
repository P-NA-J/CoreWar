/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 09:34:14 by paul              #+#    #+#             */
/*   Updated: 2020/03/25 20:57:03 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../includes/op.h"

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

int		ft_value_from_address(int pc, int indirect, t_vm *vm)
{
	int param;
	int pos;

	pos = (pc + (indirect % IDX_MOD)) % MEM_SIZE;
	param = ft_convert_to_int(vm->vm + pos);
	return (param);
}