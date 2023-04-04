/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:18:49 by hunam             #+#    #+#             */
/*   Updated: 2023/04/04 17:12:37 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_arr	*arr_init(
		int cap, int el_size, t_free_el free_el, t_print_el print_el)
{
	t_arr	*out;

	out = malloc(sizeof(t_arr));
	if (!out)
		return (NULL);
	out->data = malloc(cap * el_size);
	if (!out->data)
	{
		free(out);
		return (NULL);
	}
	out->free_el = free_el;
	out->print_el = print_el;
	out->cap = cap;
	out->len = 0;
	return (out);
}

void	arr_free(t_arr *arr)
{
	int	i;

	i = -1;
	while (++i < arr->len)
		if (arr->free_el)
			arr->free_el(arr_get(arr, i));
	free(arr->data);
	free(arr);
}

void	arr_append(t_arr *arr, void *el)
{
	arr_ins_at(arr, arr->len, el);
}

void	arr_prepend(t_arr *arr, void *el)
{
	arr_ins_at(arr, 0, el);
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
