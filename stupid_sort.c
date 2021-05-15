/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stupid_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:12:47 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/15 17:53:18 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "push_swap.h"
#include "op.h"

static void	p_low(t_op **list_op, t_pile **a, t_pile **b)
{
	int		low_value;
	int		i_low_value;
	int		i;
	t_pile	*ptr_a;

	low_value = 2147483647;
	ptr_a = *a;
	i = 0;
	i_low_value = i;
	while (ptr_a)
	{
		if (ptr_a->value <= low_value)
		{
			low_value = ptr_a->value;
			i_low_value = i;
		}
		i++;
		ptr_a = ptr_a->next;
	}
	if (i_low_value < pile_len(*a) / 2)
	{
		while (i_low_value > 0)
		{
			ra(list_op, a);
			i_low_value--;
		}
	}
	else
	{
		i_low_value = pile_len(*a) - i_low_value;
		while (i_low_value > 0)
		{
			rra(list_op, a);
			i_low_value--;
		}
	}
	pb(list_op, a, b);
}

void	stupid_sort(t_op **list_op, t_pile **a, t_pile **b)
{
	if (!pile_is_sorted(*a))
	{
		while (*a && (*a)->next)
			p_low(list_op, a, b);
		while (*b)
			pa (list_op, a, b);
	}
}
