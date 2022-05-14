/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:12:56 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/20 13:49:58 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*init_t_map(int ac, char *str, char **av)
{
	int		i;
	t_map	*new;
	int		fd;
	char	*line;

	i = 0;
	fd = open(av[1], O_RDONLY);
	new = (t_map *)malloc(sizeof(t_map));
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	new->map = (char **)malloc(sizeof(char *) * (i + 1));
	new->map[i] = NULL;
	new->vertical = i;
	new->collectible = 0;
	new->exit = 0;
	new->start = 0;
	new->error = get_map(ac, str, &new);
	new->horizontal = ft_strlen(new->map[0]);
	return (new);
}

void	set_images(t_data *img, void *mlx_ptr, int i, int y)
{
	img->wall = mlx_xpm_file_to_image(mlx_ptr, "./imgs/wall.xpm", &i, &y);
	img->wall->height = y;
	img->wall->width = i;
	img->player = mlx_xpm_file_to_image(mlx_ptr, "./imgs/cat.xpm", &i, &y);
	img->player->height = y;
	img->player->width = i;
	img->free_space = mlx_xpm_file_to_image(mlx_ptr,
			"./imgs/grass.xpm", &i, &y);
	img->free_space->height = y;
	img->free_space->width = i;
	img->exit = mlx_xpm_file_to_image(mlx_ptr, "./imgs/exit.xpm", &i, &y);
	img->exit->height = y;
	img->exit->width = i;
	img->collectible = mlx_xpm_file_to_image(mlx_ptr,
			"./imgs/fish.xpm", &i, &y);
	img->collectible->height = y;
	img->collectible->width = i;
}

t_data	*init_images(t_map *map, void *mlx_ptr)
{
	t_data	*img;
	int		y;
	int		i;

	i = 0;
	y = 0;
	img = malloc(sizeof(t_data));
	img->line_length = map->horizontal;
	set_images(img, mlx_ptr, 30, 30);
	img->endian = 0;
	return (img);
}
