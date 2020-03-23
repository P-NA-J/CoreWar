/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:34:11 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/23 18:35:39 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tab.h"
#include "../../includes/struct.h"
#include "../../../libft/includes/libft.h"

void	ft_aff(t_process *process, t_vm *vm)
{
	ft_putchar(process->registre[vm->param[0][0] - 1]);
}
