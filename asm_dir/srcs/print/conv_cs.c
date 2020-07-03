/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_cs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albanbotier <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 20:54:29 by albanboti         #+#    #+#             */
/*   Updated: 2020/06/12 17:01:49 by albanboti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/prototypes.h"

void	c_conv(t_print *buff, t_flag *flags, int c)
{
	if (flags->width > 1 && !flags->minus)
		field_in_buff(buff, flags->width - 1, flags->zero);
	if (buff->i >= BS_PRINTF)
		empty_buff(buff);
	buff->str[buff->i++] = (unsigned char)c;
	if (flags->width && flags->minus)
		field_in_buff(buff, flags->width - 1, 0);
}

void	s_conv(t_print *buff, t_flag *flags, char *s)
{
	int len;

	if (!s)
		s = "(null)\0";
	if (flags->width)
	{
		len = (int)ft_strlen(s);
		if (flags->prec != -1)
			len = (len > flags->prec ? flags->prec : len);
		if (!flags->minus)
			field_in_buff(buff, flags->width - len, flags->zero);
	}
	while (--flags->prec != -1 && *s)
	{
		if (buff->i >= BS_PRINTF)
			empty_buff(buff);
		buff->str[buff->i++] = *s++;
	}
	if (flags->width && flags->minus)
		field_in_buff(buff, flags->width - len, 0);
}
