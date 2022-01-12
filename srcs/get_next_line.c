/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:42:48 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/12 00:14:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		check_errors(int fd, char *str, char **line)
{
	if (fd == -1 || line == NULL)
	{
		return (-1);
	}
	if (BUFFER_SIZE <= 0)
		return (-1);
	if (!str)
	{
		if (!(str = malloc(sizeof(char) * BUFFER_SIZE)))
			return (-1);
	}
	return (1);
}

void	update_str(char **str, int i)
{
	char *tmp;

	if ((*str)[i + 1])
	{
		tmp = ft_strdup(&((*str)[i + 1]));
		free(*str);
		*str = tmp;
	}
	else
	{
		free(*str);
		*str = NULL;
	}
}

int		join_str(char **str, char *buffer)
{
	char	*new;

	if (*str == NULL && buffer != NULL)
	{
		*str = ft_strdup(buffer);
		return (1);
	}
	else if (*str != NULL)
	{
		new = ft_strjoin(*str, buffer);
		free(*str);
		*str = new;
		return (1);
	}
	return (0);
}

int		get_line(char **line, char **str)
{
	int		i;

	if (*str != NULL)
	{
		i = 0;
		while ((*str)[i])
		{
			if ((*str)[i] == '\n')
			{
				*line = ft_substr(*str, 0, i);
				update_str(str, i);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	int			ret;
	char		buf[BUFFER_SIZE + 1];

	if (fd >= 0 && BUFFER_SIZE > 0 && line != NULL && !read(fd, buf, 0))
	{
		while ((ret = read(fd, buf, BUFFER_SIZE)))
		{
			buf[ret] = '\0';
			join_str(&str, buf);
			if (get_line(line, &str))
				return (1);
		}
		if (get_line(line, &str))
			return (1);
		*line = str != NULL ? ft_strdup(str) : ft_strdup("");
		if (str != NULL)
		{
			free(str);
			str = NULL;
		}
		return (0);
	}
	return (-1);
}
