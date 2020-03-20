#ifndef DEBUG_H
# define DEBUG_H

# define _RED				"\x1b[31m"
# define _GREEN				"\x1b[32m"
# define _YELLOW			"\x1b[33m"
# define _BLUE				"\x1b[34m"
# define _MAGENTA			"\x1b[35m"
# define _CYAN				"\x1b[36m"
# define _RESET				"\x1b[0m"

#include "./struct.h"

void	ft_debug_processus(t_process *processus);
void	ft_debug_params(unsigned int param[3][2]);
void	ft_debug_instruction(t_process *process, t_vm *vm);
void	ft_print_bit_32(int i);
void	ft_debug_vm(t_vm *vm);
void	ft_debug_processus_list(t_process **process_list, const int len);

#endif