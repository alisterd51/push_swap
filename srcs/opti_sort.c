/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:09:07 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/21 17:14:06 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "struct.h"
#include "push_swap.h"
#include "op.h"
#include "sort.h"

static int	groupe_present(t_pile *a, int max_index)
{
	while (a)
	{
		if (a->index < max_index)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	search_low(t_pile *pile, int max_index)
{
	int	i;
	int	i_low;
	int	len;

	i = 0;
	i_low = 0;
	len = pile_len(pile);
	while (pile)
	{
		if (pile->index < max_index)
			i_low = i;
		i++;
		pile = pile->next;
	}
	return (len - i_low);
}

static int	search_up(t_pile *pile, int max_index)
{
	int	i;

	i = 0;
	while (pile)
	{
		if (pile->index < max_index)
			return (i);
		i++;
		pile = pile->next;
	}
	return (i);
}

static int	test_b_placement(int index, t_pile *pile)
{
	if (pile->index > index)
		return (0);
	while (pile->next)
		pile = pile->next;
	if (pile->index < index)
		return (0);
	return (1);
}

static int	search_up_b_placement(t_pile **a, t_pile **b)
{
	int	i;
	int	len;

	i = index_of_middle((*a)->value, *b);
	len = pile_len(*b);
	if (i < len / 2)
		return (i);
	else
		return (-(len - i));
}

static int	search_up_b_placement_bis(t_pile **b)
{
	int	i;
	int	len;

	i = index_of_max(*b);
	len = pile_len(*b);
	if (i < len / 2)
		return (i);
	else
		return (-(len - i));
}

static void	opti_a_to_b(t_op **list_op, t_pile **a, t_pile **b)
{
	int i;

	if (!*b || !(*b)->next)
	{
		pb(list_op, a, b);
		return ;
	}
	if ((*a)->value < value_of_min(*b)
			|| (*a)->value > value_of_max(*b))
	{
		i = search_up_b_placement_bis(b);
		while (i > 0)
		{
			rb(list_op, b);
			i--;
		}
		while (i < 0)
		{
			rrb(list_op, b);
			i++;
		}
	}
	else
		while (!test_b_placement((*a)->index, *b))
		{
			i = search_up_b_placement(a, b);
			while (i > 0)
			{
				rb(list_op, b);
				i--;
			}
			while (i < 0)
			{
				rrb(list_op, b);
				i++;
			}
		}
	pb(list_op, a, b);
}

static int  largest_value_index(t_pile *a)
{
	int i;
	int i_largest;
	int max_value;

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

static void	opti_b_to_a(t_op **list_op, t_pile **a, t_pile **b)
{
	int	i = largest_value_index(*b);

	if (i < pile_len(*b) / 2)
		while (!pile_is_isorted(*b))
			rb(list_op, b);
	else
		while (!pile_is_isorted(*b))
			rrb(list_op, b);
	while (*b)
		pa(list_op, a, b);
}

static void	test(t_op **list_op, t_pile **a, t_pile **b, int n)
{
	int	i_low;
	int	i_up;
	int	max_groupe;

	max_groupe = n;
	while (*a)
	{
		while (groupe_present(*a, max_groupe))
		{
			i_low = search_low(*a, max_groupe);
			i_up = search_up(*a, max_groupe);
			if (i_low < i_up)
				while (i_low-- > 0)
					rra(list_op, a);
			else
				while (i_up-- > 0)
					ra(list_op, a);
			opti_a_to_b(list_op, a, b);
		}
		max_groupe += n;
	}
	opti_b_to_a(list_op, a, b);
}

void	opti_sort(t_op **list_op, t_pile **a, t_pile **b)
{
	pre_sort(a);
	if (!pile_is_sorted(*a) && !*b)
		test(list_op, a, b, pile_len(*a) / 10 + 1);
	op_optimizer(list_op);
}
