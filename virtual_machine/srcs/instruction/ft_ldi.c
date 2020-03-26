/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:35:06 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 20:29:25 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

void	ft_ldi(t_process *process, t_vm *vm)
{
	int param_1;
	int param_2;
	int	value;

	param_1 = vm->param[0][0];
	param_2 = vm->param[1][0];
	if (IND_BIT == vm->param[0][1])
		param_1 = ft_value_from_address(process->pc, vm->param[0][0], vm);
	else if (REG_BIT == vm->param[0][1])
		param_1 = process->registre[vm->param[0][0] - 1];
	if (REG_BIT == vm->param[1][1])
		param_2 = process->registre[vm->param[1][0] - 1];
	value = param_1 + param_2;
	value = ft_value_from_address(process->pc, value, vm);
	process->carry = (process->carry == 1 ? 0 : 1);
}
