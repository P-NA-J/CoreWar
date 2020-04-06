/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:36:31 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/28 22:03:49 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../includes/debug.h"
#include "../../../libft/includes/prototypes.h"

static void	ft_verbose(t_process *process, uint32_t param[3][2])
{
	int	i;

	ft_printf("P%4d | %s ", process->no, g_tab_instruction[process->opcode].name);
	i = 0;
	while (i < g_tab_instruction[process->opcode].nb_param)
	{
		if (param[i][1] == REG_BIT)
			ft_printf("r");
		ft_printf("%d ", param[i][0]);
		i += 1;
	}
	ft_printf("\n");
}

uint32_t		ft_convert2bytes_to_int(unsigned char tab[4])
{
	uint32_t		result;
	int		index;

	result = 0;
	index = 0;
	while (index < 2)
	{
		result |= tab[index];
		if (index < 1)
			result <<= 8;
		index++;
	}
	return (result);
}

void	ft_lld(t_process *process, t_vm *vm)
{
	int	param_1;
	int	param_2;

	param_1 = vm->param[0][0];
	param_2 = vm->param[1][0];
	if (DIR_BIT == vm->param[0][1])
		process->registre[param_2 - 1] = param_1;
	else if (IND_BIT == vm->param[0][1])
	{
		process->registre[param_2 - 1] =
		ft_convert2bytes_to_int(vm->vm + param_1);
	}
	process->carry = (process->registre[param_2 - 1] == 0 ? 1 : 0);
	ft_verbose(process, vm->param);
	ft_skip_instruction_sequency(process, vm);
}
