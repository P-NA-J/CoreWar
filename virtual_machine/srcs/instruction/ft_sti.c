/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:37:26 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 09:35:38 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

void	ft_sti(t_process *process, t_vm *vm)
{
	int param_1;
	int param_2;
	int	value;
	int	pos;

	value = vm->param[0][0];
	param_1 = vm->param[1][0];
	param_2 = vm->param[2][0];
	if (IND_BIT == vm->param[1][1])
		param_1 = ft_value_from_address(process->pc, vm->param[0][0], vm);
	else if (REG_BIT == vm->param[1][1])
		param_1 = process->registre[vm->param[0][0] - 1];
	if (REG_BIT == vm->param[2][1])
		param_2 = process->registre[vm->param[1][0] - 1];
	pos = process->pc + ((param_1 + param_2) % IDX_MOD);
	ft_convert_to_char(vm,
	process->registre[vm->param[0][0] - 1], pos + 4);
}
