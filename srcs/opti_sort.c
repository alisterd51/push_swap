/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:09:07 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/20 13:41:14 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "push_swap.h"
#include "op.h"
#include "sort.h"

#include <unistd.h>
#include <stdio.h>

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

static int	is_min_of_pile(int index, t_pile *pile)
{
	printf("%d,", index);
	t_pile	*ptr;

	ptr = pile;
	while (ptr)
	{
		printf(" %d", ptr->index);
		ptr = ptr->next;
	}
	printf("\n");
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

static int	test_b_placement(int index, t_pile *pile)//boucle inf
{
	if (pile->index > index)
		return (0);
	while (pile->next)
		pile = pile->next;
	if (pile->index < index)
		return (0);
	return (1);
}

static void	opti_a_to_b(t_op **list_op, t_pile **a, t_pile **b)
{
	t_pile	*ptr_b;

	ptr_b = *b;
	while (ptr_b)
	{
//		printf("%d\n", ptr_b->value);
		ptr_b = ptr_b->next;
	}
//	printf("\n");
	if (!*b || !(*b)->next)
	{
		pb(list_op, a, b);
		return ;
	}
	//il faut que le pos0 soit inf a *a (ou si *a est le min que pos0 soit le plus grand )
	//test
	if (is_min_of_pile((*a)->index, *b))
	{
//		printf("a\n");
		while (!is_max_of_pile((*b)->index, *b))
			rb(list_op, b);
	}
	else if (is_max_of_pile((*a)->index, *b))
	{
//		printf("b\n");
		while (!is_max_of_pile((*b)->index, *b))
			rb(list_op, b);
	}
	else
	{
//		printf("c\n");
		while (!test_b_placement((*a)->index, *b))
			rb(list_op, b);
	}
	//ftest
	pb(list_op, a, b);
	//pas opti
}

static void	opti_b_to_a(t_op **list_op, t_pile **a, t_pile **b)
{
//	printf("test1\n");
	t_pile	*ptr_b;

	ptr_b = *b;
	while (ptr_b)
	{
//		printf("%d\n", ptr_b->value);
		ptr_b = ptr_b->next;
	}
	while (!pile_is_isorted(*b))
		rb(list_op, b);
//	printf("test2\n");
	while (*b)
		pa(list_op, a, b);
//	printf("test3\n");
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
		test(list_op, a, b, 10);
	}
	op_optimizer(list_op);
}
