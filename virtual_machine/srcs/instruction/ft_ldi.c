/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:35:06 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/14 17:20:22 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../includes/debug.h"
#include "../../../libft/includes/prototypes.h"
#include <stdio.h>

static void	ft_verbose(t_process *process, uint32_t param[3][2])
{
	int	i;

	ft_printf("P%5d | %s ", process->no, g_tab_instruction[process->opcode].name);
	i = 0;
	while (i < g_tab_instruction[process->opcode].nb_param)
	{
		if (i == 2 && param[i][1] == T_REG)
			ft_printf("r");
		if (param[i][1] == T_DIR)
			ft_printf("%hd", param[i][0]);
		else
			ft_printf("%d", param[i][0]);
		if (i < g_tab_instruction[process->opcode].nb_param - 1)
			ft_printf(" ");
		i += 1;
	}
	ft_printf("\n");
//	ft_printf("carry = %d\n", process->carry);
	ft_printf("       | -> load from ");
	if (param[0][1] == T_DIR)
	{
		ft_printf("%hd + ", param[0][0]);
	}
	else
		ft_printf("%d + ", param[0][0]);
	if (param[1][1] == T_DIR)
	{
		ft_printf("%hd = ", param[1][0]);
	}
	else
		ft_printf("%d = ", param[1][0]);
	ft_printf("%d", param[0][0] + param[1][0]);
	ft_printf(" (with pc and mod %d)\n", process->pc + ((short)param[0][0] + (short)param[1][0]) % IDX_MOD);
}

int		ft_ldi_param_recover_value(t_vm *vm, t_process *process, uint32_t tab[2])
{
	int	param;

	param = tab[0];
	if (tab[1] == T_DIR)
		param = (short)tab[0];
	else if (tab[1] == T_REG)
		param = process->registre[param - 1];
	else if (tab[1] == T_IND)
		param = ft_value_from_address(process->pc, param, vm);
	return (param);
}

void	ft_ldi(t_process *process, t_vm *vm)
{
	int param_1;
	int param_2;
	int	param_3;
	int	value;

	param_1 = ft_ldi_param_recover_value(vm, process, vm->param[0]);
	param_2 = ft_ldi_param_recover_value(vm, process, vm->param[1]);
	param_3 = vm->param[2][0];
	vm->param[0][0] = param_1;
	vm->param[1][0] = param_2;
	value = param_1 + param_2;
	value = ft_value_from_address(process->pc, value, vm);
	process->registre[param_3 - 1] = value;
	process->carry = (value == 0 ? 1 : 0);
	ft_verbose(process, vm->param);
	ft_skip_instruction_sequency(process, vm);
}
