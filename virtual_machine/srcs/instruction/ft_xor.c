/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:37:52 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 20:28:46 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

void	ft_xor(t_process *process, t_vm *vm)
{
	int	param_1;
	int	param_2;

	param_1 = ft_recover_value_param(vm->vm, vm->param[0], process);
	param_2 = ft_recover_value_param(vm->vm, vm->param[1], process);
	process->registre[vm->param[2][0] - 1] = param_1 ^ param_2;
	process->carry = (process->carry == 1 ? 0 : 1);
}
