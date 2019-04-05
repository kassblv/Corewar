/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 23:15:02 by kaboujna          #+#    #+#             */
/*   Updated: 2019/03/29 23:17:56 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_live(t_pro *pro, t_vm *vm)
{
	unsigned int	champ;
	int				i;

	champ = num_at_reg(*vm, pro->pc + 1, 4);
	i = -1;
	pro->live++;
	vm->total_live++;
	while (++i < vm->nbr_champs)
	{
		if (vm->champs[i].player == champ)
		{
			vm->champs[i].cur_live += 1;
			vm->champs[i].live = vm->cycles_total;
			vm->champs[i].last_live = vm->cycles_total;
			ft_printf(LIVE_TXT, -vm->champs[i].player, vm->champs[i].name);
			break ;
		}
	}
	goto_next_operation(pro, vm);
}
