/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:00:38 by nsikora           #+#    #+#             */
/*   Updated: 2017/11/21 15:27:14 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	c2;

	i = 0;
	str = (unsigned char*)s;
	c2 = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == c2)
			return (str + i);
		i++;
	}
	return (0);
}
