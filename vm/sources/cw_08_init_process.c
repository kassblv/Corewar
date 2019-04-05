/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_08_init_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 02:23:03 by fallouch          #+#    #+#             */
/*   Updated: 2019/03/30 02:23:06 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int				init_process(t_vm *vm)
{
	int		i;
	t_pro	*new;

	if (!(vm->pro = malloc(sizeof(t_pro *) * vm->nbr_champs)))
		return (0);
	i = -1;
	while (++i < vm->nbr_champs)
	{
		if (!(new = new_pro_from_champ(vm->champs[i], *vm)))
		{
			free_pro(vm);
			return (0);
		}
		vm->pro[i] = new;
	}
	return (1);
}
