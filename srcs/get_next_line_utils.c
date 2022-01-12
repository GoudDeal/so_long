/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:42:51 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/12 00:16:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t			ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i] != '\0')
		i++;
	return ((size_t)i);
}

char			*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		len;

	if (s1 == NULL)
		return (NULL);
	len = (int)ft_strlen(s1);
	i = 0;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = malloc(sizeof(char*) * (ft_strlen(s1) + (ft_strlen(s2)) + 1))))
		return (NULL);
	while (s1[j])
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	if (s != NULL)
	{
		i = 0;
		if (start >= ft_strlen((char *)s) || !(*s) || len == 0)
			return (ft_strdup("\0"));
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (s[start + i] && i < len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (ft_strdup("\0"));
}

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	sizesrc;

	if (src == NULL || dst == NULL)
		return (0);
	sizesrc = ft_strlen((char*)src);
	i = 0;
	if (dstsize == 0)
		return (sizesrc);
	while (src[i] && i < (int)(dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (sizesrc);
}
