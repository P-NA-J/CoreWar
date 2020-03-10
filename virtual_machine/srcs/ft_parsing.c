/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:36:55 by damboule          #+#    #+#             */
/*   Updated: 2020/03/10 18:17:50 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/libft.h"

int		ft_getoccur(char *args, const char *cor)
{
	int length;
	int answer;

	answer = 1;
	length = ft_strlen(args) - 4;
	if (length >= 1)
		answer = ft_strncmp(args + length, cor, 3);
	return (answer);
}

int		ft_get_filecor(const int nb_args, char **args, t_args *filecor)
{
	int		index;

	index = 0;
	while (index < nb_args)
	{
		if (ft_getoccur(args[index], ".cor") == 0)
		{
			printf("wallah.\n");
			filecor->champ[filecor->player_nb] = ft_strdup(args[index]);
			filecor->player_nb++;
		}
		index++;
	}
	printf("nb_player = %d\n", filecor->player_nb);
	if (filecor->player_nb >= 1 && filecor->player_nb <= 4)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int		ft_get_args(const int nb_args, char **args, t_args *filecor)
{
	if (ft_get_filecor(nb_args, args, filecor))
		return (EXIT_FAILURE);
	//ft_get_options();
	return (EXIT_SUCCESS);
}

int		ft_parse(int nb_args, char **args, unsigned char vm[MEM_SIZE])
{
	t_args			filecor;

	ft_bzero(&filecor, sizeof(filecor));
	ft_bzero(&vm, MEM_SIZE);
	if (ft_get_args(nb_args, args, &filecor))
		return (EXIT_FAILURE);
	if (ft_insertion_vm(&filecor, vm))
		return (EXIT_FAILURE);
//	ft_dump(vm);
	return (EXIT_SUCCESS);
}

