/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:36:45 by ldevelle          #+#    #+#             */
/*   Updated: 2019/10/22 00:59:50 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
# define MEM_SIZE				(4*1024)

# define IDX_MOD				(MEM_SIZE / 8)



uint32_t	pc_access(uint32_t pc, int32_t add, uint8_t idx_mod)
{
	DEBUG_FUNC;
	uint32_t pc_tmp;

	ft_printf("pc: %4u\tadd: %6d\tidx?%d\n", pc, add, idx_mod);
	while (add < 0)
		add += MEM_SIZE;//1095
	ft_printf("add after while add: %d\n", add);
	if (idx_mod && ft_printf("IDX MODE ON\n"))//y
	{
		ft_printf("\tpc_tmp = (pc + add) %% MEM_SIZE\n");
		pc_tmp = (pc + add) % MEM_SIZE;//pc_tmp=1095
		ft_printf("\t%u = %u + %d %% %d\n", pc_tmp, pc , add, MEM_SIZE);
		if (ft_printf("\tif (ft_abs(pc - pc_tmp) > IDX_MOD)\n\tft_abs(%u - %u) > %d\n", pc, pc_tmp, IDX_MOD) && ft_abs(pc - pc_tmp) > IDX_MOD)//y
		{
			if (ft_printf("\t\tif (pc < pc_tmp)\n\t\t%u < %u\n",pc, pc_tmp) && pc > pc_tmp)
			{
				ft_printf("\t\t\tpc_tmp = pc - (ft_abs(pc - pc_tmp) %% IDX_MOD)\n");
				ft_printf("\t\t\t%u = %u - (ft_abs(%u - %u) %% %d)\n", pc - (ft_abs(pc - pc_tmp) % IDX_MOD), pc, pc, pc_tmp, IDX_MOD);
				pc_tmp = pc - (ft_abs(pc - pc_tmp) % IDX_MOD);//-1095%512=-71
			}
			else
			{
				ft_printf("\t\t\tpc_tmp = pc + (ft_abs(pc - pc_tmp) %% IDX_MOD)\n");
				ft_printf("\t\t\t%u = %u + (ft_abs(%u - %u) %% %d)\n", pc + (ft_abs(pc - pc_tmp) % IDX_MOD), pc, pc, pc_tmp, IDX_MOD);
				pc_tmp = pc + (ft_abs(pc - pc_tmp) % IDX_MOD);
			}
		}
		pc = pc_tmp;
	}
	else
		pc += add;
	ft_printf("PC IS %u\n", pc);
	while (pc < 0)
		pc += MEM_SIZE;//4025
	ft_printf("PC AFTER ADD %u\n", pc);
	pc = pc % MEM_SIZE;
	ft_printf("PC (after modulo) IS FINALLY %u\n", pc);
	return (pc);
}

int		main(int ac, char **av)
{
	// uint32_t	pc = 0;
	// int32_t		add = -2001;
	// uint8_t		idx_mod = 1;

	if (ac != 2)
		return (0);
	// add = 0xfff4;
	// pc_access(pc, add, idx_mod);
	ft_printf("%r%s\n", ft_str_rgbcolor(0, 500, 100, 150));
	(void)av;
	return (0);
}
