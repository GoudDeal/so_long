/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:17:27 by user42            #+#    #+#             */
/*   Updated: 2022/01/19 15:19:38 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_wall(t_ptr *ptr, int i, int j)
{
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img->free_space,
		ptr->img->free_space->width * j, ptr->img->free_space->height * i);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img->wall,
		ptr->img->wall->width * j, (ptr->img->free_space->height * i) + 16);
}

void	put_exit(t_ptr *ptr, int i, int j)
{
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img->free_space,
		ptr->img->free_space->width * j, ptr->img->free_space->height * i);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img->exit,
		(ptr->img->free_space->width * j) + 8,
		(ptr->img->free_space->height * i) + 8);
}

void	put_collectible(t_ptr *ptr, int i, int j)
{
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img->free_space,
		ptr->img->free_space->width * j, ptr->img->free_space->height * i);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img->collectible,
		(ptr->img->free_space->width * j) + 8,
		(ptr->img->free_space->height * i) + 8);
}

void	put_player(t_ptr *ptr, int i, int j)
{
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img->free_space,
		ptr->img->free_space->width * j, ptr->img->free_space->height * i);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img->player,
		(ptr->img->free_space->width * j) + 4,
		(ptr->img->free_space->height * i) + 4);
}

void	put_grass(t_ptr *ptr, int i, int j)
{
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
		ptr->img->free_space, ptr->img->free_space->width * j,
		ptr->img->free_space->height * i);
}
