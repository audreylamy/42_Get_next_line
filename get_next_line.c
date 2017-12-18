/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:51:13 by alamy             #+#    #+#             */
/*   Updated: 2017/12/18 14:39:09 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_start_from_n(char *str)
{
	int i;
	char *tmp;

	i = 0;
	tmp = str;
	while (str[i] != '\n')
		i++;
	tmp = ft_strsub(str, 0, i);
	return(tmp);
}

char *ft_n_from_end(char *str)
{
	int i;
	int end;
	char *tmp;

	i = 0;
	end = ft_strlen(str);
	while((str[i] != '\0') && (str[i] != '\n'))
		i++;
	tmp = ft_strsub(str, i + 1, end);
	free(str);
	return(tmp);
}

char *ft_join_free(char *str, char *buffer) 
{
	char *tmp;

	tmp = ft_strjoin(str, buffer);
	free(str);
	return (tmp);
}

int get_next_line(const int fd, char **line)
{
	int				nb;
	char			buffer[BUFF_SIZE + 1];
	static	char	*str;

	if (fd < 0 || !line)
        return (-1);
	if (str == NULL)
		str = ft_strnew(0);
	while ((nb = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[nb] = '\0';
		str = ft_join_free(str, buffer);
		if (strchr(str, '\n'))
		{
			*line = ft_start_from_n(str);
			str = ft_n_from_end(str);
			return(1);
		}
	}
	if (nb == -1)
        return (-1);
	if (!strchr(str, '\n'))
    {
        if (nb == 0 && str[0] == '\0')
        {
            *line = NULL;
            return (0);
        }
        *line = str;
        ft_strdel(&str);
        return (1);
    }
	return (1);
}
