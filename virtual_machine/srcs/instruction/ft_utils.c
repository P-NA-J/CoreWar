/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 09:34:14 by paul              #+#    #+#             */
/*   Updated: 2020/03/25 09:41:29 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

void	ft_convert_to_char(t_vm *vm, int reg, int pos)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		vm->vm[pos] = reg;
		pos--;
		reg >>= 8;
		i += 1;
	}
}

int		ft_value_from_address(int pc, int indirect, t_vm *vm)
{
	int param;
	int pos;

	pos = pc + (indirect % IDX_MOD);
	param = ft_convert_to_int(vm->vm + pos);
	return (param);
}