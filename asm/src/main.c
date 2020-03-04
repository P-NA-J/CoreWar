/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:59:55 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/04 22:29:34 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		safe_open(char *av)
{
	int fd; 

	if ((fd = open(&av[1], 0, O_RDONLY)) == 0)
		return (FALSE);
	return (fd);
}

int		check_valid_argv(char *av, t_asm *env)
{
	int i;

	i = 0;
	while (av[i])
		i++;
	if (av[i - 2] != '.' || av[i - 1] != 's' || !av[i - 3])
		return (FALSE);
	av[i - 2] = '\0';
	env->file_name = av;
	return (TRUE);
}

int		init(t_asm *env, char *av)
{
	if ((check_valid_argv(av, env) == FALSE \
		|| (env->fd = safe_open(av)) == FALSE))
		return (FALSE);
	return (TRUE);
}

int		main(int ac, char **av)
{
	t_asm	env;

//	ft_bzero(env, sizeof(t_asm));
	if (ac != 2 || init(&env, av[1]) == FALSE)
	{
		printf("Error in input file\n");
//		ft_putstr("Please specify an input file ending with .s");
		return (FALSE);
	}
	printf("file_name = %s\n", env.file_name);
	printf("%d\n", op_tab[0].opcode);
	return (0);
}
