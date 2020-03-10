/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:42:42 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/10 14:59:01 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/tab.h"
#include "../includes/debug.h"

/*
**	Fonction puissance.
*/
int		ft_pow(int a, int n)
{
	if (a == 0)
		return (0);
	if (n == 0)
		return (1);
	return (a * ft_pow(a, n - 1));
}

/*
**	Fonction qui convertit les len-prochain bit en int.
*/

void ft_convert_param(t_vm *vm, int len, int *i_ptr, int j)
{
	int	index;

	index = *i_ptr;
	while (index < len)
	{
		vm->param[j][0] |= vm->vm[index];
//		ft_print_bit_32(vm->param[j][0]);
		if (index < len - 1)
			vm->param[j][0] <<= 8;
		index += 1;
	}
	*i_ptr = index;
}

/*
**	Fonction qui check que la valeur des parametres est valide (i.e que le numero du registre soit bien entre 1 et 16)
*/

int		ft_check_value_param(t_process *process, t_vm *vm)
{
	int	nb_param;
	int	i;

	nb_param = tab_instruction[process->opcode].nb_param;
	i = 0;
	while (i < nb_param)
	{
		if (vm->param[i][1] == REG_CODE && (vm->param[i][1] <= 0 || vm->param[i][1] >= 17))
			return (ERROR);
		i += 1;
	}
	return (TRUE);
}

/*
**	Fonction qui va stocker la valeur des parametres.
*/

int		ft_get_param_value(t_process *process, t_vm *vm)
{
	int	i;
	int	j;
	int	nb_param;

	nb_param = tab_instruction[process->opcode].nb_param;
	i = process->pc + 2;
	j = 0;
	while (j < nb_param)
	{
		if (vm->param[j][1] == REG_BIT)
		{
			vm->param[j][0] = vm->vm[i++];
			printf("Le parametre %d est un REGISTRE et vaut %d.\n", j, vm->param[j][0]);
		}
		else if (vm->param[j][1] == IND_BIT)
		{
			ft_convert_param(vm, i + 2, &i, j);
			printf("Le parametre %d est un INDIRECT et vaut %d.\n", j, vm->param[j][0]);
		}
		else if (vm->param[j][1] == DIR_BIT)
		{
			ft_convert_param(vm, i + tab_instruction[process->opcode].dir_size, &i, j);
			printf("Le parametre %d est un DIRECT et vaut %d.\n", j, vm->param[j][0]);
		}
		j += 1;
	}
	return (ft_check_value_param(process, vm));
}

/*
**	Fonction qui va stocker les types des parametres.
*/

int		ft_get_param_type(t_process *process, t_vm *vm)
{
	int	nb_param;
	int	i;
	unsigned char	ocp;
	unsigned char	mask;

	ocp = vm->vm[process->pc + 1];
	nb_param = tab_instruction[process->opcode].nb_param;
	i = 0;
	while (i < nb_param)
	{
		mask = ocp & IND_BIT;
		if (mask == REG_BIT)
			vm->param[i][1] = REG_BIT;
		else if (mask == IND_BIT)
			vm->param[i][1] = IND_BIT;
		else if (mask == DIR_BIT)
			vm->param[i][1] = DIR_BIT;
//		else
//			return (ft_bad_ocp_parsing(ocp, process->opcode));
		ocp <<= 2;
		i += 1;
	}
	return (ft_get_param_value(process, vm));
}