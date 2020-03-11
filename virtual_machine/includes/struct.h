/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:13:48 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/11 15:23:38 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

# include "./virtual_machine.h"

typedef struct			s_option
{
	int					d[2];
	int					v[2];
}						t_option;

typedef struct			s_args
{
	int					player_nb;
	char				**champ;
}						t_args;

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
	size_t				no;
	size_t				pc;
	size_t				cycle_left;
	unsigned int		registre[16];
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
	unsigned int		param[3][2];
	size_t				nb_process;
}						t_vm;

typedef struct			s_instruction
{
	void				(*ft_instruction)(t_process *process, t_vm *vm);
	size_t				cycle_to_exec;
	unsigned char		nb_param;
	unsigned char		dir_size;
	int					param_type[3];
	char				padding[6];
}						t_instruction;

#endif