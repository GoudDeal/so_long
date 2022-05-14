/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:05:37 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/20 14:59:14 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_ptr *ptr, t_map *map)
{
	int	i;
	int	y;

	if (map->map[map->pos_y - 1][map->pos_x] == '1')
		return ;
	if (map->map[map->pos_y - 1][map->pos_x] == 'C')
		update_collectible(ptr);
	if (map->collectible == 0)
	{
		mlx_destroy_image(ptr->mlx_ptr, ptr->img->exit);
		ptr->img->exit = mlx_xpm_file_to_image(ptr->mlx_ptr,
				"./imgs/exit_open.xpm", &i, &y);
		ptr->img->exit->height = y;
		ptr->img->exit->width = i;
	}
	if (map->map[map->pos_y - 1][map->pos_x] == 'E' && map->collectible == 0)
	{
		print_moves(ptr);
		exit_window(ptr);
	}
	put_grass(ptr, map->pos_y, map->pos_x);
	put_exit(ptr, map->exit_pos_x, map->exit_pos_y);
	put_player(ptr, ptr->map->pos_y - 1, ptr->map->pos_x);
	ptr->map->pos_y -= 1;
	print_moves(ptr);
}

void	move_left(t_ptr *ptr, t_map *map)
{
	int	i;
	int	y;

	if (map->map[map->pos_y][map->pos_x - 1] == '1')
		return ;
	if (map->map[map->pos_y][map->pos_x - 1] == 'C')
		update_collectible(ptr);
	if (map->collectible == 0)
	{
		mlx_destroy_image(ptr->mlx_ptr, ptr->img->exit);
		ptr->img->exit = mlx_xpm_file_to_image(ptr->mlx_ptr,
				"./imgs/exit_open.xpm", &i, &y);
		ptr->img->exit->height = y;
		ptr->img->exit->width = i;
	}
	if (map->map[map->pos_y][map->pos_x - 1] == 'E' && map->collectible == 0)
	{
		print_moves(ptr);
		exit_window(ptr);
	}
	put_grass(ptr, map->pos_y, map->pos_x);
	put_exit(ptr, map->exit_pos_x, map->exit_pos_y);
	put_player(ptr, map->pos_y, map->pos_x - 1);
	map->pos_x -= 1;
	print_moves(ptr);
}

void	move_right(t_ptr *ptr, t_map *map)
{
	int	i;
	int	y;

	if (map->map[map->pos_y][map->pos_x + 1] == '1')
		return ;
	if (map->map[map->pos_y][map->pos_x + 1] == 'C')
		update_collectible(ptr);
	if (map->collectible == 0)
	{
		mlx_destroy_image(ptr->mlx_ptr, ptr->img->exit);
		ptr->img->exit = mlx_xpm_file_to_image(ptr->mlx_ptr,
				"./imgs/exit_open.xpm", &i, &y);
		ptr->img->exit->height = y;
		ptr->img->exit->width = i;
	}
	if (map->map[map->pos_y][map->pos_x + 1] == 'E' && map->collectible == 0)
	{
		print_moves(ptr);
		exit_window(ptr);
	}
	put_grass(ptr, map->pos_y, map->pos_x);
	put_exit(ptr, map->exit_pos_x, map->exit_pos_y);
	put_player(ptr, map->pos_y, map->pos_x + 1);
	map->pos_x += 1;
	print_moves(ptr);
}

void	move_down(t_ptr *ptr, t_map *map)
{
	int	i;
	int	y;

	if (map->map[map->pos_y + 1][map->pos_x] == '1')
		return ;
	if (map->map[map->pos_y + 1][map->pos_x] == 'C')
		update_collectible(ptr);
	if (map->collectible == 0)
	{
		mlx_destroy_image(ptr->mlx_ptr, ptr->img->exit);
		ptr->img->exit = mlx_xpm_file_to_image(ptr->mlx_ptr,
				"./imgs/exit_open.xpm", &i, &y);
		ptr->img->exit->height = y;
		ptr->img->exit->width = i;
	}
	if (map->map[map->pos_y + 1][map->pos_x] == 'E' && map->collectible == 0)
	{
		print_moves(ptr);
		exit_window(ptr);
	}
	put_grass(ptr, map->pos_y, map->pos_x);
	put_exit(ptr, map->exit_pos_x, map->exit_pos_y);
	put_player(ptr, map->pos_y + 1, map->pos_x);
	map->pos_y += 1;
	print_moves(ptr);
}

void	print_moves(t_ptr *ptr)
{
	char	*str;

	ptr->map->moves += 1;
	str = ft_itoa(ptr->map->moves);
	printf("");
	put_wall(ptr, 0, 0);
	put_wall(ptr, 0, 1);
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 0, ptr->map->vertical + 5, WHITE,
		"You moved ");
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 60, ptr->map->vertical + 5,
		WHITE, str);
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, 80, ptr->map->vertical + 5,
		WHITE, " times");
	free(str);
}
