/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:46:39 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:27:11 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	get_index(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
		if (s[i++] == c)
			return (i);
	return (0);
}