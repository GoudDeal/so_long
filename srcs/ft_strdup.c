/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:53:25 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/14 17:45:00 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	if (s1 != NULL)
	{
		copy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
		if (!(copy))
			return (NULL);
		ft_memmove(copy, s1, ft_strlen(s1) + 1);
		return (copy);
	}
	return (NULL);
}
