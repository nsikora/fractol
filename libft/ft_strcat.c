/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:46:05 by nsikora           #+#    #+#             */
/*   Updated: 2017/11/13 11:33:03 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcat(const char *dest, const char *src)
{
	int		i;
	int		j;
	char	*dest2;
	char	*src2;

	dest2 = (char *)dest;
	src2 = (char *)src;
	i = 0;
	j = 0;
	while (dest2[i] != '\0')
		i++;
	while (src2[j] != '\0')
	{
		dest2[i] = src2[j];
		j++;
		i++;
	}
	dest2[i] = '\0';
	return (dest2);
}
