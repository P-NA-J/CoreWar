/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:37:39 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/26 12:42:13 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"

void	ft_sub(t_process *process, t_vm *vm)
{
	int	sub;
	int	param_1;
	int	param_2;
	int	param_3;

	param_1 = vm->param[0][0];
	param_2 = vm->param[1][0];
	param_3 = vm->param[2][0];
	sub = process->registre[param_1 - 1];
	sub -= process->registre[param_2 - 1];
	process->registre[param_3 - 1] = sub;
	process->carry = (process->carry == 1 ? 0 : 1);
}
