/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:18:37 by nsikora           #+#    #+#             */
/*   Updated: 2017/11/20 08:47:41 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_getnbwords(char const *s, char c)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			nb++;
		i++;
	}
	return (nb);
}

static char	**ft_alloctab(char **tab, int nb, char const *s, char c)
{
	int		i;
	int		x;
	int		save;

	i = 0;
	x = 0;
	if (!(tab = malloc(sizeof(char *) * (nb + 1))))
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			save = i;
		if ((s[i] == c && s[i - 1] != c && i != 0) ||
				(s[i] != c && s[i + 1] == '\0'))
		{
			if (!(tab[x] = malloc(sizeof(char) * (i - save))))
				return (0);
			x++;
		}
		i++;
	}
	return (tab);
}

static char	**ft_filltab(char **tab, char const *s, char c)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			tab[x][y] = s[i];
			y++;
		}
		if ((s[i] == c && s[i - 1] != c && i != 0) ||
				(s[i] != c && s[i + 1] == '\0'))
		{
			tab[x][y] = '\0';
			x++;
			y = 0;
		}
		i++;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nb;
	int		x;
	char	**tab;

	x = 0;
	if (!s)
		return (0);
	nb = ft_getnbwords(s, c);
	tab = 0;
	if ((tab = ft_alloctab(tab, nb, s, c)) == 0)
		return (0);
	tab = ft_filltab(tab, s, c);
	while (x <= nb)
	{
		if (x == nb)
			tab[x] = 0;
		x++;
	}
	return (tab);
}
