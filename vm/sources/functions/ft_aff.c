/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 23:15:34 by kaboujna          #+#    #+#             */
/*   Updated: 2019/03/29 23:15:36 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_aff(t_pro *pro, t_vm *vm)
{
	int				p[3];
	unsigned		c;

	params(*pro, *vm, p);
	c = pro->reg[p[0]] % 256;
	if (vm->aff)
		ft_printf("aff : %c\n", c);
	goto_next_operation(pro, vm);
}
