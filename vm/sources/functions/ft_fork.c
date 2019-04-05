/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 23:18:52 by kaboujna          #+#    #+#             */
/*   Updated: 2019/03/30 02:22:13 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_fork(t_pro *pro, t_vm *vm)
{
	short	addr;
	t_pro	*new;

	addr = num_at_reg(*vm, pro->pc + 1, 2);
	if (!(new = new_pro_from_pro(*pro, *vm)))
		return ;
	new->pc = ft_mod(pro->pc + (addr % IDX_MOD), MEM_SIZE);
	new->last_pc = new->pc;
	new->op_code = NEW_OP;
	if (!(vm->pro = realloc(vm->pro, sizeof(t_pro) * (vm->nbr_pro + 1))))
		return ;
	vm->pro[vm->nbr_pro] = new;
	vm->nbr_pro++;
	vm->nbr_pro_alive++;
	goto_next_operation(pro, vm);
}
