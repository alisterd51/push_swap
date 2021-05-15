/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:34:15 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/15 16:25:42 by anclarma         ###   ########.fr       */
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
	*pile_ptr = ptr1->next;
	ptr1->next = NULL;
	ptr2 = *pile_ptr;
	while (ptr2->next)
		ptr2 = ptr2->next;
	ptr2->next = ptr1;
}

void	ra(t_op **list_op, t_pile **a)
{
	op_push_back(list_op, "ra\n");
	r(a);
}

void	rb(t_op **list_op, t_pile **b)
{
	op_push_back(list_op, "rb\n");
	r(b);
}

void	rr(t_op **list_op, t_pile **a, t_pile **b)
{
	op_push_back(list_op, "rr\n");
	r(a);
	r(b);
}
