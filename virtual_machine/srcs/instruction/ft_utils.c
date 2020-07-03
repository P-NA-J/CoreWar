/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 09:34:14 by paul              #+#    #+#             */
/*   Updated: 2020/06/16 16:24:45 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/prototypes.h"
#include "../../../libft/includes/prototypes.h"
#include "../../includes/op.h"

long			ft_parameter_recover_value(t_vm *vm, size_t pc,
					uint32_t tab[2], t_process *process)
{
	if (tab[1] == T_IND)
		return (ft_value_from_address(pc, tab[0], vm));
	if (tab[1] == T_REG)
		return (process->registre[tab[0] - 1]);
	return (tab[0]);
}

int				ft_unrestr_value_from_address(size_t pc, short indirect,
												t_vm *vm)
{
	int			param;
	int			pos;
	uint8_t		tab[4];

	pos = (pc + indirect) % MEM_SIZE;
	tab[0] = vm->vm[pos++ % MEM_SIZE];
	tab[1] = vm->vm[pos++ % MEM_SIZE];
	tab[2] = vm->vm[pos++ % MEM_SIZE];
	tab[3] = vm->vm[pos % MEM_SIZE];
	param = ft_convert_to_int(tab);
	return (param);
}

int				ft_value_from_address(size_t pc, short indirect, t_vm *vm)
{
	int			param;
	long		pos;
	uint8_t		tab[4];

	pos = (pc + (indirect % IDX_MOD)) % MEM_SIZE;
	tab[0] = vm->vm[pos++ % MEM_SIZE];
	tab[1] = vm->vm[pos++ % MEM_SIZE];
	tab[2] = vm->vm[pos++ % MEM_SIZE];
	tab[3] = vm->vm[pos % MEM_SIZE];
	param = ft_convert_to_int(tab);
	return (param);
}
