# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaboujna <kaboujna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 21:14:05 by kaboujna          #+#    #+#              #
#    Updated: 2019/03/29 22:02:19 by kaboujna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 NAME    = asm
 
 NAME2   = corewar
 
 CC      = gcc

CFLAGS  =  -Wall -Wextra -Werror

SRCS    =   sasm/sources/main.c					\
			sasm/sources/lexer.c				\
			sasm/sources/read_file.c			\
			sasm/sources/utils.c				\
			sasm/sources/buffer.c				\
			sasm/sources/ir.c					\
			sasm/sources/gen_code.c				\
			sasm/sources/asm_parser.c

SRCS2    = 	vm/sources/cw_00_main.c				\
			vm/sources/op.c						\
			vm/sources/cw_01_parsing2.c			\
			vm/sources/cw_02_parsing1.c			\
			vm/sources/cw_03_aux.c				\
			vm/sources/cw_05_check_op.c			\
			vm/sources/cw_06_op.c				\
			vm/sources/cw_07_cpu.c				\
			vm/sources/cw_08_init_process.c		\
			vm/sources/cw_09_process_manager.c	\
			vm/sources/cw_10_reg_manager.c		\
			vm/sources/cw_11_aux_reg.c			\
			vm/sources/cw_12_usage.c			\
			vm/sources/cw_13_core.c				\
			vm/sources/cw_14_end_core.c			\
			vm/sources/functions/ft_and.c		\
			vm/sources/functions/ft_fork.c		\
			vm/sources/functions/ft_ld.c		\
			vm/sources/functions/ft_ldi.c		\
			vm/sources/functions/ft_lfork.c		\
			vm/sources/functions/ft_live.c		\
			vm/sources/functions/ft_lld.c		\
			vm/sources/functions/ft_lldi.c		\
			vm/sources/functions/ft_or.c		\
			vm/sources/functions/ft_st.c		\
			vm/sources/functions/ft_sti.c		\
			vm/sources/functions/ft_sub.c		\
			vm/sources/functions/ft_xor.c		\
			vm/sources/functions/ft_zjmp.c		\
			vm/sources/functions/ft_add.c		\
			vm/sources/functions/ft_aff.c		


LIBFT   =   libft/

HEADS	= -I ./vm/includes\
		  -I ./asm/includes

OBJS    = $(SRCS:%.c=%.o)
OBJS2    = $(SRCS2:%.c=%.o)

all:	$(NAME)  $(NAME2)

$(NAME):    $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)libft.a


$(NAME2):    $(OBJS2)
	@$(CC) $(HEADS) $(CFLAGS) -o $(NAME2) $(OBJS2) $(LIBFT)libft.a

%.o: %.c
	@$(CC) $(HEADS) $(CFLAGS) -c $< -o $@

clean:
	@/bin/rm -rf $(OBJS) $(OBJS2)
	@make -C $(LIBFT) clean
 
fclean:     clean
	@/bin/rm -rf asm corewar
	@make -C $(LIBFT) fclean
 
re: fclean all
