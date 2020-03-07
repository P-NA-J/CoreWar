#include "../includes/op.h"

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
			printf("0x%.4x : ", len);
		if ((len + 1) % 64 == 0)
			printf("%.2x\n", vm[len]);
		else
			printf("%.2x ", vm[len]);
		len++;
	}
	return ;
}
