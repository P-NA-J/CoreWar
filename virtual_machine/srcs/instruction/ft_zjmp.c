/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:38:04 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/23 17:24:24 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"

void	ft_zjmp(t_process *process, t_vm *vm)
{
	if (process->carry == 1)
		process->pc += process->pc + (vm->param[0][0] % IDX_MOD);
}
