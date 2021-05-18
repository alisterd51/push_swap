/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_pile_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 22:10:05 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/18 18:04:50 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "struct.h"
#include "push_swap.h"
#include "op.h"

static int	largest_unsorted(t_pile *a)
{
	int	i;
	int	i_largest;
	int	max_value;

	i = 0;
	i_largest = 0;
	max_value = INT_MIN;
	while (a)
	{
		if (a->value > max_value)
		{
			max_value = a->value;
			i_largest = i;
		}
		i++;
		a = a->next;
	}
	return (i_largest);
}

static int	is_max_value(t_pile *pile_ptr, int value)
{
	while (pile_ptr)
	{
		if (pile_ptr->value > value)
			return (0);
		pile_ptr = pile_ptr->next;
	}
	return (1);
}

static int	this_index_is_sorted(int i, t_pile *pile)
{
	while (i-- > 0)
		pile = pile->next;
	return (pile_is_sorted(pile));
}

static int	index_unsorted(t_pile *pile)
{
	int	ret;

	ret = 0;
	while (pile)
	{
		if (pile_is_sorted(pile))
			return (ret - 1);
		ret++;
		pile = pile->next;
	}
	return (-1);
}

static void	sort_max_value(t_op **list_op, t_pile **a, int i)
{
	int		dst;
	int		i_to_dst;
	t_pile	*pile;

	i_to_dst = index_unsorted(*a) - i;
	pile = *a;
	while (i-- > 0)
	{
		pile = pile->next;
		ra(list_op, a);
	}
	i = 0;
	while (i++ < i_to_dst)
	{
		sa(list_op, a);
		ra(list_op, a);
	}
	while (i-- > 0)
		rra(list_op, a);
}

static void	minimal_sort_max_value(t_op **list_op, t_pile **a, int i)
{
	int	len;

	len = pile_len(*a);
	if (i < len / 2)
		while (i-- >= 0)
			ra(list_op, a);
	else
		while (i++ < len)
			rra(list_op, a);
}

static void	shorter_sort(t_op **list_op, t_pile **a, int i)
{
	if (is_max_value(*a, pile_elem_value(*a, i)))
		minimal_sort_max_value(list_op, a, i);
	else
		sort_max_value(list_op, a, i);
}

void	one_pile_sort(t_op **list_op, t_pile **a)
{
	while (!pile_is_sorted(*a))
		shorter_sort(list_op, a, largest_unsorted(*a));
	op_optimizer(list_op);
}
