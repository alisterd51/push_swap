/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:14:35 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/21 15:09:00 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "struct.h"
#include "op.h"

int	value_of_end(t_pile *pile)
{
	while (pile->next)
		pile = pile->next;
	return (pile->value);
}

int	value_of_max(t_pile *pile)
{
	int	max;

	max = INT_MIN;
	while (pile)
	{
		if (pile->value >= max)
			max = pile->value;
		pile = pile->next;
	}
	return (max);
}

int	value_of_min(t_pile *pile)
{
	int	min;

	min = INT_MAX;
	while (pile)
	{
		if (pile->value <= min)
			min = pile->value;
		pile = pile->next;
	}
	return (min);
}
