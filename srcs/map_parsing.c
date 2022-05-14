/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:39:52 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/21 13:48:45 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strdup_newline(char	*str)
{
	int		i;
	char	*new;

	i = 0;
	if (str)
	{
		if (ft_strchr(str, '\n'))
			new = malloc(sizeof(char) * ft_strlen(str));
		else
			new = malloc(sizeof(char) * (ft_strlen(str) + 1));
		while (str[i] != '\0' && str[i] != '\n')
		{
			new[i] = str[i];
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}

int	verify_walls(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!map)
		return (EXIT_FAILURE);
	while (map->map[0][i])
	{	
		if (map->map[0][i] != '1' || map->map[map->vertical - 1][i] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	i -= 1;
	while (map->map[j])
	{
		if (map->map[j][0] != '1' || map->map[j][i] != '1')
			return (EXIT_FAILURE);
		j++;
	}
	return (EXIT_SUCCESS);
}

int	get_map(int fd, char *av, t_map **map)
{
	int		i;
	char	*tmp;

	i = 0;
	if (av)
	{
		fd = open(av, O_RDONLY);
		if (fd == -1)
		{
			write(2, "Error\nUnable to open map\n", 25);
			return (EXIT_FAILURE);
		}
		while (i < (*map)->vertical)
		{
			(*map)->moves = 0;
			tmp = get_next_line(fd);
			(*map)->map[i] = ft_strdup_newline(tmp);
			free(tmp);
			i++;
		}
		return (i - 1);
	}
	else
		write(2, "Error\nUsage : ./so_long [filename].ber\n", 39);
	return (EXIT_FAILURE);
}

int	verify_param(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j] != '\0')
		{
			if (map->map[i][j] == 'C')
				map->collectible += 1;
			if (map->map[i][j] == 'E')
				map->exit += 1;
			if (map->map[i][j] == 'P')
			{
				map->pos_x = j;
				map->pos_y = i;
				map->start += 1;
			}
		}
	}
	if (map->exit != 1 || map->collectible == 0 || map->start != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	verify_map(t_map *map)
{
	size_t	length;
	int		i;

	length = 0;
	i = 0;
	if (!map)
		return (EXIT_FAILURE);
	if (map->map[i])
		length = ft_strlen(map->map[i]);
	if (verify_param(map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (map->map[i])
	{	
		if (ft_strlen(map->map[i]) != length)
			return (EXIT_FAILURE);
		i++;
	}
	if (verify_walls(map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
