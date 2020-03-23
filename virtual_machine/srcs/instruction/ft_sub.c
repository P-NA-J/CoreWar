/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danglass <danglass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:37:39 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/23 17:30:33 by danglass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"

void	ft_sub(t_process *process, t_vm *vm)
{
	int	sub;

	sub = process->registre[vm->param[0][0]];
	sub -= process->registre[vm->param[1][0]];
	process->registre[vm->param[2][0]] = sub;
}
