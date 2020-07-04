/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:03:02 by jrouchon          #+#    #+#             */
/*   Updated: 2020/07/04 19:24:29 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

BOOL	ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	if (!s1 || !s2)
		return (FALSE);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (((unsigned char)s1[i] - (unsigned char)s2[i]) == 0 ? TRUE : FALSE);
}
