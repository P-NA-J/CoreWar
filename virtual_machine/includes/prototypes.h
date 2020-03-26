/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:29:36 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 20:33:03 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H

#define PROTOTYPES_H
#include "./struct.h"

/*
** Dump
*/

void	ft_dump(const unsigned char vm[MEM_SIZE]);

/*
** Parsing
*/

int		ft_get_pos_player(t_args *filecor);
int		ft_print_intro(t_player player[4]);
int		ft_check_int(char *nombr);
int		ft_usage(int usage);
int		ft_free_filecor(t_args *filecor);
int		ft_get_options(int index, char **args, t_option *option);
int		ft_insertion_vm(t_args *filecor,
						unsigned char vm[MEM_SIZE], t_player *player);
int		ft_parse(int nb_args, char **args, t_vm *vm);
int		ft_free_filecor(t_args *filecor);
int		ft_get_options(const int nb_args, char **args, t_option *option);

/*
** Truc de paul : Bidon...
*/


t_process	*ft_create_processus(int nb_player, size_t ocp, unsigned char opcode);
void		ft_add_process(t_process *tab[1024], t_process *process);
int			ft_create_processus_list(int nb_player, t_process *tab[1024], t_vm *vm);
void		ft_create_vm(t_vm *vm_struct);
void		ft_move_pc(t_process *process, int value);
void		ft_check_loading_processus(t_vm *vm, t_process *process, t_process *tab[1024], size_t cycle);
int			ft_get_param_type(t_process *process, t_vm *vm);
void		ft_exec_cycle(t_vm *vm, t_process *tab[1024], size_t cycle);
int			ft_error(void);
void		ft_reset_begin_process_list(t_process *process_list);
t_process	*ft_process_move(t_process *process, t_process *tab[1024], int cycle, int cycle_to_add);
void		ft_check(t_vm *vm, t_process *tab[CYCLE_WAIT_MAX]);
void	ft_rm_processus(t_vm *vm, t_process *tab, t_process *process);
t_process	*ft_cpy_processus(t_process *processus);
void		ft_add_process_list(t_vm *vm, t_process *process);
int		ft_recover_value_param(uint8_t vm[MEM_SIZE], uint32_t param[2], t_process *process);
int		ft_get_value_ram(uint8_t vm[4], int	len);
void	ft_convert_to_char(t_vm *vm, int reg, int pos);
int		ft_value_from_address(int pc, int indirect, t_vm *vm);
uint32_t		ft_convert_to_int(unsigned char tab[4]);

/*
**	Prototypes des fonctions pour les instructions ASM.
*/

void		ft_add(t_process *process, t_vm *vm);
void		ft_aff(t_process *process, t_vm *vm);
void		ft_and(t_process *process, t_vm *vm);
void		ft_fork(t_process *process, t_vm *vm);
void		ft_ld(t_process *process, t_vm *vm);
void		ft_ldi(t_process *process, t_vm *vm);
void		ft_lfork(t_process *process, t_vm *vm);
void		ft_live(t_process *process, t_vm *vm);
void		ft_lld(t_process *process, t_vm *vm);
void		ft_lldi(t_process *process, t_vm *vm);
void		ft_or(t_process *process, t_vm *vm);
void		ft_st(t_process *process, t_vm *vm);
void		ft_sti(t_process *process, t_vm *vm);
void		ft_sub(t_process *process, t_vm *vm);
void		ft_xor(t_process *process, t_vm *vm);
void		ft_zjmp(t_process *process, t_vm *vm);

#endif
