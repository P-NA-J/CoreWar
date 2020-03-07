/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:41:53 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/05 17:26:35 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/op.h"

void	ft_add(t_process *process, t_vm *vm)
{
	int	r1;
	int	r2;

	r1 = process->registre[vm->param.p1[0]];
	r2 = process->registre[vm->param.p2[0]];
	process->registre[vm->param.p3[0]] = r1 + r2;
	process->carry = (process->carry == 0 ? 1 : 0);
	process->ocp += 5;
}

void	ft_ld(t_process *process, t_vm *vm)
{
	uint32_t	l_ocp;

	if (vm->param.p1[1] == DIR_CODE)
		process->registre[vm->param.p2[0]] = vm->param.p1[0];
	else if (vm->param.p1[1] == IND_CODE)
	{
		l_ocp = vm + process->ocp + vm->param.p1[0];
		process->registre[vm->param.p2[0]] = ft_get_value_vm(l_ocp, REG_SIZE);
	}
	process->ocp += 2 + (vm->param.p1[1] == IND_CODE ? 2 : 4);
}