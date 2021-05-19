/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entropy_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:06:59 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/19 14:27:53 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "push_swap.h"
#include "op.h"

void	test(t_op **list_op, t_pile **a)
{
	int	select;
	int	entropy_min;

	sa(list_op, a);
	entropy_min = (entropy(*a));
	select = 0;
	sa(list_op, a);
	ra(list_op, a);
	if (entropy(*a) < entropy_min)
	{
		select = 1;
		entropy_min = (entropy(*a));
	}
	rra(list_op, a);
	rra(list_op, a);
	if (entropy(*a) < entropy_min)
	{
		select = 2;
		entropy_min = (entropy(*a));
	}
	ra(list_op, a);
	if (select == 0)
		sa(list_op, a);
	else if (select == 1)
		ra(list_op, a);
	else
		rra(list_op, a);
}

void	entropy_sort(t_op **list_op, t_pile **a)
{
	while (!pile_is_sorted(*a))
		test(list_op, a);
	op_optimizer(list_op);
}
