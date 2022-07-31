/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:49:16 by abouleau          #+#    #+#             */
/*   Updated: 2021/12/21 12:38:58 by abouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*get_read(int fd, char *save)
{
	char	*buffer;
	int		reader;

	reader = 1;
	buffer = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr2(save, '\n') && reader != 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (save);
		}
		buffer[reader] = '\0';
		save = ft_strjoin2(save, buffer);
	}
	free (buffer);
	return (save);
}

char	*get_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = (char *) malloc (sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_save(char *save)
{
	char	*save2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free (save);
		return (NULL);
	}
	save2 = (char *) malloc (sizeof(char) * (ft_strlen2(save) - i + 1));
	if (!save2)
		return (NULL);
	i++;
	while (save[i])
		save2[j++] = save[i++];
	save2[j] = '\0';
	free(save);
	return (save2);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = get_read(fd, save);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = get_save(save);
	free(save);
	save = NULL;
	return (line);
}
