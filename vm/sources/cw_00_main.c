/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_00_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 02:22:30 by fallouch          #+#    #+#             */
/*   Updated: 2019/03/30 02:22:33 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		init_var(t_vm *vm, char **argv)
{
	int		i;

	i = -1;
	vm->nbr_champs = count_champs(argv);
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->max_checks = MAX_CHECKS;
	vm->dump = -1;
	vm->aff = 0;
	ft_bzero(vm->champs, sizeof(vm->champs));
	if (!(vm->op_tab = struct_tab()))
		return (0);
	vm->last_champ = 0;
	vm->pro = 0;
	vm->cycles_total = 0;
	vm->total_live = 0;
	vm->nbr_pro = vm->nbr_champs;
	vm->nbr_pro_alive = vm->nbr_champs;
	while (++i < MEM_SIZE)
		vm->reg[i] = 0;
	i = -1;
	return (1);
}

int		init2(char **argv, t_vm *vm, int *i)
{
	if (!ft_strcmp(argv[*i], N_OPT) || !ft_strcmp(argv[*i], "-number"))
	{
		if (check_flag_n(argv, i, vm))
			return (1);
	}
	else if (!ft_strcmp(argv[*i], "-d") || !ft_strcmp(argv[*i], DUMP_OPT))
	{
		if (check_flag_d(argv, i, &vm->dump))
			return (1);
	}
	else if (!ft_strcmp(argv[*i], "-a") || !ft_strcmp(argv[*i], AFF_OPT))
		vm->aff = 1;
	else if (!ft_strchr(argv[*i], '.'))
		return (invalid_param(argv[*i]));
	else if (invalid_champ(argv[*i], vm, 0))
		return (ft_printf(ERROR_CHMP, *i, argv[*i]));
	return (0);
}

void	order(t_vm *vm)
{
	t_champ	swp;
	int		i;
	int		j;

	i = -1;
	while (++i < vm->nbr_champs - 1)
	{
		if (vm->champs[i].player < vm->champs[i + 1].player)
		{
			swap_reg(vm, i);
			swp = vm->champs[i];
			vm->champs[i] = vm->champs[i + 1];
			vm->champs[i + 1] = swp;
			j = vm->champs[i].pc;
			vm->champs[i].pc = vm->champs[i + 1].pc;
			vm->champs[i + 1].pc = j;
			i = -1;
		}
	}
}

int		init(char **argv, t_vm *vm)
{
	int		i;

	i = 0;
	if (!vm->nbr_champs || vm->nbr_champs > MAX_PLAYERS)
		return (ft_printf(ERROR_NUMB, MAX_PLAYERS));
	while (argv[++i])
	{
		if (!argv[i][0])
			continue;
		if (init2(argv, vm, &i))
			return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_vm	vm;

	if (argc < 2)
		vm_usage();
	if (!init_var(&vm, argv))
		return (0);
	if (init(argv, &vm))
	{
		free_vm(&vm);
		return (0);
	}
	order(&vm);
	if (!exec_vm(&vm))
		return (0);
	return (0);
}
