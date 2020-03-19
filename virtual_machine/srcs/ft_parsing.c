/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danglass <danglass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:36:55 by damboule          #+#    #+#             */
/*   Updated: 2020/03/19 11:40:46 by danglass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/libft.h"

int		ft_getoccur(char *args, const char *cor)
{
	int length;

	length = ft_strlen(args) - 4;
	if (length >= 1)
		return (ft_strncmp(args + length, cor, 3));
	return (1);
}

int		ft_get_filecor(int nb_args, char **args, t_args *filecor, t_option *op)
{
	int		index;

	index = 0;
	while (index < nb_args)
	{
		if (ft_strcmp(args[index], "-n") == 0
				&& ft_check_int(args[index + 1]) == 0)
			filecor->option[filecor->player_nb] = ft_atoi(args[index + 1]);
		else if (ft_getoccur(args[index], ".cor") == 0
				&& filecor->player_nb <= 4)
			filecor->champ[filecor->player_nb++] = ft_strdup(args[index]);
		else if (ft_get_options(index, args, op))
			return (EXIT_FAILURE);
		index++;
	}
	if (filecor->player_nb >= 1)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int		ft_get_args(const int nb_arg, char **arg, t_args *filecor, t_option *op)
{
	if (nb_arg == NO_ARGS)
		return (ft_usage(NO_ARGS));
	if (nb_arg == 1 && ft_strcmp(arg[0], "--help") == 0)
		return (ft_usage(0));
	if (ft_get_filecor(nb_arg, arg, filecor, op))
		return (ft_usage(PARSING));
	if (ft_get_pos_player(filecor))
		return (ft_usage(FALSE_POS));
	return (EXIT_SUCCESS);
}

int		ft_parse(int nb_args, char **args, t_vm *vm)
{
	t_args			filecor;

	ft_bzero(&filecor, sizeof(filecor));
	if (!(filecor.champ = (char **)ft_memalloc(sizeof(char *) * (4 + 1))))
		return (EXIT_FAILURE);
	if (ft_get_args(nb_args, args, &filecor, &(vm->opt)))
		return (ft_free_filecor(&filecor));
	if (ft_insertion_vm(&filecor, vm->vm, vm->player_list))
		return (ft_free_filecor(&filecor));
	vm->nb_player = filecor.player_nb;
	ft_print_intro(vm->player_list);
	ft_free_filecor(&filecor);
	return (EXIT_SUCCESS);
}
