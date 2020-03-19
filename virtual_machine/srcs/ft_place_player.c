/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danglass <danglass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 20:30:42 by danglass          #+#    #+#             */
/*   Updated: 2020/03/19 12:12:28 by danglass         ###   ########.fr       */
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

int		ft_double_option(t_args *filecor)
{
	int index;
	int check;

	index = 0;
	while (index < 4)
	{
		check = 0;
		if (filecor->option[0] == index + 1)
			check++;
		if (filecor->option[1] == index + 1)
			check++;
		if (filecor->option[2] == index + 1)
			check++;
		if (filecor->option[3] == index + 1)
			check++;
		if (check >= 2)
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}

int		ft_get_pos_player(t_args *filecor)
{
	int index;

	index = 0;
	ft_fill(filecor);
	if (ft_double_option(filecor))
		return (EXIT_FAILURE);
	while (filecor->champ[index])
	{
		printf("filecor == %d && option == %d\n", filecor->player_nb, filecor->option[index]);
		if (filecor->option[index] > 4 || filecor->option[index] < 0)
			return (EXIT_FAILURE);
		if (filecor->option[index] != 0 && filecor->option[index] != filecor->pos[index]
			&& filecor->option[index] <= filecor->player_nb)
			ft_replace(filecor, filecor->option[index], index);
		index++;
	}
	return (EXIT_SUCCESS);
}
