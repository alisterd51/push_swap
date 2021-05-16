/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:34:15 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/15 16:26:03 by anclarma         ###   ########.fr       */
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

void	rra(t_op **list_op, t_pile **a)
{
	op_push_back(list_op, "rra\n");
	r(a);
}

void	rrb(t_op **list_op, t_pile **b)
{
	op_push_back(list_op, "rrb\n");
	r(b);
}

void	rrr(t_op **list_op, t_pile **a, t_pile **b)
{
	op_push_back(list_op, "rrr\n");
	r(a);
	r(b);
}
