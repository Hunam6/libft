/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:13:03 by etattevi          #+#    #+#             */
/*   Updated: 2023/02/16 14:34:18 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, t_uint start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	stop;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len)
		out = ft_calloc(sizeof(char), s_len + 1);
	else
		out = ft_calloc(sizeof(char), len + 1);
	if (!out)
		return (NULL);
	i = 0;
	stop = start + len;
	while (start < stop && s[start] && start < s_len)
		out[i++] = s[start++];
	return (out);
}
