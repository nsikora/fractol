/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:33:43 by nsikora           #+#    #+#             */
/*   Updated: 2017/11/13 11:39:29 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	int		save;

	i = 0;
	j = 0;
	if (str[0] == '\0' && to_find[0] == '\0')
		return ((char *)str);
	if (str[0] == '\0' && to_find[0] != '\0')
		return (0);
	while (str[i] != '\0')
	{
		save = i;
		while (str[i] == to_find[j] || to_find[j] == '\0')
		{
			if (to_find[j] == '\0')
				return ((char *)str + save);
			i++;
			j++;
		}
		i = save;
		j = 0;
		i++;
	}
	return (0);
}
