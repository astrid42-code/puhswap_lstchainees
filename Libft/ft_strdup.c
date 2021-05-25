/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:12:36 by asgaulti          #+#    #+#             */
/*   Updated: 2021/04/27 19:48:11 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*copy_s1;

	i = 0;
	copy_s1 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!copy_s1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy_s1[i] = (char)s1[i];
		i++;
	}
	copy_s1[i] = '\0';
	return (copy_s1);
}
