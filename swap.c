/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:08:43 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/15 16:24:57 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "op.h"

static void	s(t_pile **pile_ptr)
{
	t_pile	*maillon1;
	t_pile	*maillon2;
	t_pile	*maillon3;

	if (!pile_ptr || !*pile_ptr || !(*pile_ptr)->next)
		return ;
	maillon1 = *pile_ptr;
	maillon2 = maillon1->next;
	maillon3 = maillon2->next;
	*pile_ptr = maillon2;
	maillon2->next = maillon1;
	maillon1->next = maillon3;
}

void	sa(t_op **op_ptr, t_pile **a)
{
	op_push_back(op_ptr, "sa\n");
	s(a);
}

void	sb(t_op **op_ptr, t_pile **b)
{
	op_push_back(op_ptr, "sb\n");
	s(b);
}

void	ss(t_op **op_ptr, t_pile **a, t_pile **b)
{
	op_push_back(op_ptr, "ss\n");
	s(a);
	s(b);
}
