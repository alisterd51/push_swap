/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:09:07 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/21 18:55:17 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "op.h"

int	search_low(t_pile *pile, int max_index)
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

int	search_up(t_pile *pile, int max_index)
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

int	search_middle(t_pile **a, t_pile **b)
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

int	search_max(t_pile **b)
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
