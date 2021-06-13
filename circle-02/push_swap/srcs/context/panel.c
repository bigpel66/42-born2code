/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 10:20:04 by jseo              #+#    #+#             */
/*   Updated: 2021/06/13 12:06:03 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_clear(void)
{
	jputstr("\E[H\E[2J\E[3J", STDOUT_FILENO);
}

static void	print_number(t_list **lst, t_list **prv, bool former, bool print)
{
	size_t	num;
	size_t	pad;

	num = 0;
	if (*lst && print)
		num = jnumlen((*lst)->v);
	pad = 20 - num;
	if (*lst && former && print)
		jputnbr((*lst)->v, STDOUT_FILENO);
	while (pad--)
		jputchar(' ', STDOUT_FILENO);
	if (*lst && !former && print)
		jputnbr((*lst)->v, STDOUT_FILENO);
	if (print)
	{
		*prv = *lst;
		*lst = (*lst)->n;
	}
}

void		print_stacks(t_ps **ps)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*prv1;
	t_list	*prv2;

	tmp1 = (*ps)->ah;
	tmp2 = (*ps)->bh;
	prv1 = NULL;
	prv2 = NULL;
	print_clear();
	jputstr("Stack A             |             Stack B\n", STDOUT_FILENO);
	jputstr("-----------------------------------------\n", STDOUT_FILENO);
	while (true)
	{
		print_number(&tmp1, &prv1, true, prv1 != (*ps)->at);
		jputchar('|', STDOUT_FILENO);
		print_number(&tmp2, &prv2, false, prv2 != (*ps)->bt);
		jputchar('\n', STDOUT_FILENO);
		if (prv1 == (*ps)->at && prv2 == (*ps)->bt)
			return ;
	}
}
