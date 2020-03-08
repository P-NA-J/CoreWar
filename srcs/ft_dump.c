#include "../includes/op.h"
#include "../../lem_in/libft/includes/libft.h"
#include "struct.h"

/*
** Dump : Fonction qui parcours la VM et Convertie/Print chaque Char en Hexa 
*/

void	ft_dump(const unsigned char vm[MEM_SIZE])
{
	int		len;

	len = 0;
	while (len < MEM_SIZE)
	{
		if (len % 64 == 0)
			ft_printf("0x%.4x : ", len);
		if ((len + 1) % 64 == 0)
			ft_printf("%.2x\n", vm[len]);
		else
			ft_printf("%.2x ", vm[len]);
		len++;
	}
	return ;
}

int		main(void)
{
	unsigned char	vm[MEM_SIZE];

	bzero(vm, MEM_SIZE);
	vm[0] = 4;
	vm[1] = 58;
	vm[2] = 144;
	vm[3] = 3;
	vm[4] = 2;
	ft_dump(vm);
}
