/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:54:22 by nsikora           #+#    #+#             */
/*   Updated: 2017/11/22 17:27:53 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)src;
	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (str[j] != '\0' && j < n)
	{
		dest[i] = str[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
