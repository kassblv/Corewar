/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_13_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 02:23:50 by fallouch          #+#    #+#             */
/*   Updated: 2019/03/30 02:23:53 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			free_vm(t_vm *vm)
{
	free_pro(vm);
	free(vm->op_tab);
}

static void		change_values_if_needed(t_vm *vm)
{
	int		i;

	i = -1;
	while (++i < vm->nbr_champs)
		vm->champs[i].cur_live = 0;
	if (vm->total_live >= NBR_LIVE)
	{
		vm->max_checks = MAX_CHECKS;
		vm->cycle_to_die = vm->cycle_to_die - CYCLE_DELTA;
	}
	else if (vm->max_checks > 0)
		vm->max_checks -= 1;
	else
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->max_checks = MAX_CHECKS;
	}
	vm->total_live = 0;
}

static void		run_cycles(t_vm *vm)
{
	register int		i;
	register int		j;

	i = -1;
	while (++i < vm->cycle_to_die)
	{
		if (vm->cycles_total == vm->dump
			&& !(i + 1 == vm->cycle_to_die && !have_active_pro(vm)))
			print_vm(*vm);
		(vm->cycles_total)++;
		j = vm->nbr_pro;
		while (--j >= 0)
		{
			if (!vm->pro[j])
				continue ;
			if (vm->pro[j]->op_code == NEW_OP)
				new_op(vm->pro[j], vm);
			if (vm->pro[j]->cycles > 1)
				vm->pro[j]->cycles -= 1;
			else
				exec_pro(vm->pro[j], vm);
		}
	}
}

int				exec_vm(t_vm *vm)
{
	int		i;

	i = -1;
	if (!init_process(vm))
		return (0);
	while (1)
	{
		run_cycles(vm);
		if (!have_active_pro(vm))
			break ;
		change_values_if_needed(vm);
	}
	ft_printf(WIN_TXT, -winner(*vm).player, winner(*vm).name);
	free_vm(vm);
	return (1);
}

void			print_vm(t_vm vm)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0 && i > 0)
			ft_printf("\n");
		if (i % 64 == 0 && i == 0)
			ft_printf("0x0000 : ");
		else if (i % 64 == 0)
			ft_printf("%#06x : ", i);
		ft_printf("%02x ", vm.reg[i]);
	}
	ft_printf("\n");
	free_vm(&vm);
	exit(0);
}
