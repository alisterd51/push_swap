/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:26:05 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/20 12:00:02 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int	thirst_is_sorted(t_pile *pile)
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

int	thirst_is_isorted(t_pile *pile)
{
	if (!pile || !pile->next)
		return (1);
	return (pile->value > pile->next->value);
}

int	pile_is_isorted(t_pile *pile)
{
	while (pile)
	{
		if (!thirst_is_isorted(pile))
			return (0);
		pile = pile->next;
	}
	return (1);
}
