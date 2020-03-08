/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:13:48 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/05 17:13:46 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

# include "./virtual_machine.h"

typedef struct		header_s
{
  unsigned int		magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 1];
}					header_t;

typedef struct s_param
{
	int			p1[2];
	int			p2[2];
	int			p3[2];
}				t_param;

typedef struct			 s_process
{
	struct s_process	*next;
	size_t				ocp;
	size_t				cycle_left;
	int					registre[16];
	char				carry;
	char				tab[7];
}						t_process;

typedef struct			s_player
{
	struct s_player		*next;
	struct s_player		*begin;
	char				*name;
	uint32_t			nb_live;
}						t_player;

typedef struct			s_vm
{
	unsigned char		vm[MEM_SIZE];
	t_player			*player_list;
	t_param				param;
}						t_vm;

#endif