/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albanbotier <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:55:21 by albanboti         #+#    #+#             */
/*   Updated: 2020/06/12 17:29:34 by albanboti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

size_t		ft_strspn(const char *s, const char *accept)
{
	const char	*tmp;
	size_t		i;

	i = 0;
	while (s[i])
	{
		tmp = accept;
		while (*tmp != s[i])
			if (!*tmp++)
				return (i);
		i++;
	}
	return (i);
}

size_t		ft_strcspn(const char *s, const char *reject)
{
	const char	*tmp;
	size_t		i;

	i = 0;
	while (s[i])
	{
		tmp = reject;
		while (*tmp)
			if (*tmp++ == s[i])
				return (i);
		i++;
	}
	return (i);
}

char		*ft_strndup(const char *s, size_t len)
{
	char	*new;
	size_t	i;

	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

size_t		ft_strclen(char const *s, char c)
{
	size_t i;

	i = 0;
	if (s)
		while (s[i] && s[i] != c)
			i++;
	return (i);
}

unsigned	swap_bytes4(unsigned bytes)
{
	bytes = ((bytes & 0xffU << 24) >> 24) | ((bytes & 0xff << 16) >> 8)
		| ((bytes & 0xff << 8) << 8) | ((bytes & 0xff) << 24);
	return (bytes);
}
