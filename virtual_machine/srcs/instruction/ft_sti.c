/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danglass <danglass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:37:26 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/23 18:14:38 by danglass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"

int		ft_value_from_address(int pc, int indirect, t_vm *vm)
{
	int param;
	int pos;

	pos = pc + (indirect % IDX_MOD);
	param = ft_convert_to_int(vm->vm + pos);
	return (param);
}

void	ft_sti(t_process *process, t_vm *vm)
{
	int param_1;
	int param_2;
	int	value;
	int pos;

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
}
