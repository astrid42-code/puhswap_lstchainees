/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:20:58 by asgaulti          #+#    #+#             */
/*   Updated: 2020/11/25 16:39:17 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*copydst;
	unsigned const char	*copysrc;

	i = 0;
	copydst = dst;
	copysrc = src;
	if ((copydst == NULL) && (copysrc == NULL))
		return (NULL);
	while (i < n)
	{
		*(copydst + i) = *(copysrc + i);
		if (*(copysrc + i) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
