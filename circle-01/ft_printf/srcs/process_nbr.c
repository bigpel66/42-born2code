/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:48:56 by jseo              #+#    #+#             */
/*   Updated: 2021/03/18 12:48:58 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	process_nbr(t_form *f, va_list ap)
{
	t_bool	ret;

	ret = FL;
	if (f->t == 4 || f->t == 5)
		ret = print_dec(f, (long long)(va_arg(ap, int)), TR);
	else if (f->t == 6)
		ret = print_dec(f, (long long)(va_arg(ap, unsigned int)), FL);
	else if (f->t == 7)
		ret = print_hex(f, va_arg(ap, unsigned int), FL, FL);
	else if (f->t == 8)
		ret = print_hex(f, va_arg(ap, unsigned int), TR, FL);
	return (ret);
}
