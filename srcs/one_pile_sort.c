/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_pile_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 22:10:05 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/21 11:23:17 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "struct.h"
#include "push_swap.h"
#include "op.h"

static int	largest_unsort_index(t_pile *pile)
{
	int	i_largest_unsorted;
	int	i_value;
	int	i;

	i_value = INT_MIN;
	i = 0;
	i_largest_unsorted = 0;
	while (pile)
	{
		if (!pile_is_sorted(pile) && pile->value > i_value)
		{
			i_value = pile->value;
			i_largest_unsorted = i;
		}
		i++;
		pile = pile->next;
	}
	return (i_largest_unsorted);
}

static int	index_unsorted(t_pile *pile)
{
	int	ret;

	ret = 0;
	while (pile)
	{
		if (pile_is_sorted(pile))
			return (ret);
		ret++;
		pile = pile->next;
	}
	return (0);
}

static void	sort_max_value(t_op **list_op, t_pile **a, int i)
{
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
	while (i < i_to_dst)
	{
		sa(list_op, a);
		ra(list_op, a);
		i++;
	}
	while (i > 0)
	{
		rra(list_op, a);
		i--;
	}
}

static void	minimal_sort_max_value(t_op **list_op, t_pile **a, int i)
{
	int	len;

	len = pile_len(*a) - 1;
	if (len - i < i + 1)
		while (i++ < len)
			rra(list_op, a);
	else
		while (i-- > -1)
			ra(list_op, a);
}

void	one_pile_sort(t_op **list_op, t_pile **a)
{
	while (!pile_is_sorted(*a))
	{
		if (index_of_max(*a) != pile_len(*a) - 1)
			minimal_sort_max_value(list_op, a, index_of_max(*a));
		else
			sort_max_value(list_op, a, largest_unsort_index(*a));
	}
	op_optimizer(list_op);
}
