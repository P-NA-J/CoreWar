/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albanbotier <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 01:28:19 by albanboti         #+#    #+#             */
/*   Updated: 2020/06/13 14:25:19 by albanboti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <unistd.h>

static void	put_strtab(char *s, char replace, int n)
{
	char	buff[100];
	int		i;
	int		j;
	char	*t;

	t = s;
	while (*s && (s - t < n || n == -1))
	{
		i = 0;
		while (i + TAB_SIZE < 100 && *s && (s - t < n || n == -1))
		{
			if (*s == '\t')
			{
				j = 0;
				while (j++ < TAB_SIZE)
					buff[i++] = replace ? replace : ' ';
			}
			else
				buff[i++] = !replace ? *s : replace;
			s++;
		}
		write(2, buff, i);
	}
}

int			check_end_str(t_env *e, char *s, int cmd, char c)
{
	char	chr[sizeof(SPACES) + 1];
	int		i;

	i = sizeof(SPACES) - 1;
	chr[i] = c;
	chr[i + 1] = '\0';
	while (i--)
		chr[i] = SPACES[i];
	s = s + ft_strspn(s, SPACES);
	if (*s == c)
		return (1);
	if (unexpected_expression(e, s, cmd) == -1)
		return (-1);
	s = s + ft_strcspn(s, chr);
	while (*(s = s + ft_strspn(s, SPACES)) != c)
	{
		if (unexpected_expression(e, s, cmd) == -1)
			return (-1);
		s = s + ft_strcspn(s, chr);
	}
	return (0);
}

void		err_pointer(int tty, char *s, char *end)
{
	int space;

	if (tty)
		ft_dprintf(2, "{R}");
	put_strtab(s, 0, -1);
	space = end - s + ft_ncount_occ(s, '\t', end - s) * (TAB_SIZE - 1);
	if (s != end)
		ft_dprintf(2, "\n%*c", space, ' ');
	else
		ft_dprintf(2, "\n");
	if (tty)
		ft_dprintf(2, GREEN_CURS"^{R}");
	else
		ft_dprintf(2, "^");
}

void		err_wave(int tty, char *s, int n)
{
	if (tty)
		ft_dprintf(2, GREEN_CURS);
	put_strtab(s, '~', n);
	if (tty)
		ft_dprintf(2, "{R}");
}
