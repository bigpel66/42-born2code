/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtob_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:08:48 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:26:34 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_bool	ft_wtob(char *s, wchar_t c)
{
	t_bool	ret;

	ret = TR;
	if (c >= 128 && c <= 2047 && MB_CUR_MAX >= 2)
	{
		s[0] = ((c >> 6) + 192);
		s[1] = ((c & 63) + 128);
	}
	else if (c >= 2048 && c <= 65535 && MB_CUR_MAX >= 3)
	{
		s[0] = ((c >> 12) + 224);
		s[1] = (((c >> 6) & 63) + 128);
		s[2] = ((c & 63) + 128);
	}
	else if (c >= 65536 && c <= 2097151 && MB_CUR_MAX == 4)
	{
		s[0] = ((c >> 18) + 240);
		s[1] = (((c >> 12) & 63) + 128);
		s[2] = (((c >> 6) & 63) + 128);
		s[3] = ((c & 63) + 128);
	}
	else
		ret = FL;
	return (ret);
}