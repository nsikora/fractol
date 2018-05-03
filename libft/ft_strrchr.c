/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:47:01 by nsikora           #+#    #+#             */
/*   Updated: 2017/11/22 17:25:22 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int	cp;
	int	coord;

	i = 0;
	cp = 0;
	coord = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			coord = i;
			cp++;
		}
		i++;
	}
	if (s[i] == c)
	{
		coord = i;
		cp++;
	}
	if (cp >= 1)
		return ((char *)s + coord);
	return (0);
}
