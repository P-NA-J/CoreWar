/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:37:18 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 21:30:56 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

void	ft_st(t_process *process, t_vm *vm)
{
	int pos;
	int	param_1;
	short	param_2;

	param_1 = vm->param[0][0];
	param_2 = vm->param[1][0];
	if (vm->param[1][1] == REG_BIT)
		process->registre[param_2 - 1] = process->registre[param_1 - 1];
	else if (vm->param[1][1] == IND_BIT)
	{
		pos = process->pc + (param_2 % IDX_MOD) + 3;
		printf("pos = %x\n", pos);
		ft_convert_to_char(vm,
		process->registre[param_1 - 1], pos);
	}
}
