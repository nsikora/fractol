/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:35:13 by nsikora           #+#    #+#             */
/*   Updated: 2017/11/22 17:16:48 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*c_src;
	unsigned char	*c_dst;

	i = 0;
	c_src = (unsigned char*)src;
	c_dst = (unsigned char*)dst;
	if (c_src > c_dst)
	{
		while (i < len)
		{
			c_dst[i] = c_src[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			c_dst[len - 1] = c_src[len - 1];
			len--;
		}
	}
	return (dst);
}
