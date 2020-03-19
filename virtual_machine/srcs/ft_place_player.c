/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danglass <danglass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 20:30:42 by danglass          #+#    #+#             */
/*   Updated: 2020/03/17 20:31:53 by danglass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/libft.h"


int		ft_replace(t_args *filecor, int pos, int index)
{
	int tmp;

	tmp = 0;
	filecor->pos[index] = pos;
	tmp = pos - 1;
	if (pos < index + 1)
	{
		while (tmp < index)
		{
			filecor->pos[tmp] += 1;
			tmp += 1;
		}		
	}
	if (pos > index + 1)
	{
		while (tmp > index)
		{
			filecor->pos[tmp] += -1;
			tmp += -1;
		}		
	}
	return (EXIT_SUCCESS);
}

void	ft_fill(t_args *filecor)
{
	int index;

	index = 0;
	while (filecor->champ[index])
	{
		filecor->pos[index] = index + 1;
		index++;
	}
}

int		ft_get_pos_player(t_args *filecor)
{
	int index;

	index = 0;
	ft_fill(filecor);
	while (filecor->champ[index])
	{
		if (filecor->option[index] > 4 || filecor->option[index] < 0)
			return (EXIT_FAILURE);
		if (filecor->option[index] != 0 && filecor->pos[index])
			ft_replace(filecor, filecor->option[index], index);
		index++;
	}
	return (EXIT_SUCCESS);
}
