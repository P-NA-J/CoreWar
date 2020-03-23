/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danglass <danglass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:37:18 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/23 17:48:16 by danglass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"

void	ft_convert_to_char(unsigned char vm[4096], int reg, int pos)
{
	while (reg)
    {
        vm[pos] = reg;
        pos--;
        reg >>= 8;
    }
}

void	ft_st(t_process *process, t_vm *vm)
{
	int pos;
	
	if (vm->param[1][1] == REG_BIT)
		process->registre[vm->param[1][0] - 1] = process->registre[vm->param[0][0] - 1];
	else if (vm->param[1][1] == IND_BIT)
	{
		pos = process->pc + (vm->param[1][0] % IDX_MOD) + 4;
		ft_convert_to_char(vm->vm,
		process->registre[vm->param[0][0]], pos);
	}
}
