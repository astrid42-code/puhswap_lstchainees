/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:13:38 by asgaulti          #+#    #+#             */
/*   Updated: 2021/04/27 19:48:17 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*copy_s;

	i = 0;
	copy_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!copy_s)
		return (NULL);
	while (s1[i])
	{
		copy_s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		copy_s[i] = s2[j];
		i++;
		j++;
	}
	copy_s[i] = '\0';
	return (copy_s);
}
