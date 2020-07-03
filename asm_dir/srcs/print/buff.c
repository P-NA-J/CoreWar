/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albanbotier <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 19:21:45 by albanboti         #+#    #+#             */
/*   Updated: 2020/06/12 17:00:41 by albanboti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void	color_in_buff(t_print *buff, char *color)
{
	char *tmp;

	tmp = color;
	if (buff->i + 25 >= BS_PRINTF)
		empty_buff(buff);
	while (*color)
		buff->str[buff->i++] = *color++;
	free(tmp);
}

void	field_in_buff(t_print *buff, int width, char zero)
{
	char c;

	c = ' ' + zero;
	if (buff->i + width >= BS_PRINTF || width + buff->i < 0)
	{
		while (--width >= 0)
		{
			if (buff->i >= BS_PRINTF)
				empty_buff(buff);
			buff->str[buff->i++] = c;
		}
	}
	else
	{
		while (--width >= 0)
			buff->str[buff->i++] = c;
	}
}

void	empty_buff(t_print *buff)
{
	int i;

	i = buff->i;
	buff->i = 0;
	buff->total += (int)write(buff->fd, buff->str, i);
	if (buff->total < 0)
		buff->error = 1;
}
