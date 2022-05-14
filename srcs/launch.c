/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:56:40 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/19 16:03:51 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_map(t_ptr *ptr)
{
	int	i;
	int	j;

	i = -1;
	while (ptr->map->map[++i])
	{
		j = -1;
		while (ptr->map->map[i][++j])
		{
			if (ptr->map->map[i][j] == '1')
				put_wall(ptr, i, j);
			if (ptr->map->map[i][j] == '0')
				put_grass(ptr, i, j);
			if (ptr->map->map[i][j] == 'E')
			{
				put_exit(ptr, i, j);
				ptr->map->exit_pos_x = i;
				ptr->map->exit_pos_y = j;
			}
			if (ptr->map->map[i][j] == 'C')
				put_collectible(ptr, i, j);
			if (ptr->map->map[i][j] == 'P')
				put_player(ptr, i, j);
		}
	}
}

void	launch(t_ptr *ptr)
{
	fill_map(ptr);
	mlx_hook(ptr->mlx_win, 02, 1L << 0, move, ptr);
	mlx_hook(ptr->mlx_win, 17, 1L << 17, exit_window, ptr);
	mlx_loop(ptr->mlx_ptr);
}
