/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:36:56 by pauljull          #+#    #+#             */
/*   Updated: 2020/05/07 12:42:32 by paul             ###   ########.fr       */
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
	while (i < g_tab_instruction[process->opcode].nb_param)
	{
		if (param[i][1] == T_REG)
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
}

int		ft_lldi_param_recover_value(t_process *process, uint32_t tab[2])
{
	int	param;

	param = tab[0];
	if (tab[1] == T_DIR)
		param = (short)tab[0];
	else if (tab[1] == T_REG)
		param = process->registre[param - 1];
	return (param);
}

void	ft_lldi(t_process *process, t_vm *vm)
{
	int param_1;
	int param_2;
	int	param_3;
	int	value;

	param_1 = ft_lldi_param_recover_value(process, vm->param[0]);
	param_2 = ft_lldi_param_recover_value(process, vm->param[1]);
	param_3 = vm->param[2][0];
	value = param_1 + param_2;
	process->registre[param_3 - 1] = value;
	process->carry = (value == 0 ? 1 : 0);
	ft_verbose(process, vm->param);
	ft_skip_instruction_sequency(process, vm);
}
