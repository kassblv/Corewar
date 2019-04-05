/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 23:14:28 by kaboujna          #+#    #+#             */
/*   Updated: 2019/03/29 23:14:32 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"

typedef	struct		s_op
{
	char			*name;
	int				nbr_arg;
	char			arg[3];
	int				opcode;
	char			codage_octal;
	int				dir_size;
	int				cycles;
	int				carry;
}					t_op;

t_op				*struct_tab(void);

#endif
