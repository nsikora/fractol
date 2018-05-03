/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:22:42 by nsikora           #+#    #+#             */
/*   Updated: 2017/11/16 11:47:59 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*str;

	if (size >= 128 * 1024 * 1024)
		return (0);
	if (!(str = malloc(size + 1)))
		return (0);
	ft_memset(str, 0, size);
	return (str);
}
