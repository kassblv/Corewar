/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 23:17:33 by kaboujna          #+#    #+#             */
/*   Updated: 2019/03/30 02:22:14 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_lld(t_pro *pro, t_vm *vm)
{
	int				p[3];
	unsigned int	a;

	params(*pro, *vm, p);
	a = p[0];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 0) == IND_CODE)
		a = num_at_reg(*vm, pro->pc + (short)p[0], 4);
	pro->reg[p[1]] = a;
	pro->carry = 0;
	if (!a)
		pro->carry = 1;
	goto_next_operation(pro, vm);
}
