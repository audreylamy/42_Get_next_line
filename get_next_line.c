/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:51:13 by alamy             #+#    #+#             */
/*   Updated: 2017/12/18 18:44:59 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_start_to_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	str = ft_strsub(str, 0, i);
	return (str);
}

static	char	*ft_n_to_end(char *str)
{
	int		i;
	int		end;
	char	*tmp;

	i = 0;
	end = ft_strlen(str);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	tmp = ft_strsub(str, i + 1, end);
	free(str);
	return (tmp);
}

static	char	*ft_join_free(char *str, char *buffer, int nb)
{
	char	*tmp;

	buffer[nb] = '\0';
	tmp = ft_strjoin(str, buffer);
	free(str);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	int				nb;
	char			buffer[BUFF_SIZE + 1];
	static	char	*str;

	if (fd < 0 || line == 0)
		return (-1);
	if (str == NULL)
		str = ft_strnew(BUFF_SIZE);
	while ((!ft_strchr(str, '\n')) && (nb = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		str = ft_join_free(str, buffer, nb);
	}
	if (nb == -1)
		return (-1);
	*line = ft_strchr(str, '\n') ? ft_start_to_n(str) : ft_strdup(str);
	if (ft_strchr(str, '\n'))
		str = ft_n_to_end(str);
	else
	{
		if (nb == 0 && str[0] == '\0')
			return (0);
		ft_strdel(&str);
	}
	return (1);
}