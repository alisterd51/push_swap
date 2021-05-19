/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entropy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:42:47 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/19 13:52:41 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "push_swap.h"

int	entropy(t_pile *pile)
{
	int	entropy;

	entropy = 0;
	while (pile)
	{
		if (!thirst_is_sorted(pile))
			entropy++;
		pile = pile->next;
	}
	return (entropy);
}
