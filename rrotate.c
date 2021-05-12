/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:34:15 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/12 21:14:50 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "op.h"

static void	r(t_pile **pile_ptr)
{
	t_pile	*ptr1;
	t_pile	*ptr2;

	if (!*pile_ptr || !(*pile_ptr)->next)
		return ;
	ptr1 = *pile_ptr;
	while (ptr1->next->next)
		ptr1 = ptr1->next;
	ptr2 = ptr1->next;
	ptr2->next = *pile_ptr;
	*pile_ptr = ptr2;
	ptr1->next = NULL;
}

void	rra(t_pile **a)
{
	write(1, "rra\n", 4);
	r(a);
}

void	rrb(t_pile **b)
{
	write(1, "rrb\n", 4);
	r(b);
}

void	rrr(t_pile **a, t_pile **b)
{
	write(1, "rrr\n", 4);
	r(a);
	r(b);
}
