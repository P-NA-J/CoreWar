/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:29:36 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/10 16:22:03 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H

#define PROTOTYPES_H

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