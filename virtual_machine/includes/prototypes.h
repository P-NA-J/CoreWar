/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:29:36 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/05 17:28:06 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H

#define PROTOTYPES_H

t_process	*ft_create_processus(int nb_player, size_t ocp);
void		ft_add_process(t_process **head, t_process *process);
int			ft_create_processus_list(int nb_player, t_process **process_list);
void		ft_create_vm(unsigned char vm[MEM_SIZE]);

/*
**	Prototypes des fonctions pour les instructions ASM.
*/

void		ft_ld(t_process *process, t_vm *vm);
void		ft_add(t_process *process, t_vm *vm);
#endif