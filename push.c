/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:08:43 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/12 16:22:01 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static void	p(t_pile **dst, t_pile **src)
{
	if (!*src)
		return ;
	(*src)->next = *dst;
	*dst = *src;
	*src = (*src)->next;
}

void	pa(t_pile **a, t_pile **b)
{
	p(a, b);
}

void	pb(t_pile **a, t_pile **b)
{
	p(b, a);
}
