/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:41:59 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/04 22:11:29 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>

# include "tokens.h"
# include "op.h"

# define TRUE 				1
# define FALSE 				0
# define MAX_INSTRUCTIONS	16

typedef struct 	s_asm
{
	int 		fd;
	char		*file_name;

}				t_asm;
	
int				safe_open(char *av);

#endif
