/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:46:19 by sbarbe            #+#    #+#             */
/*   Updated: 2023/11/06 11:58:38 by sbarbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_sep(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)ft_calloc(sizeof(char), (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *temp, char *line)
{
	int		i;
	int		j;
	char	*str;

	if (!temp)
	{
		temp = (char *)ft_calloc(1, sizeof(char));
		temp[0] = '\0';
	}
	if (!temp || !line)
		return (NULL);
	str = ft_calloc(sizeof(char), ((ft_strlen(temp) + ft_strlen(line)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (temp)
		while (temp[++i] != '\0')
			str[i] = temp[i];
	while (line[j] != '\0')
		str[i++] = line[j++];
	str[ft_strlen(temp) + ft_strlen(line)] = '\0';
	free(temp);
	return (str);
}

char	*reste(char *temp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	str = ft_calloc(sizeof(char), (ft_strlen(temp) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (temp[i])
		str[j++] = temp[i++];
	free(temp);
	str[j] = '\0';
	return (str);
}

char	*ajouteca(int fd, char *temp)
{
	char	*line;
	int		rd;

	line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	rd = 1;
	while (!ft_strchr(line, '\n') && rd != 0)
	{
		rd = read(fd, line, BUFFER_SIZE);
		if (rd == -1)
		{
			free(line);
			return (NULL);
		}
		if (rd == 0)
			break ;
		line[rd] = '\0';
		temp = ft_strjoin(temp, line);
	}
	free(line);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*theline;
	static char	*temp[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp[fd] = ajouteca(fd, temp[fd]);
	if (!temp[fd])
		return (NULL);
	theline = ft_sep(temp[fd]);
	temp[fd] = reste(temp[fd]);
	return (theline);
}
