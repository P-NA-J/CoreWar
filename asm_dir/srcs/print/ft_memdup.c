/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albanbotier <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 19:19:54 by albanboti         #+#    #+#             */
/*   Updated: 2020/06/12 17:49:33 by albanboti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memdup(const void *src, size_t n)
{
	void				*new;
	unsigned char		*ds;
	unsigned char const	*sr;

	if (!src || !(new = malloc(n)))
		return (NULL);
	ds = (unsigned char *)new;
	sr = (unsigned char const *)src;
	while (n--)
		*ds++ = *sr++;
	return (new);
}
