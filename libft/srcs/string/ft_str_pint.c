/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_pint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 11:43:28 by paul              #+#    #+#             */
/*   Updated: 2020/06/13 13:41:36 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prototypes.h"
#include <stdbool.h>

static bool	ft_is_inf_int_max(char *s, int len)
{
	int		i;
	char	*ref_s;

	ref_s = "2147483647";
	i = 0;
	while (i < len)
	{
		if (s[i] >= '0' && s[i] < ref_s[i])
			return (true);
		else if (s[i] == ref_s[i])
			i += 1;
		else
			return (false);
	}
	return (true);
}

bool		ft_str_pint(char *s)
{
	int		len;

	len = ft_strlen(s);
	if (len > 10)
		return (false);
	if (ft_str_num(s, len) == false)
		return (false);
	if (len < 10)
		return (true);
	if (ft_is_inf_int_max(s, len) == false)
		return (false);
	return (true);
}
