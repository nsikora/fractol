/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 08:27:05 by nsikora           #+#    #+#             */
/*   Updated: 2017/11/16 15:04:45 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	begin;
	size_t	end;
	size_t	i;
	char	*new;

	if (!s)
		return (0);
	begin = 0;
	end = 0;
	i = 0;
	while (ft_iswhitespace(s[i++]) == 1)
		begin++;
	while (s[i] != '\0')
		i++;
	while (ft_iswhitespace(s[i]) == 1 || (s[i] == '\0' && i > 0))
		i--;
	end = i;
	if (!(new = ft_strnew((end - begin) + 1)))
		return (0);
	i = 0;
	while (begin <= end)
		new[i++] = s[begin++];
	new[i] = '\0';
	return (new);
}
