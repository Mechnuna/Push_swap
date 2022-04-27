/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:12:20 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 01:11:42 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoinz(char *rem, char *buff)
{
	int		len_buf;
	int		len_rem;
	char	*res;
	int		i;
	int		j;

	if (!rem)
		return (ft_strdup(buff));
	len_rem = ft_strlen(rem);
	len_buf = ft_strlen(buff);
	res = malloc(sizeof(char) * (len_buf + len_rem + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (rem[i])
		res[i++] = rem[j++];
	j = 0;
	while (buff[j])
		res[i++] = buff[j++];
	free(rem);
	res[i] = '\0';
	return (res);
}

char	*read_file(int fd, char *rem, char *buf)
{
	int			read_size;

	read_size = read(fd, buf, BUFFER_SIZE);
	while ((read_size) > 0)
	{
		buf[read_size] = '\0';
		rem = ft_strjoinz(rem, buf);
		if (find_new_line(rem))
		{
			return (rem);
		}
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (rem);
}

void	free_something(char *line)
{
	free(line);
	line = NULL;
}

int	cut_nl(char **line, char **rem, char *buf, char *p)
{
	char		*tmp;

	if (!p)
	{
		*line = ft_strdup(*rem);
		free(*rem);
		*rem = NULL;
		free_something(buf);
		return (0);
	}
	*p = '\0';
	p++;
	*line = ft_strdup(*rem);
	if (!p)
	{
		free(*rem);
		*rem = NULL;
		free_something(buf);
		return (1);
	}
	tmp = ft_strdup(p);
	free(*rem);
	*rem = tmp;
	free_something(buf);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*rem;
	char		*p;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0 || !buf)
	{
		free_something(buf);
		return (-1);
	}
	*line = ft_strdup("");
	if (!(*line))
	{
		free_something(buf);
		return (-1);
	}
	rem = read_file(fd, rem, buf);
	if (!rem)
	{
		free_something(buf);
		return (0);
	}
	if (*line)
		free_something(*line);
	return (cut_nl(line, &rem, buf, p = find_new_line(rem)));
}
