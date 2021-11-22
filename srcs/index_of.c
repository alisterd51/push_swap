/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:14:35 by anclarma          #+#    #+#             */
/*   Updated: 2021/11/22 10:22:29 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "struct.h"
#include "op.h"

int	index_of_max(t_pile *pile)
{
	int	i;
	int	i_max;
	int	max;

	i = 0;
	i_max = 0;
	max = INT_MIN;
	while (pile)
	{
		if (pile->value >= max)
		{
			max = pile->value;
			i_max = i;
		}
		i++;
		pile = pile->next;
	}
	return (i_max);
}

int	index_of_min(t_pile *pile)
{
	int	i;
	int	i_min;
	int	min;

	i = 0;
	i_min = 0;
	min = INT_MAX;
	while (pile)
	{
		if (pile->value <= min)
		{
			min = pile->value;
			i_min = i;
		}
		i++;
		pile = pile->next;
	}
	return (i_min);
}

int	index_of_middle(int value, t_pile *pile)
{
	int	i;

	if (pile->value < value && value_of_end(pile) > value)
		return (0);
	i = 1;
	while (pile->next)
	{
		if (value < pile->value && value > pile->next->value)
			return (i);
		i++;
		pile = pile->next;
	}
	return (-1);
}
