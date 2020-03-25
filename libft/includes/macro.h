/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:00:13 by pauljull          #+#    #+#             */
/*   Updated: 2020/03/25 18:49:32 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTMACRO_H

# define LIBFTMACRO_H
# define PLUS_FLAG (1 << 0)
# define MINUS_FLAG (1 << 1)
# define SPACE_FLAG (1 << 2)
# define SHARP_FLAG (1 << 3)
# define ZERO_FLAG (1 << 4)
# define H_FLAG (1 << 5)
# define HH_FLAG (1 << 6)
# define MINL_FLAG (1 << 7)
# define MINLL_FLAG (1 << 8)
# define MAJL_FLAG (1 << 9)
# define C_FLAG (1 << 10)
# define S_FLAG (1 << 11)
# define P_FLAG (1 << 12)
# define D_FLAG (1 << 13)
# define I_FLAG (1 << 14)
# define O_FLAG (1 << 15)
# define U_FLAG (1 << 16)
# define X_FLAG (1 << 17)
# define BIGX_FLAG (1 << 18)
# define F_FLAG (1 << 19)
# define NB_AUTH_C 29
# define NB_OPT 5
# define NB_SIZE 5
# define NB_CONV 10
# define TRUE 1
# define FALSE 0
# define UNCHANGED -1
# define BUFF_SIZE 100
# define PRECISION 0
# define LMC 1
# define MAX(a,b) (a > b ? a : b)
# define MIN(a,b) (a < b ? a : b)
#endif
