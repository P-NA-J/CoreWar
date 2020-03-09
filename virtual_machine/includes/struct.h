/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:13:48 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/08 14:12:34 by pauljull         ###   ########.fr       */
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

typedef struct			 s_process
{
	struct s_process	*next;
	struct s_process	*begin;
	size_t				pc;
	size_t				cycle_left;
	int					registre[16];
	char				carry;
	unsigned char		opcode;
	char				padding[6];
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
	int					param[3][2];
}						t_vm;

typedef struct			s_instruction
{
	void				(*ft_instruction)(t_process *process, t_vm *vm);
	size_t				cycle_to_exec;
	unsigned char		nb_param;
	unsigned char		dir_size;
	char				padding[6];
}						t_instruction;

#endif