/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albanbotier <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 19:39:59 by albanboti         #+#    #+#             */
/*   Updated: 2020/06/12 17:49:57 by albanboti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memjoin(void const *s1, void const *s2, size_t n1, size_t n2)
{
	void				*new;
	unsigned char const	*src;
	unsigned char		*dest;

	src = (const unsigned char *)s1;
	if (!(new = malloc(n1 + n2)))
		return (NULL);
	dest = (unsigned char *)new;
	while (n1--)
		*dest++ = *src++;
	src = (const unsigned char *)s2;
	while (n2--)
		*dest++ = *src++;
	return (new);
}
