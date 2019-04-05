/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 23:16:16 by kaboujna          #+#    #+#             */
/*   Updated: 2019/03/29 23:16:18 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_sti(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		a;
	int		b;

	params(*pro, *vm, p);
	a = (short)p[1];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 1) == REG_CODE)
		a = pro->reg[p[1]];
	else if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 1) == IND_CODE)
		a = num_at_reg(*vm, pro->pc + ((short)p[1] % IDX_MOD), 4);
	b = (short)p[2];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 2) == REG_CODE)
		b = pro->reg[p[2]];
	set_num_at_reg(vm, *pro, pro->pc + ((a + b) % IDX_MOD), pro->reg[p[0]]);
	goto_next_operation(pro, vm);
}
