/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:32:31 by etattevi          #+#    #+#             */
/*   Updated: 2023/03/23 16:21:47 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	chr_idx(const char *s, int c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if ((char)c == '\0')
		return (i);
	return (-1);
}

char	*has_nl(char *saved[OPEN_MAX], int fd)
{
	int			nl_idx;
	char		*line;
	char		*rem;

	nl_idx = chr_idx(saved[fd], '\n');
	if (nl_idx != -1)
	{
		line = ft_substr(saved[fd], 0, nl_idx + 1);
		rem = ft_substr(saved[fd], nl_idx + 1, ft_strlen(saved[fd]) - nl_idx);
		free(saved[fd]);
		saved[fd] = rem;
		return (line);
	}
	return (NULL);
}

char	*no_nl(char	*saved[OPEN_MAX], int fd)
{
	char	*out;

	out = NULL;
	if (saved[fd])
	{
		if (saved[fd][0] != '\0')
			out = ft_strdup(saved[fd]);
		free(saved[fd]);
		saved[fd] = NULL;
	}
	return (out);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*out;

	if (!s1)
		return (ft_strdup(s2));
	out = ft_strjoin(s1, s2);
	free(s1);
	return (out);
}

char	*get_next_line(int fd)
{
	static char	*saved[OPEN_MAX] = {NULL};
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	int			just_read;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	while (42)
	{
		line = has_nl(saved, fd);
		if (line)
			return (line);
		just_read = read(fd, buff, BUFFER_SIZE);
		if (just_read == 0 && chr_idx(saved[fd], '\n') == -1)
			return (no_nl(saved, fd));
		buff[just_read] = '\0';
		saved[fd] = ft_strjoin_free(saved[fd], buff);
	}
}
