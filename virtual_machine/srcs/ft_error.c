/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:08:59 by pauljull          #+#    #+#             */
/*   Updated: 2020/06/16 16:31:11 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/op.h"
#include "../includes/prototypes.h"
#include "../../libft/includes/prototypes.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	g_tab[8][128] =
{
	"Can't read source file ",
	"Too many champions\n",
	"has an invalid header\n",
	"is too small to be a champion\n",
	"has too large a code",
	"is too small to be a champion\n",
	"-n number is too low or to hight or is double\n",
	"has a code size that differ from what its header says\n"
};

void	ft_print_error(int usage, char *source, int length)
{
	if (usage == 2 || usage == 3 || usage == 4 || usage == 5 || usage == 7)
	{
		ft_putstr_fd("Error: File ", 2);
		ft_putstr_fd(source, 2);
		ft_putchar_fd(' ', 2);
	}
	ft_putstr_fd(g_tab[usage], 2);
	if (usage == 4)
	{
		ft_putstr_fd(" (", 2);
		if (length > 4096)
			ft_putchar_fd('+', 2);
		ft_putnbr_fd(length, 2);
		ft_putendl_fd(" bytes > 682 bytes)", 2);
	}
	if (usage == 0)
		ft_putendl_fd(source, 2);
}

int		ft_usage(int usage, char *source, int length)
{
	if (usage == 0)
	{
		ft_putstr("| Usage: ./corewar [-d N -v N | -n]");
		ft_putstr(" <champion1.cor> <...> |\n");
		ft_putstr(" ####  VERBOSE\n");
		ft_putstr("-v N	: Verbosity levels (0 : Show only essentials)\n\n");
		ft_putstr("####  VISUALISATEUR ");
		ft_putstr("\n-visu   : Bonus viewer cant");
		ft_putstr(" print memory with colors...\n\n");
		ft_putstr("####  PLAYER_POSITION\n");
		ft_putstr("-n N    : Choice the positionement of the players\n\n");
		ft_putstr("####  DUMP\n");
		ft_putstr("-dump N : Print the memory after N cycle\n\n");
	}
	else
		ft_print_error(usage - 1, source, length);
	return (EXIT_FAILURE);
}
