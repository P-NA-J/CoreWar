/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:37:52 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/14 17:30:39 by paul             ###   ########.fr       */
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

	ft_printf("P%5d | %s ", process->no, g_tab_instruction[process->opcode].name);
	i = 0;
	while (i < g_tab_instruction[process->opcode].nb_param - 1)
	{
		if (param[i][1] == T_REG)
			ft_printf("%d ", process->registre[param[i][0] - 1]);
		else
			ft_printf("%d ", param[i][0]);
		i += 1;
	}
//	ft_printf("r%d carry = %d\n", param[2][0], process->carry);
	ft_printf("r%d\n", param[2][0]);
}

void	ft_xor(t_process *process, t_vm *vm)
{
	int	param_1;
	int	param_2;
	int	param_3;

	param_1 = ft_parameter_recover_value(vm, process->pc, vm->param[0], process);
	param_2 = ft_parameter_recover_value(vm, process->pc, vm->param[1], process);
	param_3 = ft_parameter_recover_value(vm, process->pc, vm->param[2], process);
	ft_verbose(process, vm->param);
	process->registre[vm->param[2][0] - 1] = param_1 ^ param_2;
//	if (process->no == 6)
//		ft_printf("P    6 %d %d %d\n", param_1, param_2, process->registre[vm->param[2][0] - 1]);
	process->carry = (process->registre[vm->param[2][0] - 1] == 0 ? 1 : 0);
	ft_skip_instruction_sequency(process, vm);
}
