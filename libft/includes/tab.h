/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:02:39 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:49:10 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTTAB_H

# define LIBFTTAB_H

typedef void				(*t_tab)(t_buffer *, t_flag *);

# ifdef GLOBAL_H

t_tab	g_f_tab[127] =
{
	['%'] = ft_percent_conversion,
	['X'] = ft_bigx_conversion,
	['c'] = ft_c_conversion,
	['d'] = ft_d_conversion,
	['i'] = ft_d_conversion,
	['o'] = ft_o_conversion,
	['p'] = ft_p_conversion,
	['s'] = ft_s_conversion,
	['u'] = ft_u_conversion,
	['x'] = ft_x_conversion,
};

char	g_auth_c_tab[NB_AUTH_C] =
{
	'+',
	'-',
	' ',
	'#',
	'0',
	'l',
	'h',
	'L',
	'c',
	's',
	'p',
	'd',
	'i',
	'o',
	'u',
	'x',
	'X',
	'%'
};

int		g_bin[127] =
{
	['#'] = SHARP_FLAG,
	['0'] = ZERO_FLAG,
	['+'] = PLUS_FLAG,
	['-'] = MINUS_FLAG,
	[' '] = SPACE_FLAG,
	['h'] = H_FLAG,
	['l'] = MINL_FLAG,
	['L'] = MAJL_FLAG,
	['j'] = MINLL_FLAG,
	['z'] = MINL_FLAG
};

char	g_opt_auth[NB_OPT] =
{
	'#',
	'+',
	'-',
	'0',
	' '
};

char	g_size_auth[NB_SIZE] =
{
	'h',
	'l',
	'L',
	'j',
	'z'
};

char	g_conv_auth[NB_CONV] =
{
	'c',
	's',
	'p',
	'd',
	'i',
	'o',
	'u',
	'x',
	'X',
	'%'
};
# endif

extern char	*g_m_tab[64];
extern t_tab	g_f_tab[127];
extern char	g_auth_c_tab[NB_AUTH_C];
extern int	g_bin[127];
extern char	g_opt_auth[NB_OPT];
extern char	g_size_auth[NB_SIZE];
extern char	g_conv_auth[NB_CONV];
#endif
