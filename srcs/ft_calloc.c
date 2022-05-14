/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:15:36 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/20 15:10:27 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (count != 0 && size != 0)
	{
		mem = malloc(count * size);
		if (!mem)
			return (NULL);
		ft_bzero(mem, count * size);
		return (mem);
	}
	return (malloc(1));
}
