/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:37:26 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/26 14:10:19 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

int		ft_sti_param_recover_value(t_vm *vm, t_process *process, uint32_t tab[2])
{
	int	param;

	param = tab[0];
	if (tab[1] == DIR_BIT)
		param = (short)tab[0];
	else if (tab[1] == REG_BIT)
		param = process->registre[param - 1];
	else if (tab[1] == IND_BIT)
		param = ft_value_from_address(process->pc, param, vm);
	return (param);
}

void	ft_sti(t_process *process, t_vm *vm)
{
	int param_1;
	int param_2;
	int	param_3;
	int	pos;

	param_1 = ft_sti_param_recover_value(vm, process, vm->param[0]);
	param_2 = ft_sti_param_recover_value(vm, process, vm->param[1]);
	param_3 = ft_sti_param_recover_value(vm, process, vm->param[2]);
	pos = process->pc + ((param_1 + param_2) % IDX_MOD);
	ft_convert_to_char(vm,
	process->registre[param_1 - 1], process->pc + pos + 3);
}
