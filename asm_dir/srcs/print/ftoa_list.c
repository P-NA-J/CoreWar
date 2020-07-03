/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albanbotier <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 22:14:12 by albanboti         #+#    #+#             */
/*   Updated: 2020/06/12 17:12:53 by albanboti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>

void	free_bint(t_bint **lst)
{
	t_bint	*next;

	if (lst)
	{
		while (*lst)
		{
			next = (*lst)->next;
			free(*lst);
			*lst = next;
		}
		*lst = NULL;
	}
}

t_bint	*init_bint(char digit)
{
	t_bint	*new;

	if (!(new = (t_bint *)malloc(sizeof(t_bint))))
		return (NULL);
	new->next = NULL;
	new->digit = digit;
	return (new);
}

int		bint_len(t_bint *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while ((lst = lst->next))
		i++;
	return (i);
}
