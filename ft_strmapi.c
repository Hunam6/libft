/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:13:03 by etattevi          #+#    #+#             */
/*   Updated: 2023/02/16 14:34:18 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(t_uint, char))
{
	char	*out;
	size_t	i;

	if (!s)
		return (NULL);
	out = ft_strdup(s);
	if (!out)
		return (NULL);
	i = 0;
	while (out[i])
	{
		out[i] = f(i, out[i]);
		i++;
	}
	return (out);
}
