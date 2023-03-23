/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:32:31 by etattevi          #+#    #+#             */
/*   Updated: 2023/01/20 13:21:40 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 2048
# endif

char	*get_next_line(int fd);
int		chr_idx(const char *s, int c);
char	*has_nl(char *saved[OPEN_MAX], int fd);
char	*no_nl(char	*saved[OPEN_MAX], int fd);
char	*ft_strjoin_free(char *s1, char *s2);

#endif