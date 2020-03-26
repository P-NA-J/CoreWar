/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:37:07 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/26 12:57:07 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

void	ft_or(t_process *process, t_vm *vm)
{
	int	param_1;
	int	param_2;
	int	param_3;

	param_1 = ft_parameter_recover_value(vm, process->pc, vm->param[0]);
	param_2 = ft_parameter_recover_value(vm, process->pc, vm->param[1]);
	param_3 = ft_parameter_recover_value(vm, process->pc, vm->param[2]);
	process->registre[vm->param[2][0] - 1] = param_1 | param_2;
	process->carry = (process->carry == 1 ? 0 : 1);
}
