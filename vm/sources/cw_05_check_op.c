/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_05_check_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 02:24:19 by fallouch          #+#    #+#             */
/*   Updated: 2019/03/30 02:24:21 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		incorrect_param(t_pro pro, t_vm vm, int op_code)
{
	int		oct_code;
	int		i;
	int		p;
	int		param[3];

	i = -1;
	ft_bzero(param, sizeof(param));
	if (!vm.op_tab[op_code - 1].codage_octal)
		return (0);
	oct_code = vm.reg[(pro.pc + 1) % MEM_SIZE];
	params(pro, vm, param);
	while (++i < vm.op_tab[op_code - 1].nbr_arg)
	{
		p = (oct_code >> (2 * (3 - i))) & 0x03;
		if (p == 0x03)
			p++;
		if (!(p & vm.op_tab[op_code - 1].arg[i]))
			return (1);
		if ((p & 0x03) == REG_CODE && (param[i] < 1
		|| param[i] > REG_NUMBER))
			return (1);
	}
	return (0);
}
