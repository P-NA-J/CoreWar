/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danglass <danglass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:36:56 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/26 17:38:29 by danglass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"

int		ft_lldi_param_recover_value(t_process *process, uint32_t tab[2])
{
	int	param;

	param = tab[0];
	if (tab[1] == DIR_BIT)
		param = (short)tab[0];
	else if (tab[1] == REG_BIT)
		param = process->registre[param - 1];
	return (param);
}

void	ft_lldi(t_process *process, t_vm *vm)
{
	int param_1;
	int param_2;
	int	param_3;
	int	value;

	param_1 = ft_lldi_param_recover_value(process, vm->param[0]);
	param_2 = ft_lldi_param_recover_value(process, vm->param[1]);
	param_3 = ft_lldi_param_recover_value(process, vm->param[2]);
	value = param_1 + param_2;
	process->registre[param_3 - 1] = value;
	process->carry = (process->carry == 1 ? 0 : 1);
}
