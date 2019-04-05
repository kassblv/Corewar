/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_14_end_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 23:24:57 by kaboujna          #+#    #+#             */
/*   Updated: 2019/03/30 02:23:57 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_champ		winner(t_vm vm)
{
	unsigned int	live_max;
	int				i;
	t_champ			champ_max;

	i = -1;
	live_max = 0;
	while (++i < vm.nbr_champs)
		if (vm.champs[i].live >= live_max)
		{
			live_max = vm.champs[i].live;
			champ_max = vm.champs[i];
		}
	return (champ_max);
}

int			have_active_pro(t_vm *vm)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while ((unsigned int)++i < vm->nbr_pro)
	{
		if (!vm->pro[i])
			continue ;
		if (!vm->pro[i]->live)
		{
			vm->nbr_pro_alive--;
			ft_memdel((void **)(&(vm->pro[i])));
		}
		else
		{
			vm->pro[i]->live = 0;
			j++;
		}
	}
	return (j);
}
