#include "../includes/debug.h"

void	ft_debug_processus(t_process *processus)
{
	printf("process->registre[%d] = %d\n",0, processus->registre[0]);
	printf("process->registre[%d] = %d\n",1, processus->registre[1]);
	printf("process->registre[%d] = %d\n",2, processus->registre[2]);
	printf("process->registre[%d] = %d\n",3, processus->registre[3]);
	printf("process->registre[%d] = %d\n",4, processus->registre[4]);
	printf("process->registre[%d] = %d\n",5, processus->registre[5]);
	printf("process->registre[%d] = %d\n",6, processus->registre[6]);
	printf("process->registre[%d] = %d\n",7, processus->registre[7]);
	printf("process->registre[%d] = %d\n",8, processus->registre[8]);
	printf("process->registre[%d] = %d\n",9, processus->registre[9]);
	printf("process->registre[%d] = %d\n",10, processus->registre[10]);
	printf("process->registre[%d] = %d\n",11, processus->registre[11]);
	printf("process->registre[%d] = %d\n",12, processus->registre[12]);
	printf("process->registre[%d] = %d\n",13, processus->registre[13]);
	printf("process->registre[%d] = %d\n",14, processus->registre[14]);
	printf("process->registre[%d] = %d\n",15, processus->registre[15]);
	printf("process->carry =        %hhd\n", processus->carry);
	printf("process->pc  =          %zu\n", processus->pc);
	printf("process->cycle_left =   %zu\n", processus->cycle_left);
	printf("process->next =         %p\n", processus->next);
	printf("process =               %p\n", processus);
	printf("\n--------------------------------------------------------------------\n\n");
}

void	ft_debug_processus_list(t_process *processus_list)
{
	while (processus_list != NULL)
	{
		ft_debug_processus(processus_list);
		processus_list = processus_list->next;
	}
}