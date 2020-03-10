/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:59:55 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/10 21:51:08 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		safe_open(char *av)
{
	int fd; 

	errno = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (FALSE);
	printf("FD\t\t\tOK\n");
	return (fd);
}

/*
**	We only accept .s files -- ε (empty string) as filename not accepted.
*/

int		check_valid_argv(t_asm *env, char *av)
{
	int i;

	i = 0;
	while (av[i])
		i++;
	if (av[i - 2] != '.' || av[i - 1] != 's' || !av[i - 3])
	{
		ft_putstr(FILE_ERROR);
		return (FALSE);
	}
	if ((env->fd = safe_open(av)) == FALSE)
		return (FALSE);
	av[i - 2] = '\0';
	env->file_name = av;
	printf("CHECK_ARGV\t\tOK\n");
	return (TRUE);
}

int		init(t_asm *env, char *av)
{
	if ((check_valid_argv(env, av) == FALSE \
		|| scan(env) == FALSE))
		return (FALSE);
	return (TRUE);
}

int		main(int ac, char **av)
{
	t_asm	env;

	ft_bzero(&env, sizeof(t_asm));
	if (ac != 2 || init(&env, av[1]) == FALSE)
		return (FALSE);
	printf("file_name = %s\n", env.file_name);
	return (0);
}
