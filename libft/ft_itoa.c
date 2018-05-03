/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 08:27:07 by nsikora           #+#    #+#             */
/*   Updated: 2017/11/16 09:06:04 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fills(int n, int neg, int div, char *s)
{
	int	i;

	i = 0;
	if (neg == 1)
		s[i++] = '-';
	while (div >= 1)
	{
		s[i++] = n / div + 48;
		n = n % div;
		div = div / 10;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_itoa(int n)
{
	int		neg;
	int		div;
	int		len;
	char	*s;

	neg = 0;
	div = 1;
	len = 0;
	if (n == -2147483648)
		return (s = ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		neg = 1;
	}
	while (div <= n / 10)
	{
		div = div * 10;
		len++;
	}
	if (!(s = ft_strnew(len + neg + 1)))
		return (0);
	s = ft_fills(n, neg, div, s);
	return (s);
}
