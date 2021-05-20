/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:09:07 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/21 00:25:37 by anclarma         ###   ########.fr       */
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
/*
static int	search_max_low(t_pile *pile)
{
	int	i;
	int	max_value;
	int	i_max_value;
	int	len;

	i = 0;
	max_value = INT_MAX;
	i_max_value = 0;
	len = pile_len(pile);
	while (pile)
	{
		if (pile->value > max_value)
		{
			max_value = pile->value;
			i_max_value = i;
		}
		i++;
		pile = pile->next;
	}
	return (len - i_max_value);
}

static int	search_max_up(t_pile *pile)
{
	int	i;
	int	max_value;
	int	i_max_value;

	i = 0;
	max_value = INT_MAX;
	i_max_value = 0;
	while (pile)
	{
		if (pile->value > max_value)
		{
			max_value = pile->value;
			i_max_value = i;
		}
		i++;
		pile = pile->next;
	}
	return (i_max_value);
}
*/
static int	is_min_of_pile(int index, t_pile *pile)
{
	while (pile)
	{
		if (pile->index < index)
			return (0);
		pile = pile->next;
	}
	return (1);
}

static int	is_max_of_pile(int index, t_pile *pile)
{
	while (pile)
	{
		if (pile->index > index)
			return (0);
		pile = pile->next;
	}
	return (1);
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

static int	search_up_b_placement(t_op **list_op, t_pile **a, t_pile **b)
{
	int	i;
	int	i_opti;

	i = 0;
	while (!test_b_placement((*a)->index, *b))
	{
		rb(list_op, b);
		i++;
	}
	i_opti = i;
	while (i > 0)
	{
		rrb(list_op, b);
		i--;
	}
	while (!test_b_placement((*a)->index, *b))
	{
		rrb(list_op, b);
		i++;
	}
	if (i < i_opti)
		i_opti = -i;
	while (i > 0)
	{
		rb(list_op, b);
		i--;
	}
	return (i_opti);
}

static int	search_up_b_placement_bis(t_op **list_op, t_pile **b)
{
	int	i;
	int	i_opti;

	i = 0;
	while (!is_max_of_pile((*b)->index, *b))
	{
		rb(list_op, b);
		i++;
	}
	i_opti = i;
	while (i > 0)
	{
		rrb(list_op, b);
		i--;
	}
	while (!is_max_of_pile((*b)->index, *b))
	{
		rrb(list_op, b);
		i++;
	}
	if (i < i_opti)
		i_opti = -i;
	while (i > 0)
	{
		rb(list_op, b);
		i--;
	}
	return (i_opti);
}

static void	opti_a_to_b(t_op **list_op, t_pile **a, t_pile **b)
{
/*	int	i_low;
	int	i_up;*/

	if (!*b || !(*b)->next)
	{
		pb(list_op, a, b);
		return ;
	}
	if (is_min_of_pile((*a)->index, *b)
		|| is_max_of_pile((*a)->index, *b))
	{
/*		i_low = search_max_low(*b);
		i_up = search_max_up(*b);
		if (i_low < i_up)
			while (i_low-- > 0)
				rrb(list_op, b);
		else
			while (i_up-- > 0)
				rb(list_op, b);*/
		int i = search_up_b_placement_bis(list_op, b);
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
//		while (!is_max_of_pile((*b)->index, *b))
//			rb(list_op, b);
	}
	else
		while (!test_b_placement((*a)->index, *b))
		{
			int i = search_up_b_placement(list_op, a, b);
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
//			rb(list_op, b);
		}
	pb(list_op, a, b);
}

static void	opti_b_to_a(t_op **list_op, t_pile **a, t_pile **b)
{
	while (!pile_is_isorted(*b))
		rb(list_op, b);
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
	{
		test(list_op, a, b, pile_len(*a) / 10 + 1);
	}
	op_optimizer(list_op);
}
