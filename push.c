/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:08:43 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/15 16:25:19 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "op.h"

static void	p(t_pile **dst, t_pile **src)
{
	t_pile	*ptr;

	if (!*src)
		return ;
	ptr = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = ptr;
}

void	pa(t_op **list_op, t_pile **a, t_pile **b)
{
	op_push_back(list_op, "pa\n");
	p(a, b);
}

void	pb(t_op **list_op, t_pile **a, t_pile **b)
{
	op_push_back(list_op, "pb\n");
	p(b, a);
}
