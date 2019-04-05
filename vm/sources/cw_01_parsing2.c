/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_01_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 02:22:25 by fallouch          #+#    #+#             */
/*   Updated: 2019/03/30 02:22:26 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		check_magic(char *line, t_vm *vm, int *i)
{
	int *tmp;

	*i += 3;
	(void)vm;
	tmp = (int*)line;
	*tmp = swap_int32(*tmp);
	if (*tmp == COREWAR_EXEC_MAGIC)
		return (0);
	return (ft_printf(ERROR_MGC));
}

int		check_name(char *line, t_vm *vm, int *i, int k)
{
	int		j;

	j = 0;
	while (line[++(*i)])
	{
		if (j == PROG_NAME_LENGTH + 1)
			return (ft_printf(ERROR_NAME, k + 1));
		vm->champs[k].name[j] = line[*i];
		j++;
	}
	vm->champs[k].name[j] = 0;
	vm->champs[k].last_live = 0;
	vm->champs[k].cur_live = 0;
	vm->champs[k].pc = k * MEM_SIZE / vm->nbr_champs;
	vm->champs[k].live = 0;
	return (0);
}

int		check_comment(char *line, t_vm *vm, int k)
{
	int		i;
	int		j;

	i = 0x8b;
	j = -1;
	while (line[++i] && j < COMMENT_LENGTH)
		vm->champs[k].comment[++j] = line[i];
	if (j >= COMMENT_LENGTH)
		return (ft_printf(ERROR_COM));
	vm->champs[k].comment[j + 1] = 0;
	return (0);
}

int		init_champ(char *line, t_vm *vm, char *name)
{
	int		fd;

	(void)vm;
	if ((fd = ft_strlen(name)) >= 2 && !ft_strcmp(name + fd - 2, ".s"))
		return (ft_printf(ERROR_ASM, name));
	if ((fd = ft_strlen(name)) < 4 || ft_strcmp(name + fd - 4, CHAMP_EXTENSION))
		return (ft_printf(ERROR_COR, name));
	if ((fd = open(name, O_RDONLY)) == -1)
		return (ft_printf(ERROR_OPEN, name));
	if (read(fd, line, HEADER_SIZE) < HEADER_SIZE)
		return (ft_printf(ERROR_READ));
	if ((unsigned char)line[SIZE_CHAMP] * 256 +
			(unsigned char)line[SIZE_CHAMP + 1] > CHAMP_MAX_SIZE)
		return (ft_printf(ERROR_CONT));
	if ((unsigned char)line[SIZE_CHAMP] * 256 +
			(unsigned char)line[SIZE_CHAMP + 1] == 0)
		return (ft_printf(ERROR_EMPT));
	if (read(fd, line + HEADER_SIZE, (unsigned char)line[SIZE_CHAMP]
				* 256 + (unsigned char)line[SIZE_CHAMP + 1] + 1) !=
			(unsigned char)line[SIZE_CHAMP] * 256
			+ (unsigned char)line[SIZE_CHAMP + 1])
		return (ft_printf(ERROR_SIZE));
	return (0);
}

int		invalid_champ(char *name, t_vm *vm, char *number)
{
	int		j;
	char	line[HEADER_SIZE + CHAMP_MAX_SIZE + 1];

	j = 0;
	if (init_champ(line, vm, name))
		return (1);
	if (check_magic(line, vm, &j) || check_name(line, vm, &j, vm->last_champ) ||
			check_comment(line, vm, vm->last_champ))
		return (1);
	j = -1;
	while (++j < (unsigned char)line[SIZE_CHAMP] * 256 +
			(unsigned char)line[SIZE_CHAMP + 1])
		vm->reg[j + (vm->last_champ * MEM_SIZE / vm->nbr_champs)] =
			line[HEADER_SIZE + j];
	vm->champs[vm->last_champ].size = (unsigned char)line[SIZE_CHAMP] * 256
		+ (unsigned char)line[SIZE_CHAMP + 1];
	if (handle_number(vm, number, vm->last_champ))
		return (ft_printf(ERROR_NBR, ft_atoi(number)));
	vm->last_champ++;
	return (0);
}
