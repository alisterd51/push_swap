/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:08:43 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/12 20:50:45 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "struct.h"

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

void	pa(t_pile **a, t_pile **b)
{
	write(1, "pa\n", 3);
	p(a, b);
}

void	pb(t_pile **a, t_pile **b)
{
	write(1, "pb\n", 3);
	p(b, a);
}
