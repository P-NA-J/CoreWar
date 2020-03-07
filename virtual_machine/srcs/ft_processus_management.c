/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processus_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:28:14 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/05 16:40:47 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/struct.h"
#include "../includes/virtual_machine.h"

t_process	*ft_create_processus(int nb_player, size_t ocp)
{
	t_process *process;

	if (!(process = (t_process *)malloc(sizeof(t_process))))
		return (NULL);
	bzero(process->registre, sizeof(process->registre));
	if (nb_player > 0 && nb_player <= LIMIT_CHAMP)
		process->registre[0] = -nb_player;
	else
		return (NULL);
	process->ocp = ocp;
	process->carry = 0;
	process->cycle_left = 0;
	process->next = NULL;
	return (process);
}

void	ft_add_process(t_process **head, t_process *process)
{
	t_process	*h_tmp;
	t_process	*local;

	h_tmp = head[0];
	local = head[0];
	if (head[0] == NULL)
		head[0] = process;
	else
	{
		process->next = local;
		head[0] = process;
	}
}

int	ft_create_processus_list(int nb_player, t_process **process_list)
{
	int	i;
	size_t	ocp;
	t_process *process;

	if (!process_list)
		return (ERROR);
	i = 0;
	while (i < nb_player)
	{
		ocp = (MEM_SIZE / nb_player) * i;
		if(!(process = ft_create_processus(i + 1, ocp)))
			return (ERROR);
		ft_add_process(process_list, process);
		i += 1;
	}
	return (TRUE);
}