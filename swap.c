/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:08:43 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/12 13:50:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"

static void	s(t_pile **pile_ptr)
{
	t_pile	*maillon1;
	t_pile	*maillon2;
	t_pile	*maillon3;

	if (!pile_ptr || !*pile_ptr || !(*pile_ptr)->next)
		return ;
	maillon1 = *pile_ptr;
	maillon2 = maillon1->next;
	maillon3 = maillon2->next;
	*pile_ptr = maillon2;
	maillon2->next = maillon1;
	maillon1->next = maillon3;
}

void	sa(t_pile **a)
{
	s(a);
}

void	sb(t_pile **b)
{
	s(b);
}

void	ss(t_pile **a, t_pile **b)
{
	s(a);
	s(b);
}
