/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:28:15 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/20 15:09:17 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	get_n_word(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (s[j])
	{
		if ((s[j] == c && s[j - 1] != c && s[j + 1])
			|| (s[j] != c && s[j + 1] == '\0'))
			i++;
		j++;
	}
	return (i);
}

char	*extract_word(const char *s, char c)
{
	int	end;

	end = 0;
	while (s[end] && s[end] != c)
		end++;
	return (ft_substr(s, 0, end));
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	n_word;
	size_t	j;

	if (s != NULL && c && *s != 0)
	{
		j = 0;
		n_word = get_n_word(s, c);
		result = ft_calloc(n_word + 1, sizeof(char *));
		if (!result)
			return (NULL);
		while (j < n_word && *s)
		{
			while (*s == c)
				s++;
			result[j] = extract_word(s, c);
			s = ft_strchr(s, c);
			j++;
		}
		result[j] = NULL;
		return (result);
	}
	return ((char **)ft_calloc(2, sizeof(char *)));
}
