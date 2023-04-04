/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:19:47 by hunam             #+#    #+#             */
/*   Updated: 2023/04/04 14:28:17 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include "libft.h"

typedef void	(*t_free_el)(void *);
typedef void	(*t_print_el)(void *);

typedef struct s_arr
{
	void		***data;
	int			len;
	int			cap;
	t_free_el	free_el;
	t_print_el	print_el;
}	t_arr;

t_arr	*arr_init(
			int cap, int el_size, void free_el(void *), void print_el(void *));
void	arr_free(t_arr *arr);
void	arr_append(t_arr *arr, void *el);
void	arr_prepend(t_arr *arr, void *el);
void	arr_ins_at(t_arr *arr, int idx, void *el);
void	arr_del_at(t_arr *arr, int idx);
void	arr_pop(t_arr *arr);
void	arr_set(t_arr *arr, int idx, void *el);
void	*arr_get(t_arr *arr, int idx);
void	arr_print(t_arr *arr);

#endif