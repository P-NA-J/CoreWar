#include "../includes/debug.h"
#include "../includes/struct.h"
#include "../includes/tab.h"
#include "../includes/op.h"
#include "../../libft/includes/prototypes.h"
#include <stdlib.h>
#include <stdio.h>
#define MASK_32 0b10000000000000000000000000000000

void	ft_print_param(int param, int type, int opcode)
{
	if (type == T_REG)
		ft_printf("r%d", param);
	if (type == T_IND ||
		(type == T_DIR &&
		g_tab_instruction[opcode].dir_size == 2))
		ft_printf("%hd", param);
	else
		ft_printf("%d", param);
}

void	ft_debug_instruction(t_process *process, t_vm *vm)
{
	int	i = 0;
	ft_printf("P%4d | %s ", process->no, g_tab_instruction[process->opcode].name);
	while (i < g_tab_instruction[process->opcode].nb_param)
	{
		if (vm->param[i][1] == T_REG)
			ft_printf("r");
		if (vm->param[i][1] == T_IND ||
		(vm->param[i][1] == T_DIR &&
		g_tab_instruction[process->opcode].dir_size == 2))
			ft_printf("%d ", vm->param[i][0]);
		else
			ft_printf("%d ", vm->param[i][0]);
		i += 1;
	}
}

void	ft_print_bit_32(int i)
{
	unsigned int	mask;
	int	j;

	mask = MASK_32;
	j = 0;
	while (j < 32)
	{
		if (mask & i)
			ft_printf("1");
		else
			ft_printf("0");
		mask >>= 1;
		j += 1;
		if ((j % 8) == 0)
			ft_printf(" ");
	}
	ft_printf("\n");
}

void	ft_print_bit_16(unsigned short c)
{
	unsigned short	mask;

	mask = 0b1000000000000000;
	while (mask != 0)
	{
		if (mask & c)
			ft_printf("1");
		else
			ft_printf("0");
		mask >>= 1;
		if (mask == 0b10000000)
			ft_printf(" ");
	}
	ft_printf("\n");
}

void	ft_print_bit_8(unsigned char c)
{
	unsigned char	mask;

	mask = 0b10000000;
	while (mask != 0)
	{
		if (mask & c)
			ft_printf("1");
		else
			ft_printf("0");
		mask >>= 1;
	}
	ft_printf("\n");
}

void	ft_debug_one_param(unsigned int param[2])
{
	if (param[1] == T_DIR)
		printf("DIRECT   [%d].\n", param[0]);
	else if (param[1] == T_IND)
		printf("INDIRECT [%d].\n", param[0]);
	else if (param[1] == T_REG)
		printf("REGISTRE [%d].\n", param[0]);
	else
		printf("Pas de paramètre.\n");
}

void	ft_debug_param(unsigned int param[3][2])
{
	printf("----------- PARAM ----------\n");
	ft_debug_one_param(param[0]);
	ft_debug_one_param(param[1]);
	ft_debug_one_param(param[2]);
	printf("----------------------------\n\n");
}

void	ft_debug_one_player(t_player player)
{
	printf("magic = |%s|\n", player.magic);
	printf("name = |%s|\n", player.name);
	printf("comment = |%s|\n", player.comment);
	printf("player_size = |%s|\n", player.size);
	printf("index_player = %d\n", player.index_player);
	printf("nb_live = %u\n\n", player.nb_live);
}

void	ft_debug_player_list(t_player player_list[4])
{
	printf("----------- PLAYER_LIST ----------\n");
	ft_debug_one_player(player_list[0]);
	ft_debug_one_player(player_list[1]);
	ft_debug_one_player(player_list[2]);
	ft_debug_one_player(player_list[3]);
	printf("----------------------------------\n\n");
}

void	ft_debug_opt(t_option opt)
{
	printf("----------- OPT ----------\n");
	printf("VISU : %d\n", opt.visu);
	printf("v[0] = %d v[1] = %d\n", opt.v[0], opt.v[1]);
	printf("d[0] = %d d[1] = %d\n", opt.d[0], opt.d[1]);
	printf("pad[0] = %d pad[1] = %d\n", opt.pad[0], opt.pad[1]);
	printf("--------------------------\n\n");
}

void	ft_debug_vm(t_vm *vm)
{
	ft_dump(vm->vm);
	ft_debug_player_list(vm->player_list);
	ft_debug_opt(vm->opt);
	printf("ADDR(process_list) = %p\n", vm->process_list);
	ft_debug_param(vm->param);
	printf("cycle = %d\n", vm->cycle);
	printf("nb_process = %zu\n", vm->nb_process);
	printf("cycles_to_die = %d\n", vm->cycles_to_die);
	printf("nb_live = %d\n", vm->nb_live);
	printf("no_decrease_check = %d\n", vm->no_decrease_check);
	printf("nb_champs_left = %d\n", vm->nb_champs_left);
	printf("period[0] = %d period[1] = %d\n", vm->period[0], vm->period[1]);
	printf("nb_player = %d\n", vm->nb_player);
}

void	ft_debug_processus(t_process *process)
{
	ft_printf("Processus N°%zu\n", process->no);
	ft_printf("PC : %x\n", process->pc);
	ft_printf("cycle_last_live : %zu\n", process->cycle_last_live);
	ft_printf("carry : %d\n", process->carry);
	ft_printf("tab_places : %zu\n", process->tab_places);
	ft_printf("opcode : %d\n", process->opcode);
	if (process->opcode == 255)
		ft_printf("operation : ERROR\n");
	else if (process->opcode >= 0 && process->opcode < 16)
		ft_printf("operation : %s\n", g_tab_instruction[process->opcode].name);
	if (process->next == NULL)
		ft_printf("NEXT : %p\n", process->next);
	else
		ft_printf("NEXT : Processus N°%zu\n", process->next->no);
	ft_printf("[%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d]\n\n",
	process->registre[0], process->registre[1], process->registre[2],process->registre[3],
	process->registre[4], process->registre[5], process->registre[6],process->registre[7],
	process->registre[8], process->registre[9], process->registre[10],process->registre[11],
	process->registre[12], process->registre[13], process->registre[14],process->registre[15]);
}

void	ft_debug_processus_list(t_process **process_list, const int len)
{
	int	i;

	i = 0;
	printf("___________________LIST_PROCESS___________________\n\n");
	while (i < len)
	{
		if (process_list[i] == NULL)
			printf("NULL\n");
		else
			ft_debug_processus(process_list[i]);
		i += 1;
	}
}

void	ft_debug_tab_process(t_process *tab[CYCLE_WAIT_MAX])
{
	size_t	i;
	t_process	*tmp;

	tmp = NULL;
	i = 0;
	ft_printf("___________________TAB_PROCESS____________________\n\n");
	while (i < 1024)
	{
		if (tab[i] != NULL)
		{
			tmp = tab[i];
			ft_printf(_GREEN "i = %zu\n" _RESET, i);
			while (tmp != NULL)
			{
				ft_debug_processus(tmp);
				tmp = tmp->next;
			}
			ft_printf("---------------------------------------------\n");
		}
		i += 1;
	}
}

void	ft_debug_critical_error(t_vm *vm)
{
	size_t	i;

	i = 0;
	while (i < vm->nb_process)
	{
		if (vm->process_list[i]->next)
		{
			if (vm->process_list[i]->no == vm->process_list[i]->next->no)
			{
				printf(_RED "Processus N°%zu\n" _RESET, vm->process_list[i]->no);
				printf(_RED "/!\\ CRITICAL ERROR /!\\" _RESET);
				exit(0);
			}
		}
		i += 1;
	}
}