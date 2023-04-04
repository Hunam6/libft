/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:45:24 by hunam             #+#    #+#             */
/*   Updated: 2023/04/04 14:37:39 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	arr_del_at(t_arr *arr, int idx)
{
	int	i;

	if (arr->free_el)
		arr->free_el(arr_get(arr, idx));
	i = idx - 1;
	while (++i < arr->len)
		arr_set(arr, i, arr_get(arr, i + 1));
	arr->len--;
}

void	arr_pop(t_arr *arr)
{
	arr_del_at(arr, arr->len - 1);
}

void	arr_set(t_arr *arr, int idx, void *el)
{
	arr->data[idx] = el;
}

void	*arr_get(t_arr *arr, int idx)
{
	return (arr->data[idx]);
}

void	arr_print(t_arr *arr)
{
	int	i;

	if (arr->print_el)
	{
		i = -1;
		while (++i < arr->len)
		{
			arr->print_el(arr_get(arr, i));
			ft_printf(" ");
		}
		ft_printf("\n");
	}
}
