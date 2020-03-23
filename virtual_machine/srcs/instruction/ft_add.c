/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:31:49 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/23 17:35:08 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"

void	ft_add(t_process *process, t_vm *vm)
{
	int adition;

	adition = process->registre[vm->param[0][0] - 1];
	adition += process->registre[vm->param[1][0] - 1];
	process->registre[vm->param[2][0] - 1] = adition;
}
