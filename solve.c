/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:56:38 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/15 14:35:04 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "op.h"

static int	thirst_is_sorted(t_pile *pile)
{
	if (!pile || !pile->next)
		return (1);
	return (pile->value < pile->next->value);
}

int	pile_is_sorted(t_pile *pile)
{
	while (pile)
	{
		if (!thirst_is_sorted(pile))
			return (0);
		pile = pile->next;
	}
	return (1);
}

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
	while (i_low_value > 0)
	{
		ra(list_op, a);
		i_low_value--;
	}
	pb(list_op, a, b);
}
static void	stupid_sort(t_op **list_op, t_pile **a, t_pile **b)
{
	if (!pile_is_sorted(*a))
	{
		while (*a)
			p_low(list_op, a, b);
		while (*b)
			pa (list_op, a, b);
	}
}

void	solve(t_pile **a, t_pile **b)
{
	t_op	*list_op;

	list_op = NULL;
	stupid_sort(&list_op, a, b);
	op_write(list_op);
	op_clear(&list_op);
	pile_write(*a, *b);
}
