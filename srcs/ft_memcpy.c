/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:12:41 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/12 17:41:47 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dst != NULL && src != NULL && src != dst && n != 0)
	{
		d = (unsigned char *)dst;
		s = (unsigned char *)src;
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
