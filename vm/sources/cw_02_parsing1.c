/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_02_parsing1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 02:22:42 by fallouch          #+#    #+#             */
/*   Updated: 2019/03/30 02:22:48 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		ft_str_is_number(char *str)
{
	if (!str || !(*str))
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	return (!(*str));
}

int		check_flag_n(char **argv, int *i, t_vm *vm)
{
	if (!ft_str_is_number(argv[*i + 1]))
		return (ft_printf(ERROR_N1));
	if (ft_atoi(argv[*i + 1]) < 0)
		return (ft_printf(ERROR_N3, ft_atoi(argv[*i + 1])));
	if (ft_atoi(argv[*i + 1]) > 1000)
		return (ft_printf(ERROR_N4, ft_atoi(argv[*i + 1])));
	if (!argv[*i + 2])
		return (ft_printf(ERROR_N2));
	if (invalid_champ(argv[*i + 2], vm, argv[*i + 1]))
		return (ft_printf(ERROR_CHMP, *i + 2, argv[*i + 2]));
	*i += 2;
	return (0);
}

int		check_flag_d(char **argv, int *i, int *dump)
{
	if (!ft_str_is_number(argv[*i + 1]))
		return (ft_printf(ERROR_D1));
	if (*dump != -1)
		return (ft_printf(ERROR_D2));
	*dump = ft_atoi(argv[*i + 1]);
	if (*dump < 0)
		return (ft_printf(ERROR_D3, *dump));
	(*i)++;
	return (0);
}

int		count_champs(char **argv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (argv[++i])
		if (ft_strchr(argv[i], '.'))
			j++;
	return (j);
}

int		invalid_param(char *argv)
{
	if (argv[0] == '-')
	{
		if (!argv[1])
			return (ft_printf(ERROR_F1));
		return (ft_printf(ERROR_F2, argv));
	}
	return (ft_printf(ERROR_FILE, argv));
}
