/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:13:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/11/02 13:54:54 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static bool	isinstr(char const ch, char const *str)
{
	while (*str)
	{
		if (*str == ch)
			return (true);
		str++;
	}
	return (false);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	beg;
	int	end;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	beg = 0;
	end = 0;
	while (isinstr(s1[i++], set))
		beg++;
	while (s1[i])
	{
		if (isinstr(s1[i], set))
		{
			if (end == 0)
				end = i;
		}
		else
			end = 0;
		i++;
	}
	if (end == 0)
		end = i;
	return (ft_substr(s1, beg, end - beg));
}
