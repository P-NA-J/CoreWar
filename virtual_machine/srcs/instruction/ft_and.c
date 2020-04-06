/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:34:28 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/28 22:03:13 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../../libft/includes/prototypes.h"
#include "../../includes/debug.h"

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

void	ft_and(t_process *process, t_vm *vm)
{
	int	param_1;
	int	param_2;
	int	param_3;

	param_1 = ft_parameter_recover_value(vm, process->pc, vm->param[0]);
	param_2 = ft_parameter_recover_value(vm, process->pc, vm->param[1]);
	param_3 = ft_parameter_recover_value(vm, process->pc, vm->param[2]);
	process->registre[param_3 - 1] = param_1 & param_2;
	process->carry = (process->registre[param_3 - 1] == 0 ? 1 : 0);
	ft_verbose(process, vm->param);
	ft_skip_instruction_sequency(process, vm);
}
