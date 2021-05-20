/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:43:26 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/20 15:55:38 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "struct.h"

static t_pile	*low_elem_not_sorted(t_pile *a)
{
	t_pile	*min_value;

	min_value = NULL;
	while (a)
	{
		if ((!min_value && a->index == -1)
			|| (min_value && (min_value->value > a->value && a->index == -1)))
			min_value = a;
		a = a->next;
	}
	return (min_value);
}

void	pre_sort(t_pile **a)
{
	t_pile	*low;
	int		index;

	low = low_elem_not_sorted(*a);
	index = 0;
	while (low)
	{
		low->index = index;
		low = low_elem_not_sorted(*a);
		index++;
	}
}
