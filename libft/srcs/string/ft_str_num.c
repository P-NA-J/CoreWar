/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 11:44:48 by paul              #+#    #+#             */
/*   Updated: 2020/06/13 13:41:08 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prototypes.h"
#include <stdbool.h>

bool	ft_str_num(char *s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (ft_isdigit(s[i++]) == false)
			return (false);
	}
	return (true);
}
