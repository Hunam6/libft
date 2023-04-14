/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:45:24 by hunam             #+#    #+#             */
/*   Updated: 2023/04/14 16:33:25 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_arr	*arr_dup(t_arr *arr)
{
	int		i;
	t_arr	*out;

	out = arr_init(arr->cap, arr->el_size, arr->free_el, arr->print_el);
	if (!out)
		return (NULL);
	i = -1;
	while (++i < arr->len)
		out->append(out, arr->get(arr, i));
	return (out);
}

void	arr_ins_at(t_arr *arr, int idx, void *el)
{
	int	i;

	i = arr->len;
	while (--i >= idx)
		arr_set(arr, i + 1, arr_get(arr, i));
	arr_set(arr, idx, el);
	arr->len++;
}
