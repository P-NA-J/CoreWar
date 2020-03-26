/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:31:49 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/26 12:41:21 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"

void	ft_add(t_process *process, t_vm *vm)
{
	int adition;
	int	param_1;
	int	param_2;
	int	param_3;

	param_1 = vm->param[0][0];
	param_2 = vm->param[1][0];
	param_3 = vm->param[2][0];
	adition = process->registre[param_1 - 1];
	adition += process->registre[param_2 - 1];
	process->registre[param_3 - 1] = adition;
	process->carry = (process->carry == 1 ? 0 : 1);
}
