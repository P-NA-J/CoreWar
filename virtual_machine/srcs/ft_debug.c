#include "../includes/debug.h"
#include "../includes/struct.h"
#include "../includes/tab.h"
#include "../includes/op.h"
#define MASK_32 0b10000000000000000000000000000000

void	ft_debug_instruction(t_process *process, t_vm *vm)
{
	int	i = 0;
	printf("[ %s ] ", g_tab_instruction[process->opcode].name);
	fflush(stdout);
	while (i < g_tab_instruction[process->opcode].nb_param)
	{
		if (vm->param[i][1] == REG_BIT)
		{
			printf("r");
			fflush(stdout);
		}
		if (vm->param[i][1] == IND_BIT ||
		(vm->param[i][1] == DIR_BIT &&
		g_tab_instruction[process->opcode].dir_size == 2))
		{
			printf("%hd ", (short)vm->param[i][0]);
			fflush(stdout);
		}
		else
		{
			printf("%d ", vm->param[i][0]);
			fflush(stdout);
		}
		i += 1;
	}
	printf("\n");
	fflush(stdout);
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
		{
			printf("1");
			fflush(stdout);
		}
		else
		{
			printf("0");
			fflush(stdout);
		}
		mask >>= 1;
		j += 1;
		if ((j % 8) == 0)
		{
			printf(" ");
			fflush(stdout);
		}
	}
	printf("\n");
}

void	ft_debug_one_param(unsigned int param[2])
{
	if (param[1] == DIR_BIT)
		printf("DIRECT   [%d].\n", param[0]);
	else if (param[1] == IND_BIT)
		printf("INDIRECT [%d].\n", param[0]);
	else if (param[1] == REG_BIT)
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
	printf("cycle = %zu\n", vm->cycle);
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
	printf("Processus N°%zu\n", process->no);
	printf("PC : %zu\n", process->pc);
	printf("cycle_last_live : %zu\n", process->cycle_last_live);
	printf("carry : %d\n", process->carry);
	printf("opcode : %d\n", process->opcode);
	printf("[%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d]\n",
	process->registre[0], process->registre[1], process->registre[2],process->registre[3],
	process->registre[4], process->registre[5], process->registre[6],process->registre[7],
	process->registre[8], process->registre[9], process->registre[10],process->registre[11],
	process->registre[12], process->registre[13], process->registre[14],process->registre[15]);
	printf("--------------------------------\n");
}

void	ft_debug_processus_list(t_process **process_list, const int len)
{
	int	i;

	i = 0;
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
	while (i < CYCLE_WAIT_MAX)
	{
		if (tab[i] != NULL)
		{
			tmp = tab[i];
			printf("i = %zu\n", i);
			while (tmp != NULL)
			{
				ft_debug_processus(tmp);
				tmp = tmp->next;
			}
		}
		i += 1;
	}
}