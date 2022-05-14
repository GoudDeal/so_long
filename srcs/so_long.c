/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:14:01 by user42            #+#    #+#             */
/*   Updated: 2022/01/21 13:42:49 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_them_all(t_ptr *ptr, int mode)
{
	int	i;

	i = 0;
	while (ptr->map->map[i])
	{
		free(ptr->map->map[i]);
		i++;
	}
	free(ptr->map->map);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img->wall);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img->player);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img->collectible);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img->exit);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img->free_space);
	if (mode == 1)
		mlx_destroy_window(ptr->mlx_ptr, ptr->mlx_win);
	mlx_destroy_display(ptr->mlx_ptr);
	free(ptr->map);
	free(ptr->img);
	free(ptr->mlx_ptr);
	free(ptr);
}

int	main(int ac, char **av)
{
	t_ptr	*ptr;

	ptr = malloc(sizeof(t_ptr));
	ptr->mlx_ptr = mlx_init();
	ptr->map = init_t_map(ac, av[1], av);
	ptr->img = init_images(ptr->map, ptr->mlx_ptr);
	ptr->map->horizontal = ft_strlen(ptr->map->map[0]);
	if (ptr->map->error == EXIT_FAILURE)
	{
		free_them_all(ptr, 0);
		return (EXIT_FAILURE);
	}
	if (verify_map(ptr->map) == EXIT_FAILURE
		|| verify_keys(ptr->map) == EXIT_FAILURE)
	{
		write(2, "Error\nIncorrect map format\n", 27);
		free_them_all(ptr, 0);
		return (EXIT_FAILURE);
	}
	ptr->mlx_win = mlx_new_window(ptr->mlx_ptr, ptr->img->free_space->width
			* ptr->map->horizontal, ptr->img->free_space->height
			* ptr->map->vertical, "So_long");
	launch(ptr);
	free_them_all(ptr, 1);
	return (0);
}
