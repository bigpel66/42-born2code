/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:48:56 by jseo              #+#    #+#             */
/*   Updated: 2021/03/19 17:10:16 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	process_nbr(t_form *f, va_list ap)
{
	t_bool	ret;

	ret = FL;
	if (f->t == 4 || f->t == 5)
		ret = prnt_dec_signed(f, va_arg(ap, int), TR);
	else if (f->t == 6)
		ret = prnt_dec_unsigned(f, va_arg(ap, unsigned int), FL);
	else if (f->t == 7)
		ret = prnt_oct(f, va_arg(ap, unsigned int));
	else if (f->t == 8)
		ret = prnt_hex(f, va_arg(ap, unsigned int), FL, FL);
	else if (f->t == 9)
		ret = prnt_hex(f, va_arg(ap, unsigned int), TR, FL);
	return (ret);
}
