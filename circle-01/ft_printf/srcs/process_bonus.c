/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:32:03 by jseo              #+#    #+#             */
/*   Updated: 2021/03/17 12:32:06 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int process_bonus(t_form *f, va_list ap)
{
	int test1;
	int test2;
	test1 = f->flg & 0;
	test2 = va_arg(ap, int);
	return (1);
}
