/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_newline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:06:54 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 16:07:49 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	is_newline(int c)
{
	return (c == '\n' || c == '\f' || c == '\r');
}
