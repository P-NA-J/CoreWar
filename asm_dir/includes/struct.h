/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:01:45 by pauljull          #+#    #+#             */
/*   Updated: 2020/06/12 17:21:27 by albanboti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSTRUCT_H

# define LIBFTSTRUCT_H

# include <stdlib.h>
# include <stdarg.h>
# include "macro.h"

typedef struct		s_buffer
{
	int				count;
	int				buff_i;
	char			buffer[BUFF_SIZE + 1];
}					t_buffer;

typedef struct		s_base
{
	char			*base_t;
	int				base_l;
}					t_base;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

#endif
