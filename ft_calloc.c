/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:13:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/10/31 17:07:49 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*out;
	size_t	i;

	out = malloc(count * size);
	if (out == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (i < count * size)
		out[i++] = '\0';
	return (out);
}
