/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:13:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/11/03 15:46:20 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_split {
	char	**out;
	int		i;
	int		part_beg;
	int		part_len;
	int		out_i;
}	t_split;

static t_split	*init(char const *str)
{
	t_split	*s;

	s = malloc(sizeof(t_split));
	if (!s)
		return (NULL);
	s->out = malloc(sizeof(char *) * (ft_strlen(str) / 2 + 1));
	if (!(s->out))
		return (NULL);
	s->i = 0;
	s->part_beg = -1;
	s->part_len = 0;
	s->out_i = 0;
	return (s);
}

static char	**end(char const *s, t_split *data)
{
	if (data->part_beg != -1)
		data->out[data->out_i++] = ft_substr(s, data->part_beg, data->part_len);
	data->out[data->out_i] = NULL;
	return (data->out);
}

char	**ft_split(char const *s, char c)
{
	t_split	*data;

	if (!s)
		return (NULL);
	data = init(s);
	if (!data)
		return (NULL);
	while (s[data->i])
	{
		if (s[data->i] != c)
		{
			if (data->part_beg == -1)
				data->part_beg = data->i;
			data->part_len++;
		}
		else if (data->part_beg != -1)
		{
			data->out[data->out_i++]
				= ft_substr(s, data->part_beg, data->part_len);
			data->part_beg = -1;
			data->part_len = 0;
		}
		data->i++;
	}
	return (end(s, data));
}
