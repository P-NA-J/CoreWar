/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albanbotier <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 18:28:05 by albanboti         #+#    #+#             */
/*   Updated: 2020/06/13 14:03:59 by albanboti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <errno.h>
#include <stdlib.h>

void	help(t_env *e)
{
	ft_printf("Usage: %s [options] file ...\n", e->exname);
	ft_printf("Options:\n\
	-d, --disassemble: from bytecode to corewar assembly\n\
	-x, --hexadecimal: display bytecode generate from file.s (hexadecimal)\n\
	-b, --binary: display bytecode generate from file.s (binary)\n\
	-l, --long-dump: display entire bytecode \
(-x or -b is needed to be effective)\n\
	-o, --output <output>: write output to <file>\n\
	--color[=WHEN]: specify when to display in color \
(ex: always, never, auto)\n");
	free_lst_file(e);
	exit(0);
}

int		usage(t_env *e, int err)
{
	if (err == 3)
	{
		ft_dprintf(--err, "%s: error: ", e->exname);
		ft_dprintf(err, "no input files\n");
	}
	ft_dprintf(err, "Usage: %s [-o output] <file.s> ...\n", e->exname);
	ft_dprintf(err, "       %s (-x | -b) [-l] <file.s> ...\n", e->exname);
	ft_dprintf(err, "       %s -d [-o <file>] <file.cor> ...\n", e->exname);
	ft_dprintf(err, "Try `%s (-h | --help)' for more information.\n",
		e->exname);
	return (1);
}

int		error_file(t_env *e, char *error, char *file, unsigned opt)
{
	free_lst_file(e);
	ft_dprintf(2, "%s: error: ", e->exname);
	if (opt & ~0xff)
	{
		if (opt & O_SHORT_ERR)
			ft_dprintf(2, "unknow option - %c\n", *error);
		else if (opt & O_LONG_ERR)
			ft_dprintf(2, "unknow option -- %s\n", error);
		else if (opt & (O_COL_AMBIGUOUS_ERR | O_COL_INVALID_ERR))
		{
			ft_dprintf(2, "%s argument '%s' for '--color'\n",
				opt & O_COL_AMBIGUOUS_ERR ? "ambiguous" : "invalid", error);
			ft_dprintf(2, "Valid arguments are:\n");
			ft_dprintf(2, "  - 'always', 'yes', 'force'\n");
			ft_dprintf(2, "  - 'never', 'no', 'none'\n");
			ft_dprintf(2, "  - 'auto', 'tty', 'if-tty'\n");
		}
		else if (opt & O_INVALID_FILE_ERR)
			ft_dprintf(2, "invalid file '%s'\n", file);
		else
			ft_dprintf(2, "argument to '-o' is missing\n");
	}
	else
		ft_dprintf(2, "%s: '%s'\n", strerror(errno), file);
	return (0);
}