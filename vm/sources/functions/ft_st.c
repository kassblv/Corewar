/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 23:17:09 by kaboujna          #+#    #+#             */
/*   Updated: 2019/03/29 23:17:10 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_st(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		a;

	params(*pro, *vm, p);
	a = pro->reg[p[0]];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 1) == REG_CODE)
		pro->reg[p[1]] = a;
	else
		set_num_at_reg(vm, *pro, pro->pc + ((short)p[1] % IDX_MOD), a);
	goto_next_operation(pro, vm);
}
