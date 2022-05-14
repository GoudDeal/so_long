/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:53:24 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/20 15:06:25 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_collectible(t_ptr *ptr)
{
	ptr->map->collectible -= 1;
	if (ptr->map->map[ptr->map->pos_y][ptr->map->pos_x - 1] == 'C')
		ptr->map->map[ptr->map->pos_y][ptr->map->pos_x - 1] = '0';
	if (ptr->map->map[ptr->map->pos_y - 1][ptr->map->pos_x] == 'C')
		ptr->map->map[ptr->map->pos_y - 1][ptr->map->pos_x] = '0';
	if (ptr->map->map[ptr->map->pos_y][ptr->map->pos_x + 1] == 'C')
		ptr->map->map[ptr->map->pos_y][ptr->map->pos_x + 1] = '0';
	if (ptr->map->map[ptr->map->pos_y + 1][ptr->map->pos_x] == 'C')
		ptr->map->map[ptr->map->pos_y + 1][ptr->map->pos_x] = '0';
}

int	move(int keycode, void *ptr)
{
	t_ptr	*act;

	act = (t_ptr *)ptr;
	if (keycode == 100)
		move_right(act, act->map);
	if (keycode == 119)
		move_up(act, act->map);
	if (keycode == 97)
		move_left(act, act->map);
	if (keycode == 115)
		move_down(act, act->map);
	if (keycode == 65307)
		exit_window(act);
	return (1);
}

int	exit_window(void *ptr)
{
	t_ptr	*act;

	act = (t_ptr *)ptr;
	free_them_all(act, 1);
	exit(1);
}
