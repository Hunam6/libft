/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:19:47 by hunam             #+#    #+#             */
/*   Updated: 2023/04/14 15:06:19 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include "libft.h"

typedef void	(*t_free_el)(void *);
typedef void	(*t_print_el)(void *);

typedef struct s_arr
{
	void			***data;
	int				len;
	int				cap;
	int				el_size;
	t_free_el		free_el;
	t_print_el		print_el;
	void			(*free)(struct s_arr *arr);
	void			(*append)(struct s_arr *arr, void *el);
	void			(*prepend)(struct s_arr *arr, void *el);
	void			(*ins_at)(struct s_arr *arr, int idx, void *el);
	void			(*del_at)(struct s_arr *arr, int idx);
	void			(*pop)(struct s_arr *arr);
	void			(*set)(struct s_arr *arr, int idx, void *el);
	void			*(*get)(struct s_arr *arr, int idx);
	void			(*print)(struct s_arr *arr);
	struct s_arr	*(*dup)(struct s_arr *arr);
}	t_arr;

t_arr	*arr_init(int cap, int el_size, t_free_el free_el, t_print_el print_el);
void	arr_free(t_arr *arr);
void	arr_append(t_arr *arr, void *el);
void	arr_prepend(t_arr *arr, void *el);
void	arr_ins_at(t_arr *arr, int idx, void *el);
void	arr_del_at(t_arr *arr, int idx);
void	arr_pop(t_arr *arr);
void	arr_set(t_arr *arr, int idx, void *el);
void	*arr_get(t_arr *arr, int idx);
void	arr_print(t_arr *arr);
t_arr	*arr_dup(t_arr *arr);

#endif