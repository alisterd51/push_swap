/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:56:38 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/14 22:17:29 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "pile.h"
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

static void	p_low(t_pile **a, t_pile **b)
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
		ra(a);
		i_low_value--;
	}
	pb(a, b);
}

void	solve(t_pile **a, t_pile **b)
{
	if (!pile_is_sorted(*a))
	{
		while (*a)
			p_low(a, b);
		while (*b)
			pa (a, b);
	}
	pile_write(*a, *b);
}
