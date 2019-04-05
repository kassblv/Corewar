/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 23:16:34 by kaboujna          #+#    #+#             */
/*   Updated: 2019/03/30 02:25:38 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_zjmp(t_pro *pro, t_vm *vm)
{
	short	addr;

	addr = num_at_reg(*vm, pro->pc + 1, 2);
	if (pro->carry)
	{
		increment_pc(addr % IDX_MOD, pro, vm);
		pro->op_code = NEW_OP;
	}
	else
		goto_next_operation(pro, vm);
}
