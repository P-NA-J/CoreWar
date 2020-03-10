/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_vm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:59:05 by damboule          #+#    #+#             */
/*   Updated: 2020/03/10 17:24:58 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"

int		ft_read(const char *filecor, unsigned char vm[MEM_SIZE], int write_pos)
{
	char	skip[NOT_READ];
	int		fd;

	if ((fd = open(filecor, O_RDONLY)) == -1)
		return (EXIT_FAILURE);
	read(fd, skip, NOT_READ);
	if (read(fd, vm + write_pos, TO_READ + 1) > TO_READ)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		ft_insertion_vm(const t_args *filecor, unsigned char vm[MEM_SIZE])
{
	int		write_pos;
	int		nb_champ;

	nb_champ = 0;
	while (filecor->champ[nb_champ] != NULL)
	{
		write_pos = (MEM_SIZE / filecor->player_nb) * nb_champ;
		if (ft_read(filecor->champ[nb_champ], vm, write_pos))
			return (EXIT_FAILURE);
		nb_champ++;
	}
	return (EXIT_SUCCESS);
}
