/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:22:35 by asgaulti          #+#    #+#             */
/*   Updated: 2020/11/25 17:40:21 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*copys;

	i = 0;
	copys = (void *)s;
	while (i < n)
	{
		if (copys[i] == (unsigned char)c)
			return (copys + i);
		i++;
	}
	return (NULL);
}
