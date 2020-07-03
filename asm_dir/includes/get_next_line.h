/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albanbotier <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 22:42:29 by albanboti         #+#    #+#             */
/*   Updated: 2020/06/12 17:46:45 by albanboti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>

# define BS_GNL 100
# define MAX_SIZE_STATIC 10000

typedef struct		s_gnl
{
	char			*str;
	int				fd;
	size_t			len;
	struct s_gnl	*next;
}					t_gnl;

#endif
