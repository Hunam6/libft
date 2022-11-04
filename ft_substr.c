/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:13:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/11/02 13:00:11 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	stop;
	size_t	s_len;

	if (!s)
		return (NULL);
	out = malloc(sizeof(char) * (len + 1));
	i = 0;
	stop = start + len;
	s_len = ft_strlen(s);
	if (out == NULL)
		return (NULL);
	while (start < stop && s[start] && start < s_len)
		out[i++] = s[start++];
	out[i] = '\0';
	return (out);
}
