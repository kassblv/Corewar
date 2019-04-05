/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_11_aux_reg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 02:23:35 by fallouch          #+#    #+#             */
/*   Updated: 2019/03/30 02:23:40 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	swap_reg(t_vm *vm, unsigned int c)
{
	int				i;
	int				max;
	unsigned char	swp;

	max = CHAMP_MAX_SIZE;
	i = -1;
	while (++i < max)
	{
		swp = vm->reg[vm->champs[c].pc + i];
		vm->reg[vm->champs[c].pc + i] = vm->reg[vm->champs[c + 1].pc + i];
		vm->reg[vm->champs[c + 1].pc + i] = swp;
	}
}
