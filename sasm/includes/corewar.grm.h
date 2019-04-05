#ifndef _COREWAR_GRM_H_
#define _COREWAR_GRM_H_

#include <stdint.h>
#include <stdbool.h>

#define _ONLY_STATE_TOKEN_	
#include "corewar.lex.h"
#include "../../libft/libft.h"
#undef	_ONLY_STATE_TOKEN_

enum {
	N_program,
	N_prolog,
	N_list,
	N_name,
	N_comment,
	N_asm_layout,
	N_list_PRIME,
	N_label_opt,
	N_mixed_instr,
	N_lfork_instr,
	N_sti_instr,
	N_fork_instr,
	N_lld_instr,
	N_ld_instr,
	N_add_instr,
	N_zjmp_instr,
	N_sub_instr,
	N_ldi_instr,
	N_or_instr,
	N_aff_instr,
	N_live_instr,
	N_xor_instr,
	N_lldi_instr,
	N_and_instr,
	N_all,
	N_regdir,
	N_dirind,
};

#define TOTAL_NTER	27

enum {
	P_LHS_Nprogram_RHS_Nprolog_Nlist,
	P_LHS_Nprolog_RHS_Nname_Ncomment,
	P_LHS_Nprolog_RHS_Ncomment_Nname,
	P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE,
	P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE,
	P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME,
	P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME,
	P_LHS_Nlist_PRIME_RHS,
	P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE,
	P_LHS_Nlabel_opt_RHS_TLABEL,
	P_LHS_Nlabel_opt_RHS,
	P_LHS_Nmixed_instr_RHS_Nlfork_instr,
	P_LHS_Nmixed_instr_RHS_Nsti_instr,
	P_LHS_Nmixed_instr_RHS_Nfork_instr,
	P_LHS_Nmixed_instr_RHS_Nlld_instr,
	P_LHS_Nmixed_instr_RHS_Nld_instr,
	P_LHS_Nmixed_instr_RHS_Nadd_instr,
	P_LHS_Nmixed_instr_RHS_Nzjmp_instr,
	P_LHS_Nmixed_instr_RHS_Nsub_instr,
	P_LHS_Nmixed_instr_RHS_Nldi_instr,
	P_LHS_Nmixed_instr_RHS_Nor_instr,
	P_LHS_Nmixed_instr_RHS_Naff_instr,
	P_LHS_Nmixed_instr_RHS_Nlive_instr,
	P_LHS_Nmixed_instr_RHS_Nxor_instr,
	P_LHS_Nmixed_instr_RHS_Nlldi_instr,
	P_LHS_Nmixed_instr_RHS_Nand_instr,
	P_LHS_Nmixed_instr_RHS,
	P_LHS_Nlfork_instr_RHS_TLFORK_TDIRECT,
	P_LHS_Nsti_instr_RHS_TSTI_TREG_TSEP_Nall_TSEP_Nregdir,
	P_LHS_Nfork_instr_RHS_TFORK_TDIRECT,
	P_LHS_Nlld_instr_RHS_TLLD_Ndirind_TSEP_TREG,
	P_LHS_Nld_instr_RHS_TLD_Ndirind_TSEP_TREG,
	P_LHS_Nadd_instr_RHS_TADD_TREG_TSEP_TREG_TSEP_TREG,
	P_LHS_Nzjmp_instr_RHS_TZJMP_TDIRECT,
	P_LHS_Nsub_instr_RHS_TSUB_TREG_TSEP_TREG_TSEP_TREG,
	P_LHS_Nldi_instr_RHS_TLDI_Nall_TSEP_Nregdir_TSEP_TREG,
	P_LHS_Nor_instr_RHS_TOR_Nall_TSEP_Nall_TSEP_TREG,
	P_LHS_Naff_instr_RHS_TAFF_TREG,
	P_LHS_Nlive_instr_RHS_TLIVE_TDIRECT,
	P_LHS_Nxor_instr_RHS_TXOR_Nall_TSEP_Nall_TSEP_TREG,
	P_LHS_Nlldi_instr_RHS_TLLDI_Nall_TSEP_Nregdir_TSEP_TREG,
	P_LHS_Nand_instr_RHS_TAND_Nall_TSEP_Nall_TSEP_TREG,
	P_LHS_Nall_RHS_TREG,
	P_LHS_Nall_RHS_TDIRECT,
	P_LHS_Nall_RHS_TINDIRECT,
	P_LHS_Nregdir_RHS_TREG,
	P_LHS_Nregdir_RHS_TDIRECT,
	P_LHS_Ndirind_RHS_TDIRECT,
	P_LHS_Ndirind_RHS_TINDIRECT,
};

#define TOTAL_PROD	50

static int
corewar_rhs_prod_table[TOTAL_PROD] = {
	[P_LHS_Nprogram_RHS_Nprolog_Nlist] = 2,
	[P_LHS_Nprolog_RHS_Nname_Ncomment] = 2,
	[P_LHS_Nprolog_RHS_Ncomment_Nname] = 2,
	[P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE] = 3,
	[P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE] = 3,
	[P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME] = 2,
	[P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME] = 2,
	[P_LHS_Nlist_PRIME_RHS] = 0,
	[P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE] = 3,
	[P_LHS_Nlabel_opt_RHS_TLABEL] = 1,
	[P_LHS_Nlabel_opt_RHS] = 0,
	[P_LHS_Nmixed_instr_RHS_Nlfork_instr] = 1,
	[P_LHS_Nmixed_instr_RHS_Nsti_instr] = 1,
	[P_LHS_Nmixed_instr_RHS_Nfork_instr] = 1,
	[P_LHS_Nmixed_instr_RHS_Nlld_instr] = 1,
	[P_LHS_Nmixed_instr_RHS_Nld_instr] = 1,
	[P_LHS_Nmixed_instr_RHS_Nadd_instr] = 1,
	[P_LHS_Nmixed_instr_RHS_Nzjmp_instr] = 1,
	[P_LHS_Nmixed_instr_RHS_Nsub_instr] = 1,
	[P_LHS_Nmixed_instr_RHS_Nldi_instr] = 1,
	[P_LHS_Nmixed_instr_RHS_Nor_instr] = 1,
	[P_LHS_Nmixed_instr_RHS_Naff_instr] = 1,
	[P_LHS_Nmixed_instr_RHS_Nlive_instr] = 1,
	[P_LHS_Nmixed_instr_RHS_Nxor_instr] = 1,
	[P_LHS_Nmixed_instr_RHS_Nlldi_instr] = 1,
	[P_LHS_Nmixed_instr_RHS_Nand_instr] = 1,
	[P_LHS_Nmixed_instr_RHS] = 0,
	[P_LHS_Nlfork_instr_RHS_TLFORK_TDIRECT] = 2,
	[P_LHS_Nsti_instr_RHS_TSTI_TREG_TSEP_Nall_TSEP_Nregdir] = 6,
	[P_LHS_Nfork_instr_RHS_TFORK_TDIRECT] = 2,
	[P_LHS_Nlld_instr_RHS_TLLD_Ndirind_TSEP_TREG] = 4,
	[P_LHS_Nld_instr_RHS_TLD_Ndirind_TSEP_TREG] = 4,
	[P_LHS_Nadd_instr_RHS_TADD_TREG_TSEP_TREG_TSEP_TREG] = 6,
	[P_LHS_Nzjmp_instr_RHS_TZJMP_TDIRECT] = 2,
	[P_LHS_Nsub_instr_RHS_TSUB_TREG_TSEP_TREG_TSEP_TREG] = 6,
	[P_LHS_Nldi_instr_RHS_TLDI_Nall_TSEP_Nregdir_TSEP_TREG] = 6,
	[P_LHS_Nor_instr_RHS_TOR_Nall_TSEP_Nall_TSEP_TREG] = 6,
	[P_LHS_Naff_instr_RHS_TAFF_TREG] = 2,
	[P_LHS_Nlive_instr_RHS_TLIVE_TDIRECT] = 2,
	[P_LHS_Nxor_instr_RHS_TXOR_Nall_TSEP_Nall_TSEP_TREG] = 6,
	[P_LHS_Nlldi_instr_RHS_TLLDI_Nall_TSEP_Nregdir_TSEP_TREG] = 6,
	[P_LHS_Nand_instr_RHS_TAND_Nall_TSEP_Nall_TSEP_TREG] = 6,
	[P_LHS_Nall_RHS_TREG] = 1,
	[P_LHS_Nall_RHS_TDIRECT] = 1,
	[P_LHS_Nall_RHS_TINDIRECT] = 1,
	[P_LHS_Nregdir_RHS_TREG] = 1,
	[P_LHS_Nregdir_RHS_TDIRECT] = 1,
	[P_LHS_Ndirind_RHS_TDIRECT] = 1,
	[P_LHS_Ndirind_RHS_TINDIRECT] = 1,
};

static int
corewar_lhs_prod_table[TOTAL_PROD] = {
	[P_LHS_Nprogram_RHS_Nprolog_Nlist] = N_program,
	[P_LHS_Nprolog_RHS_Nname_Ncomment] = N_prolog,
	[P_LHS_Nprolog_RHS_Ncomment_Nname] = N_prolog,
	[P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE] = N_name,
	[P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE] = N_comment,
	[P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME] = N_list,
	[P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME] = N_list_PRIME,
	[P_LHS_Nlist_PRIME_RHS] = N_list_PRIME,
	[P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE] = N_asm_layout,
	[P_LHS_Nlabel_opt_RHS_TLABEL] = N_label_opt,
	[P_LHS_Nlabel_opt_RHS] = N_label_opt,
	[P_LHS_Nmixed_instr_RHS_Nlfork_instr] = N_mixed_instr,
	[P_LHS_Nmixed_instr_RHS_Nsti_instr] = N_mixed_instr,
	[P_LHS_Nmixed_instr_RHS_Nfork_instr] = N_mixed_instr,
	[P_LHS_Nmixed_instr_RHS_Nlld_instr] = N_mixed_instr,
	[P_LHS_Nmixed_instr_RHS_Nld_instr] = N_mixed_instr,
	[P_LHS_Nmixed_instr_RHS_Nadd_instr] = N_mixed_instr,
	[P_LHS_Nmixed_instr_RHS_Nzjmp_instr] = N_mixed_instr,
	[P_LHS_Nmixed_instr_RHS_Nsub_instr] = N_mixed_instr,
	[P_LHS_Nmixed_instr_RHS_Nldi_instr] = N_mixed_instr,
	[P_LHS_Nmixed_instr_RHS_Nor_instr] = N_mixed_instr,
	[P_LHS_Nmixed_instr_RHS_Naff_instr] = N_mixed_instr,
	[P_LHS_Nmixed_instr_RHS_Nlive_instr] = N_mixed_instr,
	[P_LHS_Nmixed_instr_RHS_Nxor_instr] = N_mixed_instr,
	[P_LHS_Nmixed_instr_RHS_Nlldi_instr] = N_mixed_instr,
	[P_LHS_Nmixed_instr_RHS_Nand_instr] = N_mixed_instr,
	[P_LHS_Nmixed_instr_RHS] = N_mixed_instr,
	[P_LHS_Nlfork_instr_RHS_TLFORK_TDIRECT] = N_lfork_instr,
	[P_LHS_Nsti_instr_RHS_TSTI_TREG_TSEP_Nall_TSEP_Nregdir] = N_sti_instr,
	[P_LHS_Nfork_instr_RHS_TFORK_TDIRECT] = N_fork_instr,
	[P_LHS_Nlld_instr_RHS_TLLD_Ndirind_TSEP_TREG] = N_lld_instr,
	[P_LHS_Nld_instr_RHS_TLD_Ndirind_TSEP_TREG] = N_ld_instr,
	[P_LHS_Nadd_instr_RHS_TADD_TREG_TSEP_TREG_TSEP_TREG] = N_add_instr,
	[P_LHS_Nzjmp_instr_RHS_TZJMP_TDIRECT] = N_zjmp_instr,
	[P_LHS_Nsub_instr_RHS_TSUB_TREG_TSEP_TREG_TSEP_TREG] = N_sub_instr,
	[P_LHS_Nldi_instr_RHS_TLDI_Nall_TSEP_Nregdir_TSEP_TREG] = N_ldi_instr,
	[P_LHS_Nor_instr_RHS_TOR_Nall_TSEP_Nall_TSEP_TREG] = N_or_instr,
	[P_LHS_Naff_instr_RHS_TAFF_TREG] = N_aff_instr,
	[P_LHS_Nlive_instr_RHS_TLIVE_TDIRECT] = N_live_instr,
	[P_LHS_Nxor_instr_RHS_TXOR_Nall_TSEP_Nall_TSEP_TREG] = N_xor_instr,
	[P_LHS_Nlldi_instr_RHS_TLLDI_Nall_TSEP_Nregdir_TSEP_TREG] = N_lldi_instr,
	[P_LHS_Nand_instr_RHS_TAND_Nall_TSEP_Nall_TSEP_TREG] = N_and_instr,
	[P_LHS_Nall_RHS_TREG] = N_all,
	[P_LHS_Nall_RHS_TDIRECT] = N_all,
	[P_LHS_Nall_RHS_TINDIRECT] = N_all,
	[P_LHS_Nregdir_RHS_TREG] = N_regdir,
	[P_LHS_Nregdir_RHS_TDIRECT] = N_regdir,
	[P_LHS_Ndirind_RHS_TDIRECT] = N_dirind,
	[P_LHS_Ndirind_RHS_TINDIRECT] = N_dirind,
};

#define ERROR_SLOT	0
#define START_SYMBOL	N_program

static int
corewar_ll_table[TOTAL_NTER][TOTAL_TOKEN] = {
	[N_program][T_COMMENT]=P_LHS_Nprogram_RHS_Nprolog_Nlist, [N_program][T_NAME]=P_LHS_Nprogram_RHS_Nprolog_Nlist, 
	[N_prolog][T_COMMENT]=P_LHS_Nprolog_RHS_Ncomment_Nname, [N_prolog][T_NAME]=P_LHS_Nprolog_RHS_Nname_Ncomment, 
	[N_list][T_AND]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, [N_list][T_LLDI]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, [N_list][T_XOR]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, [N_list][T_LIVE]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, [N_list][T_AFF]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, [N_list][T_OR]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, [N_list][T_LDI]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, [N_list][T_SUB]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, [N_list][T_ZJMP]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, [N_list][T_ADD]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, [N_list][T_LD]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, [N_list][T_LLD]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, [N_list][T_FORK]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, [N_list][T_STI]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, [N_list][T_LFORK]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, [N_list][T_LABEL]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, [N_list][T_NEWLINE]=P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME, 
	[N_name][T_NAME]=P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE, 
	[N_comment][T_COMMENT]=P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE, 
	[N_asm_layout][T_AND]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, [N_asm_layout][T_LLDI]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, [N_asm_layout][T_XOR]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, [N_asm_layout][T_LIVE]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, [N_asm_layout][T_AFF]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, [N_asm_layout][T_OR]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, [N_asm_layout][T_LDI]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, [N_asm_layout][T_SUB]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, [N_asm_layout][T_ZJMP]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, [N_asm_layout][T_ADD]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, [N_asm_layout][T_LD]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, [N_asm_layout][T_LLD]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, [N_asm_layout][T_FORK]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, [N_asm_layout][T_STI]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, [N_asm_layout][T_LFORK]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, [N_asm_layout][T_LABEL]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, [N_asm_layout][T_NEWLINE]=P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE, 
	[N_list_PRIME][T_EOF]=P_LHS_Nlist_PRIME_RHS, [N_list_PRIME][T_AND]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, [N_list_PRIME][T_LLDI]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, [N_list_PRIME][T_XOR]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, [N_list_PRIME][T_LIVE]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, [N_list_PRIME][T_AFF]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, [N_list_PRIME][T_OR]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, [N_list_PRIME][T_LDI]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, [N_list_PRIME][T_SUB]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, [N_list_PRIME][T_ZJMP]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, [N_list_PRIME][T_ADD]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, [N_list_PRIME][T_LD]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, [N_list_PRIME][T_LLD]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, [N_list_PRIME][T_FORK]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, [N_list_PRIME][T_STI]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, [N_list_PRIME][T_LFORK]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, [N_list_PRIME][T_LABEL]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, [N_list_PRIME][T_NEWLINE]=P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME, 
	[N_label_opt][T_AND]=P_LHS_Nlabel_opt_RHS, [N_label_opt][T_LLDI]=P_LHS_Nlabel_opt_RHS, [N_label_opt][T_XOR]=P_LHS_Nlabel_opt_RHS, [N_label_opt][T_LIVE]=P_LHS_Nlabel_opt_RHS, [N_label_opt][T_AFF]=P_LHS_Nlabel_opt_RHS, [N_label_opt][T_OR]=P_LHS_Nlabel_opt_RHS, [N_label_opt][T_LDI]=P_LHS_Nlabel_opt_RHS, [N_label_opt][T_SUB]=P_LHS_Nlabel_opt_RHS, [N_label_opt][T_ZJMP]=P_LHS_Nlabel_opt_RHS, [N_label_opt][T_ADD]=P_LHS_Nlabel_opt_RHS, [N_label_opt][T_LD]=P_LHS_Nlabel_opt_RHS, [N_label_opt][T_LLD]=P_LHS_Nlabel_opt_RHS, [N_label_opt][T_FORK]=P_LHS_Nlabel_opt_RHS, [N_label_opt][T_STI]=P_LHS_Nlabel_opt_RHS, [N_label_opt][T_LFORK]=P_LHS_Nlabel_opt_RHS, [N_label_opt][T_NEWLINE]=P_LHS_Nlabel_opt_RHS, [N_label_opt][T_LABEL]=P_LHS_Nlabel_opt_RHS_TLABEL, 
	[N_mixed_instr][T_NEWLINE]=P_LHS_Nmixed_instr_RHS, [N_mixed_instr][T_AND]=P_LHS_Nmixed_instr_RHS_Nand_instr, [N_mixed_instr][T_LLDI]=P_LHS_Nmixed_instr_RHS_Nlldi_instr, [N_mixed_instr][T_XOR]=P_LHS_Nmixed_instr_RHS_Nxor_instr, [N_mixed_instr][T_LIVE]=P_LHS_Nmixed_instr_RHS_Nlive_instr, [N_mixed_instr][T_AFF]=P_LHS_Nmixed_instr_RHS_Naff_instr, [N_mixed_instr][T_OR]=P_LHS_Nmixed_instr_RHS_Nor_instr, [N_mixed_instr][T_LDI]=P_LHS_Nmixed_instr_RHS_Nldi_instr, [N_mixed_instr][T_SUB]=P_LHS_Nmixed_instr_RHS_Nsub_instr, [N_mixed_instr][T_ZJMP]=P_LHS_Nmixed_instr_RHS_Nzjmp_instr, [N_mixed_instr][T_ADD]=P_LHS_Nmixed_instr_RHS_Nadd_instr, [N_mixed_instr][T_LD]=P_LHS_Nmixed_instr_RHS_Nld_instr, [N_mixed_instr][T_LLD]=P_LHS_Nmixed_instr_RHS_Nlld_instr, [N_mixed_instr][T_FORK]=P_LHS_Nmixed_instr_RHS_Nfork_instr, [N_mixed_instr][T_STI]=P_LHS_Nmixed_instr_RHS_Nsti_instr, [N_mixed_instr][T_LFORK]=P_LHS_Nmixed_instr_RHS_Nlfork_instr, 
	[N_lfork_instr][T_LFORK]=P_LHS_Nlfork_instr_RHS_TLFORK_TDIRECT, 
	[N_sti_instr][T_STI]=P_LHS_Nsti_instr_RHS_TSTI_TREG_TSEP_Nall_TSEP_Nregdir, 
	[N_fork_instr][T_FORK]=P_LHS_Nfork_instr_RHS_TFORK_TDIRECT, 
	[N_lld_instr][T_LLD]=P_LHS_Nlld_instr_RHS_TLLD_Ndirind_TSEP_TREG, 
	[N_ld_instr][T_LD]=P_LHS_Nld_instr_RHS_TLD_Ndirind_TSEP_TREG, 
	[N_add_instr][T_ADD]=P_LHS_Nadd_instr_RHS_TADD_TREG_TSEP_TREG_TSEP_TREG, 
	[N_zjmp_instr][T_ZJMP]=P_LHS_Nzjmp_instr_RHS_TZJMP_TDIRECT, 
	[N_sub_instr][T_SUB]=P_LHS_Nsub_instr_RHS_TSUB_TREG_TSEP_TREG_TSEP_TREG, 
	[N_ldi_instr][T_LDI]=P_LHS_Nldi_instr_RHS_TLDI_Nall_TSEP_Nregdir_TSEP_TREG, 
	[N_or_instr][T_OR]=P_LHS_Nor_instr_RHS_TOR_Nall_TSEP_Nall_TSEP_TREG, 
	[N_aff_instr][T_AFF]=P_LHS_Naff_instr_RHS_TAFF_TREG, 
	[N_live_instr][T_LIVE]=P_LHS_Nlive_instr_RHS_TLIVE_TDIRECT, 
	[N_xor_instr][T_XOR]=P_LHS_Nxor_instr_RHS_TXOR_Nall_TSEP_Nall_TSEP_TREG, 
	[N_lldi_instr][T_LLDI]=P_LHS_Nlldi_instr_RHS_TLLDI_Nall_TSEP_Nregdir_TSEP_TREG, 
	[N_and_instr][T_AND]=P_LHS_Nand_instr_RHS_TAND_Nall_TSEP_Nall_TSEP_TREG, 
	[N_all][T_INDIRECT]=P_LHS_Nall_RHS_TINDIRECT, [N_all][T_DIRECT]=P_LHS_Nall_RHS_TDIRECT, [N_all][T_REG]=P_LHS_Nall_RHS_TREG, 
	[N_regdir][T_DIRECT]=P_LHS_Nregdir_RHS_TDIRECT, [N_regdir][T_REG]=P_LHS_Nregdir_RHS_TREG, 
	[N_dirind][T_INDIRECT]=P_LHS_Ndirind_RHS_TINDIRECT, [N_dirind][T_DIRECT]=P_LHS_Ndirind_RHS_TDIRECT, 
};

#if 0

enum {
	_SHIFT	= 0x1000,
	_REDUCE	= 0x2000,
	_GOTO	= 0x4000,
};

#define SHIFT(x)	(x | _SHIFT)
#define REDUCE(x)	(x | _REDUCE)
#define GOTO(x)	(x | _GOTO)
#define ACCEPT	(~0)

#define LR_START_STATE	0

static int
corewar_lr_action_table[110][TOTAL_TOKEN] = {
/*   0 */	{[T_COMMENT]=SHIFT(6), [T_NAME]=SHIFT(5)},
/*   1 */	{[T_EOF]=ACCEPT,},
/*   2 */	{[T_LABEL]=SHIFT(16), [T_AND]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LLDI]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_XOR]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LIVE]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_AFF]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_OR]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LDI]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_SUB]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_ZJMP]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_ADD]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LD]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LLD]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_FORK]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_STI]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LFORK]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_NEWLINE]=REDUCE(P_LHS_Nlabel_opt_RHS)},
/*   3 */	{[T_COMMENT]=SHIFT(6)},
/*   4 */	{[T_NAME]=SHIFT(5)},
/*   5 */	{[T_STR]=SHIFT(9)},
/*   6 */	{[T_STR]=SHIFT(7)},
/*   7 */	{[T_NEWLINE]=SHIFT(8)},
/*   8 */	{[T_AND]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_LLDI]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_XOR]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_LIVE]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_AFF]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_OR]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_LDI]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_SUB]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_ZJMP]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_ADD]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_LD]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_LLD]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_FORK]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_STI]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_LFORK]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_LABEL]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_NEWLINE]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE), [T_NAME]=REDUCE(P_LHS_Ncomment_RHS_TCOMMENT_TSTR_TNEWLINE)},
/*   9 */	{[T_NEWLINE]=SHIFT(10)},
/*  10 */	{[T_AND]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_LLDI]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_XOR]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_LIVE]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_AFF]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_OR]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_LDI]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_SUB]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_ZJMP]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_ADD]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_LD]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_LLD]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_FORK]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_STI]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_LFORK]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_LABEL]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_COMMENT]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE), [T_NEWLINE]=REDUCE(P_LHS_Nname_RHS_TNAME_TSTR_TNEWLINE)},
/*  11 */	{[T_AND]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname), [T_LLDI]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname), [T_XOR]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname), [T_LIVE]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname), [T_AFF]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname), [T_OR]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname), [T_LDI]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname), [T_SUB]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname), [T_ZJMP]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname), [T_ADD]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname), [T_LD]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname), [T_LLD]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname), [T_FORK]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname), [T_STI]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname), [T_LFORK]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname), [T_LABEL]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname), [T_NEWLINE]=REDUCE(P_LHS_Nprolog_RHS_Ncomment_Nname)},
/*  12 */	{[T_AND]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment), [T_LLDI]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment), [T_XOR]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment), [T_LIVE]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment), [T_AFF]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment), [T_OR]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment), [T_LDI]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment), [T_SUB]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment), [T_ZJMP]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment), [T_ADD]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment), [T_LD]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment), [T_LLD]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment), [T_FORK]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment), [T_STI]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment), [T_LFORK]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment), [T_LABEL]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment), [T_NEWLINE]=REDUCE(P_LHS_Nprolog_RHS_Nname_Ncomment)},
/*  13 */	{[T_EOF]=REDUCE(P_LHS_Nprogram_RHS_Nprolog_Nlist)},
/*  14 */	{[T_LABEL]=SHIFT(16), [T_AND]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LLDI]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_XOR]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LIVE]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_AFF]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_OR]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LDI]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_SUB]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_ZJMP]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_ADD]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LD]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LLD]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_FORK]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_STI]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LFORK]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_NEWLINE]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_EOF]=REDUCE(P_LHS_Nlist_PRIME_RHS)},
/*  15 */	{[T_AND]=SHIFT(47), [T_LLDI]=SHIFT(46), [T_XOR]=SHIFT(45), [T_LIVE]=SHIFT(44), [T_AFF]=SHIFT(43), [T_OR]=SHIFT(42), [T_LDI]=SHIFT(41), [T_SUB]=SHIFT(40), [T_ZJMP]=SHIFT(39), [T_ADD]=SHIFT(38), [T_LD]=SHIFT(37), [T_LLD]=SHIFT(36), [T_FORK]=SHIFT(35), [T_STI]=SHIFT(34), [T_LFORK]=SHIFT(33), [T_NEWLINE]=REDUCE(P_LHS_Nmixed_instr_RHS)},
/*  16 */	{[T_AND]=REDUCE(P_LHS_Nlabel_opt_RHS_TLABEL), [T_LLDI]=REDUCE(P_LHS_Nlabel_opt_RHS_TLABEL), [T_XOR]=REDUCE(P_LHS_Nlabel_opt_RHS_TLABEL), [T_LIVE]=REDUCE(P_LHS_Nlabel_opt_RHS_TLABEL), [T_AFF]=REDUCE(P_LHS_Nlabel_opt_RHS_TLABEL), [T_OR]=REDUCE(P_LHS_Nlabel_opt_RHS_TLABEL), [T_LDI]=REDUCE(P_LHS_Nlabel_opt_RHS_TLABEL), [T_SUB]=REDUCE(P_LHS_Nlabel_opt_RHS_TLABEL), [T_ZJMP]=REDUCE(P_LHS_Nlabel_opt_RHS_TLABEL), [T_ADD]=REDUCE(P_LHS_Nlabel_opt_RHS_TLABEL), [T_LD]=REDUCE(P_LHS_Nlabel_opt_RHS_TLABEL), [T_LLD]=REDUCE(P_LHS_Nlabel_opt_RHS_TLABEL), [T_FORK]=REDUCE(P_LHS_Nlabel_opt_RHS_TLABEL), [T_STI]=REDUCE(P_LHS_Nlabel_opt_RHS_TLABEL), [T_LFORK]=REDUCE(P_LHS_Nlabel_opt_RHS_TLABEL), [T_NEWLINE]=REDUCE(P_LHS_Nlabel_opt_RHS_TLABEL)},
/*  17 */	{[T_NEWLINE]=SHIFT(106)},
/*  18 */	{[T_NEWLINE]=REDUCE(P_LHS_Nmixed_instr_RHS_Nlfork_instr)},
/*  19 */	{[T_NEWLINE]=REDUCE(P_LHS_Nmixed_instr_RHS_Nsti_instr)},
/*  20 */	{[T_NEWLINE]=REDUCE(P_LHS_Nmixed_instr_RHS_Nfork_instr)},
/*  21 */	{[T_NEWLINE]=REDUCE(P_LHS_Nmixed_instr_RHS_Nlld_instr)},
/*  22 */	{[T_NEWLINE]=REDUCE(P_LHS_Nmixed_instr_RHS_Nld_instr)},
/*  23 */	{[T_NEWLINE]=REDUCE(P_LHS_Nmixed_instr_RHS_Nadd_instr)},
/*  24 */	{[T_NEWLINE]=REDUCE(P_LHS_Nmixed_instr_RHS_Nzjmp_instr)},
/*  25 */	{[T_NEWLINE]=REDUCE(P_LHS_Nmixed_instr_RHS_Nsub_instr)},
/*  26 */	{[T_NEWLINE]=REDUCE(P_LHS_Nmixed_instr_RHS_Nldi_instr)},
/*  27 */	{[T_NEWLINE]=REDUCE(P_LHS_Nmixed_instr_RHS_Nor_instr)},
/*  28 */	{[T_NEWLINE]=REDUCE(P_LHS_Nmixed_instr_RHS_Naff_instr)},
/*  29 */	{[T_NEWLINE]=REDUCE(P_LHS_Nmixed_instr_RHS_Nlive_instr)},
/*  30 */	{[T_NEWLINE]=REDUCE(P_LHS_Nmixed_instr_RHS_Nxor_instr)},
/*  31 */	{[T_NEWLINE]=REDUCE(P_LHS_Nmixed_instr_RHS_Nlldi_instr)},
/*  32 */	{[T_NEWLINE]=REDUCE(P_LHS_Nmixed_instr_RHS_Nand_instr)},
/*  33 */	{[T_DIRECT]=SHIFT(105)},
/*  34 */	{[T_REG]=SHIFT(100)},
/*  35 */	{[T_DIRECT]=SHIFT(99)},
/*  36 */	{[T_INDIRECT]=SHIFT(92), [T_DIRECT]=SHIFT(91)},
/*  37 */	{[T_INDIRECT]=SHIFT(92), [T_DIRECT]=SHIFT(91)},
/*  38 */	{[T_REG]=SHIFT(86)},
/*  39 */	{[T_DIRECT]=SHIFT(85)},
/*  40 */	{[T_REG]=SHIFT(80)},
/*  41 */	{[T_INDIRECT]=SHIFT(50), [T_DIRECT]=SHIFT(49), [T_REG]=SHIFT(48)},
/*  42 */	{[T_INDIRECT]=SHIFT(50), [T_DIRECT]=SHIFT(49), [T_REG]=SHIFT(48)},
/*  43 */	{[T_REG]=SHIFT(69)},
/*  44 */	{[T_DIRECT]=SHIFT(68)},
/*  45 */	{[T_INDIRECT]=SHIFT(50), [T_DIRECT]=SHIFT(49), [T_REG]=SHIFT(48)},
/*  46 */	{[T_INDIRECT]=SHIFT(50), [T_DIRECT]=SHIFT(49), [T_REG]=SHIFT(48)},
/*  47 */	{[T_INDIRECT]=SHIFT(50), [T_DIRECT]=SHIFT(49), [T_REG]=SHIFT(48)},
/*  48 */	{[T_SEP]=REDUCE(P_LHS_Nall_RHS_TREG)},
/*  49 */	{[T_SEP]=REDUCE(P_LHS_Nall_RHS_TDIRECT)},
/*  50 */	{[T_SEP]=REDUCE(P_LHS_Nall_RHS_TINDIRECT)},
/*  51 */	{[T_SEP]=SHIFT(52)},
/*  52 */	{[T_INDIRECT]=SHIFT(50), [T_DIRECT]=SHIFT(49), [T_REG]=SHIFT(48)},
/*  53 */	{[T_SEP]=SHIFT(54)},
/*  54 */	{[T_REG]=SHIFT(55)},
/*  55 */	{[T_NEWLINE]=REDUCE(P_LHS_Nand_instr_RHS_TAND_Nall_TSEP_Nall_TSEP_TREG)},
/*  56 */	{[T_SEP]=SHIFT(57)},
/*  57 */	{[T_DIRECT]=SHIFT(60), [T_REG]=SHIFT(59)},
/*  58 */	{[T_SEP]=SHIFT(61)},
/*  59 */	{[T_SEP]=REDUCE(P_LHS_Nregdir_RHS_TREG), [T_NEWLINE]=REDUCE(P_LHS_Nregdir_RHS_TREG)},
/*  60 */	{[T_SEP]=REDUCE(P_LHS_Nregdir_RHS_TDIRECT), [T_NEWLINE]=REDUCE(P_LHS_Nregdir_RHS_TDIRECT)},
/*  61 */	{[T_REG]=SHIFT(62)},
/*  62 */	{[T_NEWLINE]=REDUCE(P_LHS_Nlldi_instr_RHS_TLLDI_Nall_TSEP_Nregdir_TSEP_TREG)},
/*  63 */	{[T_SEP]=SHIFT(64)},
/*  64 */	{[T_INDIRECT]=SHIFT(50), [T_DIRECT]=SHIFT(49), [T_REG]=SHIFT(48)},
/*  65 */	{[T_SEP]=SHIFT(66)},
/*  66 */	{[T_REG]=SHIFT(67)},
/*  67 */	{[T_NEWLINE]=REDUCE(P_LHS_Nxor_instr_RHS_TXOR_Nall_TSEP_Nall_TSEP_TREG)},
/*  68 */	{[T_NEWLINE]=REDUCE(P_LHS_Nlive_instr_RHS_TLIVE_TDIRECT)},
/*  69 */	{[T_NEWLINE]=REDUCE(P_LHS_Naff_instr_RHS_TAFF_TREG)},
/*  70 */	{[T_SEP]=SHIFT(71)},
/*  71 */	{[T_INDIRECT]=SHIFT(50), [T_DIRECT]=SHIFT(49), [T_REG]=SHIFT(48)},
/*  72 */	{[T_SEP]=SHIFT(73)},
/*  73 */	{[T_REG]=SHIFT(74)},
/*  74 */	{[T_NEWLINE]=REDUCE(P_LHS_Nor_instr_RHS_TOR_Nall_TSEP_Nall_TSEP_TREG)},
/*  75 */	{[T_SEP]=SHIFT(76)},
/*  76 */	{[T_DIRECT]=SHIFT(60), [T_REG]=SHIFT(59)},
/*  77 */	{[T_SEP]=SHIFT(78)},
/*  78 */	{[T_REG]=SHIFT(79)},
/*  79 */	{[T_NEWLINE]=REDUCE(P_LHS_Nldi_instr_RHS_TLDI_Nall_TSEP_Nregdir_TSEP_TREG)},
/*  80 */	{[T_SEP]=SHIFT(81)},
/*  81 */	{[T_REG]=SHIFT(82)},
/*  82 */	{[T_SEP]=SHIFT(83)},
/*  83 */	{[T_REG]=SHIFT(84)},
/*  84 */	{[T_NEWLINE]=REDUCE(P_LHS_Nsub_instr_RHS_TSUB_TREG_TSEP_TREG_TSEP_TREG)},
/*  85 */	{[T_NEWLINE]=REDUCE(P_LHS_Nzjmp_instr_RHS_TZJMP_TDIRECT)},
/*  86 */	{[T_SEP]=SHIFT(87)},
/*  87 */	{[T_REG]=SHIFT(88)},
/*  88 */	{[T_SEP]=SHIFT(89)},
/*  89 */	{[T_REG]=SHIFT(90)},
/*  90 */	{[T_NEWLINE]=REDUCE(P_LHS_Nadd_instr_RHS_TADD_TREG_TSEP_TREG_TSEP_TREG)},
/*  91 */	{[T_SEP]=REDUCE(P_LHS_Ndirind_RHS_TDIRECT)},
/*  92 */	{[T_SEP]=REDUCE(P_LHS_Ndirind_RHS_TINDIRECT)},
/*  93 */	{[T_SEP]=SHIFT(94)},
/*  94 */	{[T_REG]=SHIFT(95)},
/*  95 */	{[T_NEWLINE]=REDUCE(P_LHS_Nld_instr_RHS_TLD_Ndirind_TSEP_TREG)},
/*  96 */	{[T_SEP]=SHIFT(97)},
/*  97 */	{[T_REG]=SHIFT(98)},
/*  98 */	{[T_NEWLINE]=REDUCE(P_LHS_Nlld_instr_RHS_TLLD_Ndirind_TSEP_TREG)},
/*  99 */	{[T_NEWLINE]=REDUCE(P_LHS_Nfork_instr_RHS_TFORK_TDIRECT)},
/* 100 */	{[T_SEP]=SHIFT(101)},
/* 101 */	{[T_INDIRECT]=SHIFT(50), [T_DIRECT]=SHIFT(49), [T_REG]=SHIFT(48)},
/* 102 */	{[T_SEP]=SHIFT(103)},
/* 103 */	{[T_DIRECT]=SHIFT(60), [T_REG]=SHIFT(59)},
/* 104 */	{[T_NEWLINE]=REDUCE(P_LHS_Nsti_instr_RHS_TSTI_TREG_TSEP_Nall_TSEP_Nregdir)},
/* 105 */	{[T_NEWLINE]=REDUCE(P_LHS_Nlfork_instr_RHS_TLFORK_TDIRECT)},
/* 106 */	{[T_EOF]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_AND]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_LLDI]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_XOR]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_LIVE]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_AFF]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_OR]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_LDI]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_SUB]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_ZJMP]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_ADD]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_LD]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_LLD]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_FORK]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_STI]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_LFORK]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_LABEL]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE), [T_NEWLINE]=REDUCE(P_LHS_Nasm_layout_RHS_Nlabel_opt_Nmixed_instr_TNEWLINE)},
/* 107 */	{[T_EOF]=REDUCE(P_LHS_Nlist_RHS_Nasm_layout_Nlist_PRIME)},
/* 108 */	{[T_LABEL]=SHIFT(16), [T_AND]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LLDI]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_XOR]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LIVE]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_AFF]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_OR]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LDI]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_SUB]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_ZJMP]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_ADD]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LD]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LLD]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_FORK]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_STI]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_LFORK]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_NEWLINE]=REDUCE(P_LHS_Nlabel_opt_RHS), [T_EOF]=REDUCE(P_LHS_Nlist_PRIME_RHS)},
/* 109 */	{[T_EOF]=REDUCE(P_LHS_Nlist_PRIME_RHS_Nasm_layout_Nlist_PRIME)},
};

static int
corewar_lr_goto_table[110][TOTAL_NTER] = {
/*   0 */	{[N_comment]=GOTO(4), [N_name]=GOTO(3), [N_prolog]=GOTO(2), [N_program]=GOTO(1)},
/*   1 */	{},
/*   2 */	{[N_label_opt]=GOTO(15), [N_asm_layout]=GOTO(14), [N_list]=GOTO(13)},
/*   3 */	{[N_comment]=GOTO(12)},
/*   4 */	{[N_name]=GOTO(11)},
/*   5 */	{},
/*   6 */	{},
/*   7 */	{},
/*   8 */	{},
/*   9 */	{},
/*  10 */	{},
/*  11 */	{},
/*  12 */	{},
/*  13 */	{},
/*  14 */	{[N_asm_layout]=GOTO(108), [N_list_PRIME]=GOTO(107), [N_label_opt]=GOTO(15)},
/*  15 */	{[N_and_instr]=GOTO(32), [N_lldi_instr]=GOTO(31), [N_xor_instr]=GOTO(30), [N_live_instr]=GOTO(29), [N_aff_instr]=GOTO(28), [N_or_instr]=GOTO(27), [N_ldi_instr]=GOTO(26), [N_sub_instr]=GOTO(25), [N_zjmp_instr]=GOTO(24), [N_add_instr]=GOTO(23), [N_ld_instr]=GOTO(22), [N_lld_instr]=GOTO(21), [N_fork_instr]=GOTO(20), [N_sti_instr]=GOTO(19), [N_lfork_instr]=GOTO(18), [N_mixed_instr]=GOTO(17)},
/*  16 */	{},
/*  17 */	{},
/*  18 */	{},
/*  19 */	{},
/*  20 */	{},
/*  21 */	{},
/*  22 */	{},
/*  23 */	{},
/*  24 */	{},
/*  25 */	{},
/*  26 */	{},
/*  27 */	{},
/*  28 */	{},
/*  29 */	{},
/*  30 */	{},
/*  31 */	{},
/*  32 */	{},
/*  33 */	{},
/*  34 */	{},
/*  35 */	{},
/*  36 */	{[N_dirind]=GOTO(96)},
/*  37 */	{[N_dirind]=GOTO(93)},
/*  38 */	{},
/*  39 */	{},
/*  40 */	{},
/*  41 */	{[N_all]=GOTO(75)},
/*  42 */	{[N_all]=GOTO(70)},
/*  43 */	{},
/*  44 */	{},
/*  45 */	{[N_all]=GOTO(63)},
/*  46 */	{[N_all]=GOTO(56)},
/*  47 */	{[N_all]=GOTO(51)},
/*  48 */	{},
/*  49 */	{},
/*  50 */	{},
/*  51 */	{},
/*  52 */	{[N_all]=GOTO(53)},
/*  53 */	{},
/*  54 */	{},
/*  55 */	{},
/*  56 */	{},
/*  57 */	{[N_regdir]=GOTO(58)},
/*  58 */	{},
/*  59 */	{},
/*  60 */	{},
/*  61 */	{},
/*  62 */	{},
/*  63 */	{},
/*  64 */	{[N_all]=GOTO(65)},
/*  65 */	{},
/*  66 */	{},
/*  67 */	{},
/*  68 */	{},
/*  69 */	{},
/*  70 */	{},
/*  71 */	{[N_all]=GOTO(72)},
/*  72 */	{},
/*  73 */	{},
/*  74 */	{},
/*  75 */	{},
/*  76 */	{[N_regdir]=GOTO(77)},
/*  77 */	{},
/*  78 */	{},
/*  79 */	{},
/*  80 */	{},
/*  81 */	{},
/*  82 */	{},
/*  83 */	{},
/*  84 */	{},
/*  85 */	{},
/*  86 */	{},
/*  87 */	{},
/*  88 */	{},
/*  89 */	{},
/*  90 */	{},
/*  91 */	{},
/*  92 */	{},
/*  93 */	{},
/*  94 */	{},
/*  95 */	{},
/*  96 */	{},
/*  97 */	{},
/*  98 */	{},
/*  99 */	{},
/* 100 */	{},
/* 101 */	{[N_all]=GOTO(102)},
/* 102 */	{},
/* 103 */	{[N_regdir]=GOTO(104)},
/* 104 */	{},
/* 105 */	{},
/* 106 */	{},
/* 107 */	{},
/* 108 */	{[N_list_PRIME]=GOTO(109), [N_asm_layout]=GOTO(108), [N_label_opt]=GOTO(15)},
/* 109 */	{},
};

#endif

static int
corewar_sync_token[TOTAL_NTER][19] = {
	[N_program] = { T_EOF, -1 },
	[N_prolog] = { T_NEWLINE, T_LABEL, T_LFORK, T_STI, T_FORK, T_LLD, T_LD, T_ADD, T_ZJMP, T_SUB, T_LDI, T_OR, T_AFF, T_LIVE, T_XOR, T_LLDI, T_AND, -1 },
	[N_list] = { T_EOF, -1 },
	[N_name] = { T_NEWLINE, T_COMMENT, T_LABEL, T_LFORK, T_STI, T_FORK, T_LLD, T_LD, T_ADD, T_ZJMP, T_SUB, T_LDI, T_OR, T_AFF, T_LIVE, T_XOR, T_LLDI, T_AND, -1 },
	[N_comment] = { T_NAME, T_NEWLINE, T_LABEL, T_LFORK, T_STI, T_FORK, T_LLD, T_LD, T_ADD, T_ZJMP, T_SUB, T_LDI, T_OR, T_AFF, T_LIVE, T_XOR, T_LLDI, T_AND, -1 },
	[N_asm_layout] = { T_NEWLINE, T_LABEL, T_LFORK, T_STI, T_FORK, T_LLD, T_LD, T_ADD, T_ZJMP, T_SUB, T_LDI, T_OR, T_AFF, T_LIVE, T_XOR, T_LLDI, T_AND, T_EOF, -1 },
	[N_list_PRIME] = { T_EOF, -1 },
	[N_label_opt] = { T_NEWLINE, T_LFORK, T_STI, T_FORK, T_LLD, T_LD, T_ADD, T_ZJMP, T_SUB, T_LDI, T_OR, T_AFF, T_LIVE, T_XOR, T_LLDI, T_AND, -1 },
	[N_mixed_instr] = { T_NEWLINE, -1 },
	[N_lfork_instr] = { T_NEWLINE, -1 },
	[N_sti_instr] = { T_NEWLINE, -1 },
	[N_fork_instr] = { T_NEWLINE, -1 },
	[N_lld_instr] = { T_NEWLINE, -1 },
	[N_ld_instr] = { T_NEWLINE, -1 },
	[N_add_instr] = { T_NEWLINE, -1 },
	[N_zjmp_instr] = { T_NEWLINE, -1 },
	[N_sub_instr] = { T_NEWLINE, -1 },
	[N_ldi_instr] = { T_NEWLINE, -1 },
	[N_or_instr] = { T_NEWLINE, -1 },
	[N_aff_instr] = { T_NEWLINE, -1 },
	[N_live_instr] = { T_NEWLINE, -1 },
	[N_xor_instr] = { T_NEWLINE, -1 },
	[N_lldi_instr] = { T_NEWLINE, -1 },
	[N_and_instr] = { T_NEWLINE, -1 },
	[N_all] = { T_SEP, -1 },
	[N_regdir] = { T_NEWLINE, T_SEP, -1 },
	[N_dirind] = { T_SEP, -1 },
};

#endif /* _COREWAR_GRM_H_ */