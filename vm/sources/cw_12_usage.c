/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_12_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 02:23:44 by fallouch          #+#    #+#             */
/*   Updated: 2019/03/30 02:23:47 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	vm_usage(void)
{
	ft_printf("usage : ./corewar [champ.cor ...]\n");
	ft_printf("\t[-n num] Set custom champion's number\n");
	ft_printf("\t[-d num] Dump vm at custom cycle\n");
	ft_printf("\t[-a] Display aff function result on standard output\n");
	exit(0);
}
