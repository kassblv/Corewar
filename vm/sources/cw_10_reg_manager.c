/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_10_reg_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 02:23:24 by fallouch          #+#    #+#             */
/*   Updated: 2019/03/30 02:23:25 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int				num_at_reg(t_vm vm, int pos, size_t size)
{
	int		n;

	n = 0;
	pos = pos % MEM_SIZE;
	if (pos < 0)
		pos += MEM_SIZE;
	while (size-- > 0)
	{
		n = n << 8;
		n |= vm.reg[pos % MEM_SIZE];
		pos++;
	}
	return (n);
}

void			set_num_at_reg(t_vm *vm, t_pro pro, int reg_pos,
								unsigned int reg)
{
	int		i;

	i = DIR_SIZE;
	(void)pro;
	reg_pos = reg_pos % MEM_SIZE;
	if (reg_pos < 0)
		reg_pos += MEM_SIZE;
	while (--i >= 0)
	{
		vm->reg[reg_pos % MEM_SIZE] = (reg >> (i * 8)) & 0xff;
		reg_pos++;
	}
}
