/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:14:01 by user42            #+#    #+#             */
/*   Updated: 2022/01/12 01:04:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx-linux/mlx.h"

void	my_mlx_pixel_puts(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		i;
	int		j;
	t_data	img;

	i = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "on se fait chier");
	img.img = mlx_new_image(mlx, 600,600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	while (i < 599)
	{
		my_mlx_pixel_puts(&img, i, 0, 0x00ff0000);
	
		i++;
	}
	j = i;
	while (i > 0)
	{
		my_mlx_pixel_puts(&img, 0, i, 0x00ff0000);
	
		i--;
	}
	while (i < 599)
	{
		my_mlx_pixel_puts(&img, i, j, 0x00ff0000);
		i++;
	}
	while (i > 0)
	{
		my_mlx_pixel_puts(&img, j, i, 0x00ff0000);
		i--;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (1);
}