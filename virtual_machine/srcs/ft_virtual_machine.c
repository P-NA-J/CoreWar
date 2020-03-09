/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_virtual_machine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:27:38 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/08 15:35:21 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/virtual_machine.h"
#include "../includes/struct.h"

void	ft_create_vm(t_vm *vm_struct)
{
	vm_struct->player_list = NULL;
	vm_struct->param[0][0] = 0;
	vm_struct->param[0][1] = 0;
	vm_struct->param[1][0] = 0;
	vm_struct->param[1][1] = 0;
	vm_struct->param[2][0] = 0;
	vm_struct->param[2][1] = 0;

	bzero(vm_struct->vm, MEM_SIZE);
	vm_struct->vm[0] = 0;
	vm_struct->vm[1] = 84;
	vm_struct->vm[2] = 2;
	vm_struct->vm[3] = 3;
	vm_struct->vm[4] = 4;
	vm_struct->vm[5] = 1;
	vm_struct->vm[6] = 144;
	vm_struct->vm[7] = 0;
	vm_struct->vm[8] = 0;
	vm_struct->vm[9] = 0;
	vm_struct->vm[10] = 54;
	vm_struct->vm[11] = 2;
	
	vm_struct->vm[2048] = 0;
	vm_struct->vm[2049] = 84;
	vm_struct->vm[2050] = 2;
	vm_struct->vm[2051] = 3;
	vm_struct->vm[2052] = 4;
	vm_struct->vm[2053] = 1;
	vm_struct->vm[2054] = 144;
	vm_struct->vm[2055] = 0;
	vm_struct->vm[2056] = 0;
	vm_struct->vm[2057] = 0;
	vm_struct->vm[2058] = 54;
	vm_struct->vm[2059] = 2;

}