/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dalloc_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:45:38 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:25:06 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_bool	dalloc(void **ptr, size_t cnt, size_t n)
{
	*ptr = (void *)malloc(cnt * n);
	if (*ptr == NULL)
		return (FL);
	ft_memset(*ptr, 0, cnt * n);
	return (TR);
}
