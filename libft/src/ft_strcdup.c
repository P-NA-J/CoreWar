/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 16:34:34 by aboitier          #+#    #+#             */
/*   Updated: 2018/12/29 19:02:00 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcdup(const char *s, char c)
{
	size_t		i;
	size_t		j;
	char		*new;

	i = 0;
	j = 0;
	while (s[i] != c && s[i])
		i++;
	if (!(new = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		new[j] = s[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}
