/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:57:21 by nsikora           #+#    #+#             */
/*   Updated: 2018/02/09 15:48:20 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 4096
# define CAST(x) ((t_gnl*)x->content)

int					get_next_line(const int fd, char **line);

typedef struct		s_gnl
{
	char			*str;
	int				index;
	int				len;
	int				size;
}					t_gnl;
#endif
