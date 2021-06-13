/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jnumlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 10:51:25 by jseo              #+#    #+#             */
/*   Updated: 2021/06/13 12:06:16 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	jnumlen(int v)
{
	size_t	len;

	len = 0;
	if (v < 0)
		++len;
	while (true)
	{
		v /= 10;
		++len;
		if (!v)
			return (len);
	}
}