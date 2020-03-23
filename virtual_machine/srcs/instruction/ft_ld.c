/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danglass <danglass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:34:52 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/23 17:51:11 by danglass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"

void	ft_ld(t_process *process, t_vm *vm)
{
	int pos;

	if (DIR_BIT == vm->param[0][1])
		process->registre[vm->param[1][0] - 1] = vm->param[0][0];
	else if (IND_BIT == vm->param[0][1])
	{
		pos = process->pc + (vm->param[0][0] % IDX_MOD);
		process->registre[vm->param[1][0] - 1] =
		ft_convert_to_int(vm->vm + pos);
	}
}
