/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_nothing_ll.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:21:07 by jseo              #+#    #+#             */
/*   Updated: 2021/03/19 17:21:08 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	process_nothing_ll(t_form *f, void *ptr)
{
	*(long long *)ptr = (f->size);
	return (TR);
}
