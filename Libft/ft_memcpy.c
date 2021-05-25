/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:29:51 by asgaulti          #+#    #+#             */
/*   Updated: 2021/04/26 21:36:33 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*copydst;
	const char	*copysrc;

	i = 0;
	copydst = (char *)dst;
	copysrc = (const char *)src;
	if ((copydst == NULL) && (copysrc == NULL))
		return (NULL);
	while (i < n)
	{
		*(copydst + i) = *(copysrc + i);
		i++;
	}
	return (dst);
}
