/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:09:07 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/21 18:56:16 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	opti_a_to_b(t_op **list_op, t_pile **a, t_pile **b)
{
	int	i;

	if (!*b || !(*b)->next)
	{
		pb(list_op, a, b);
		return ;
	}
	if ((*a)->value < value_of_min(*b)
		|| (*a)->value > value_of_max(*b))
		i = search_max(b);
	else
		i = search_middle(a, b);
	if (i > 0)
		while (i-- > 0)
			rb(list_op, b);
	else
		while (i++ < 0)
			rrb(list_op, b);
	pb(list_op, a, b);
}

static void	opti_b_to_a(t_op **list_op, t_pile **a, t_pile **b)
{
	int	i;

	i = index_of_max(*b);
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
