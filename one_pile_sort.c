/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_pile_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 22:10:05 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/16 00:34:46 by anclarma         ###   ########.fr       */
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

static void	shorter_sort()
{
	
}

void	one_pile_sort(t_op **list_op, t_pile **a)
{
	while (!pile_is_sorted(*a))
		shorter_sort(list_op, a, largest_unsorted(*a));
}
