/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danglass <danglass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:36:56 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/26 17:12:14 by danglass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"

void	ft_lldi(t_process *process, t_vm *vm)
{
	int param_1;
	int param_2;
	int	param_3;
	int	value;

	param_1 = ft_ldi_param_recover_value(vm, process, vm->param[0]);
	param_2 = ft_ldi_param_recover_value(vm, process, vm->param[1]);
	param_3 = ft_ldi_param_recover_value(vm, process, vm->param[2]);
	value = param_1 + param_2;
	value = ft_value_from_address(process->pc, value, vm);
	process->registre[param_3 - 1] = value;
	process->carry = (process->carry == 1 ? 0 : 1);
}
