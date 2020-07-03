/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albanbotier <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 23:45:39 by albanboti         #+#    #+#             */
/*   Updated: 2020/06/12 17:30:07 by albanboti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdlib.h>

size_t			param_strrspn(const char *s, const char *accept, char stop)
{
	const char	*tmp;
	size_t		i;

	if ((i = ft_strclen(s, stop)))
		i -= 1;
	while (i > 0)
	{
		tmp = accept;
		while (*tmp != s[i])
			if (!*tmp++)
				return (i);
		--i;
	}
	return (i);
}

unsigned char	*lst_to_char(t_env *e, unsigned char *header, int *size)
{
	unsigned char	*str;
	t_buff			*buff;
	int				i;
	int				j;

	buff = e->file->begin_buff;
	*size = HEADER_SIZE;
	while (buff)
	{
		*size += buff->len;
		buff = buff->next;
	}
	if (!(str = (unsigned char *)malloc(sizeof(unsigned char) * (*size))))
		alloc_error(e);
	i = 0;
	while (i < HEADER_SIZE)
		str[i++] = *header++;
	buff = e->file->begin_buff;
	while (buff && !(j = 0))
	{
		while (j < buff->len)
			str[i++] = buff->s[j++];
		buff = buff->next;
	}
	return (str);
}

int				ft_ncount_occ(char const *s, char c, int n)
{
	int occ;
	int i;

	occ = 0;
	i = 0;
	while (*s && i++ < n)
	{
		if (*s == c)
			occ++;
		s++;
	}
	return (occ);
}