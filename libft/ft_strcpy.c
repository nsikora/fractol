/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 13:48:12 by nsikora           #+#    #+#             */
/*   Updated: 2017/11/22 17:27:03 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcpy(const char *dest, const char *src)
{
	int		i;
	char	*dest2;
	char	*src2;

	dest2 = (char *)dest;
	src2 = (char *)src;
	i = 0;
	while (src2[i] != '\0')
	{
		dest2[i] = src2[i];
		i++;
	}
	dest2[i] = src2[i];
	return (dest2);
}
