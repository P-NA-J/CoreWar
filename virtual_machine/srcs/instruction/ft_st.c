/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:37:18 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 09:35:45 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"

void	ft_st(t_process *process, t_vm *vm)
{
	int pos;
	
	if (vm->param[1][1] == REG_BIT)
		process->registre[vm->param[1][0] - 1] = process->registre[vm->param[0][0] - 1];
	else if (vm->param[1][1] == IND_BIT)
	{
		pos = process->pc + (vm->param[1][0] % IDX_MOD) + 3;
		ft_convert_to_char(vm,
		process->registre[vm->param[0][0] - 1], pos);
	}
}
