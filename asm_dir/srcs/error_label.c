/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albanbotier <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 18:57:51 by albanboti         #+#    #+#             */
/*   Updated: 2020/06/13 14:24:05 by albanboti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	redefine_label(t_env *e, char *error, int y)
{
	t_line *line;

	line = e->file->last;
	++e->file->warning;
	ft_dprintf(2, "%s:%d:%d: warning: ",
		e->file->name, line->y, error - line->s + 1);
	ft_dprintf(2, "redefinition of label '%.*s' not allowed",
		ft_strchr(error, LABEL_CHAR) - error, error);
	ft_dprintf(2, " (previous definition line %d)\n", y);
	err_pointer(e->tty2, line->s, error);
	ft_dprintf(2, "\n");
}

void	undefined_label(t_env *e, t_call *call, int tt)
{
	int len;

	++e->file->error;
	len = ft_strspn(call->s, LABEL_CHARS);
	ft_dprintf(2, "%s:%d:%d: error: ",
		e->file->name, call->line->y, call->s - call->line->s);
	ft_dprintf(2, "label '%.*s' is undefined ", len, call->s);
	if (tt)
		ft_dprintf(2, "(%d other%s", tt, tt > 1 ? "s)" : ")");
	ft_dprintf(2, "\n");
	err_pointer(e->tty2, call->line->s, call->s);
	ft_dprintf(2, "\n");
	if (tt)
	{
		ft_dprintf(2, "%s:%d:%d: note: ",
			e->file->name, call->line->y, call->s - call->line->s);
		ft_dprintf(2, "undefined label reported only once\n");
	}
	if (e->tty2)
		ft_dprintf(2, "{R}");
}
