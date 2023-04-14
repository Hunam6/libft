/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:18:49 by hunam             #+#    #+#             */
/*   Updated: 2023/04/14 16:33:16 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static void	arr_link_funcs(t_arr *arr, t_free_el free_el, t_print_el print_el)
{
	arr->free_el = free_el;
	arr->print_el = print_el;
	arr->append = arr_append;
	arr->del_at = arr_del_at;
	arr->free = arr_free;
	arr->get = arr_get;
	arr->ins_at = arr_ins_at;
	arr->pop = arr_pop;
	arr->prepend = arr_prepend;
	arr->print = arr_print;
	arr->set = arr_set;
	arr->dup = arr_dup;
}

t_arr	*arr_init(int cap, int el_size, t_free_el free_el, t_print_el print_el)
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
	arr_link_funcs(out, free_el, print_el);
	out->cap = cap;
	out->el_size = el_size;
	out->len = 0;
	return (out);
}

void	arr_free(t_arr *arr)
{
	int	i;

	if (!arr)
		return ;
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
