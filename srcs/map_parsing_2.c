/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:12:10 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/19 17:16:20 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	verify_keys(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!ft_cinset(map->map[i][j], "01CPE"))
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
