/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:46:01 by jseo              #+#    #+#             */
/*   Updated: 2021/03/18 12:46:02 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		((t_char *)s)[i] = (t_char)c;
	return (s);
}
