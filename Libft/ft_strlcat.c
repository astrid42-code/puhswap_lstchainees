/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 09:30:23 by asgaulti          #+#    #+#             */
/*   Updated: 2020/11/30 15:56:04 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	size_t			len_src;
	unsigned int	len_dst;

	i = 0;
	len_src = ft_strlen(src);
	len_dst = (unsigned int)ft_strlen(dst);
	if (dstsize < len_dst)
		return (len_src + dstsize);
	while (src[i] && i + len_dst + 1 < dstsize)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
