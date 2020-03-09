/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:07:31 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/09 17:07:47 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/virtual_machine.h"
#include "../includes/op.h"

/*
** Dump : Fonction qui parcours la VM et Convertie/Print chaque Char en Hexa 
*/

void	ft_dump(const unsigned char vm[MEM_SIZE])
{
	int		len;

	len = 0;
	while (len < MEM_SIZE)
	{
		if (len % 64 == 0)
			printf("0x%.4x : ", len);
		if ((len + 1) % 64 == 0)
			printf("%.2x\n", vm[len]);
		else
			printf("%.2x ", vm[len]);
		len++;
	}
	return ;
}
