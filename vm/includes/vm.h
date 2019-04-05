/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <kaboujna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:48:23 by fallouch          #+#    #+#             */
/*   Updated: 2019/03/29 23:13:54 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "corewar.h"
# include "op.h"

# define CHAMP_EXTENSION	".cor"

# define ERROR_N1	"ERROR : Number needed after -n flag\n"
# define ERROR_D1	"ERROR : Number needed after -d flag\n"
# define ERROR_N2	"ERROR : Champs needed after -n flag\n"
# define ERROR_N3	"ERROR : Num after -n (%d) flag must be greater than 0\n"
# define ERROR_N4	"ERROR : Num after -n (%d) flag must be less than 1000\n"
# define ERROR_D2	"ERROR : Cannot use multiple -d flag\n"
# define ERROR_D3	"ERROR : Cannot use -d flag with a negative number\n"
# define ERROR_OPEN	"ERROR : \"%s\" cannot be opened or does not exist\n"
# define ERROR_NUMB	"ERROR : 1 to %d champions needed\n"
# define ERROR_ASM	"ERROR : Cannot run .s file. Execute \"./asm %s\" first\n"
# define ERROR_F1	"ERROR : Missing flag. Use -a, -d, -i or -n\n"
# define ERROR_F2	"ERROR : flag \"%s\" is not handle\n"
# define ERROR_FILE	"ERROR : \"%s\" is not a file\n"
# define ERROR_COR	"ERROR : \"%s\" is not a .cor\n"
# define ERROR_MALL	"ERROR : Memory allocation\n"
# define ERROR_0	"ERROR : First byte must be 0x00\n"
# define ERROR_MGC	"ERROR : Invalid COREWAR_EXEC_MAGIC\n"
# define ERROR_CHMP	"ERROR : Invalid parameter number %d: \"%s\"\n"
# define ERROR_NAME	"ERROR : Champion number %d name's is incorrect\n"
# define ERROR_READ	"ERROR : Invalid header size\n"
# define ERROR_CONT	"ERROR : Too large content\n"
# define ERROR_EMPT "ERROR : Empty content\n"
# define ERROR_SIZE	"ERROR : Bad content size\n"
# define ERROR_COM	"ERROR : Comment is too long\n"
# define ERROR_NBR	"ERROR : Player number %d is already used\n"

# define DUMP_OPT	"-dump"
# define N_OPT		"-n"
# define AFF_OPT	"aff"

# define LIVE_TXT	"un processus dit que le joueur %d(%s) est en vie\n"
# define WIN_TXT	"le joueur %d(%s) a gagne\n"

# define NEW_OP 256

# define COLOR_GRAY 8
# define SETTINGS_LINE 2
# define INFO_LINE SETTINGS_LINE + 5
# define CHAMPS_LINE INFO_LINE + 12

typedef struct		s_pro
{
	unsigned int	player;
	int				last_pc;
	int				pc;
	int				op_size;
	int				cycles;
	unsigned short	op_code;

	int				color;
	int				live;
	int				carry;

	unsigned int	reg[REG_NUMBER + 1];
}					t_pro;

typedef struct		s_champ
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned int	player;

	unsigned int	last_live;
	unsigned int	cur_live;
	unsigned int	live;
	unsigned int	pc;

	int				color;
	unsigned int	size;
}					t_champ;

typedef struct		s_vm
{
	unsigned char	reg[MEM_SIZE];
	int				cycle_to_die;
	int				max_checks;
	int				nbr_champs;
	int				cycles_total;
	unsigned int	total_live;
	unsigned char	last_champ;

	int				dump;
	char			aff;
	unsigned int	nbr_pro;
	unsigned int	nbr_pro_alive;

	t_champ			champs[MAX_PLAYERS];
	t_pro			**pro;
	t_op			*op_tab;
}					t_vm;

void				vm_usage(void);
int					check_flag_n(char **argv, int *i, t_vm *vm);
int					check_flag_d(char **argv, int *i, int *dump);
int					invalid_champ(char *name, t_vm *vm, char *number);
int					count_champs(char **argv);
int					invalid_param(char *argv);
int					convert_hexa_int(char a, char b);
int					handle_number(t_vm *vm, char *number, int j);
void				swap_reg(t_vm *vm, unsigned int c);
int					exec_vm(t_vm *vm);
void				free_vm(t_vm *vm);
void				print_vm(t_vm vm);
int					init_process(t_vm *vm);
t_pro				*new_pro_from_champ(t_champ champ, t_vm vm);
t_pro				*new_pro_from_pro(t_pro pro, t_vm vm);
void				free_pro(t_vm *vm);
void				increment_pc(int increment, t_pro *pro, t_vm *vm);
int					have_winner(t_vm vm);
t_champ				winner(t_vm vm);
int					have_active_pro(t_vm *vm);
void				exec_pro(t_pro *pro, t_vm *vm);
void				goto_next_operation(t_pro *pro, t_vm *vm);
int					num_at_reg(t_vm vm, int pos, size_t size);
int32_t				swap_int32(int32_t value);
void				set_num_at_reg(t_vm *vm, t_pro pro, int reg_pos,
									unsigned int reg);
int					op_size(int op_code, int oct_code, t_vm vm);
int					*params(t_pro pro, t_vm vm, int *p);
int					param_type(int oct_code, int n);
int					incorrect_param(t_pro pro, t_vm vm, int op_code);
int					ft_mod(int a, int b);
void				new_op(t_pro *pro, t_vm *vm);
void				ft_live(t_pro *pro, t_vm *vm);
void				ft_ld(t_pro *pro, t_vm *vm);
void				ft_st(t_pro *pro, t_vm *vm);
void				ft_add(t_pro *pro, t_vm *vm);
void				ft_sub(t_pro *pro, t_vm *vm);
void				ft_and(t_pro *pro, t_vm *vm);
void				ft_or(t_pro *pro, t_vm *vm);
void				ft_xor(t_pro *pro, t_vm *vm);
void				ft_zjmp(t_pro *pro, t_vm *vm);
void				ft_ldi(t_pro *pro, t_vm *vm);
void				ft_sti(t_pro *pro, t_vm *vm);
void				ft_fork(t_pro *pro, t_vm *vm);
void				ft_lld(t_pro *pro, t_vm *vm);
void				ft_lldi(t_pro *pro, t_vm *vm);
void				ft_lfork(t_pro *pro, t_vm *vm);
void				ft_aff(t_pro *pro, t_vm *vm);

#endif
