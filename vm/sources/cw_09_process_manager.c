/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_09_process_manager.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 02:23:16 by fallouch          #+#    #+#             */
/*   Updated: 2019/03/30 02:23:17 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_pro	*new_pro_from_champ(t_champ champ, t_vm vm)
{
	t_pro	*new;
	int		op_code;

	if (!(new = (t_pro *)malloc(sizeof(t_pro))))
		return (NULL);
	op_code = vm.reg[champ.pc] - 1;
	new->player = champ.player;
	new->pc = champ.pc;
	new->last_pc = new->pc;
	new->live = 0;
	new->carry = 0;
	new->color = champ.color;
	new->op_code = NEW_OP;
	ft_memset(new->reg, 0, (REG_NUMBER + 1) * sizeof(int));
	new->reg[1] = champ.player;
	return (new);
}

t_pro	*new_pro_from_pro(t_pro pro, t_vm vm)
{
	t_pro	*new;

	(void)vm;
	if (!(new = (t_pro *)malloc(sizeof(t_pro))))
		return (NULL);
	new->player = pro.player;
	new->live = pro.live;
	new->carry = pro.carry;
	new->color = pro.color;
	ft_memcpy(new->reg, pro.reg, (REG_NUMBER + 1) * sizeof(int));
	return (new);
}

void	free_pro(t_vm *vm)
{
	unsigned int		i;

	i = 0;
	if (!vm->pro)
		return ;
	while (i < vm->nbr_pro)
	{
		ft_memdel((void **)&(vm->pro[i]));
		i++;
	}
	free(vm->pro);
}

void	increment_pc(int increment, t_pro *pro, t_vm *vm)
{
	pro->last_pc = pro->pc;
	(void)vm;
	pro->pc = (pro->pc + increment) % MEM_SIZE;
	if (pro->pc < 0)
		pro->pc = pro->pc + MEM_SIZE;
}

void	goto_next_operation(t_pro *pro, t_vm *vm)
{
	increment_pc(pro->op_size + 1, pro, vm);
	pro->op_code = NEW_OP;
}
