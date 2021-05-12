/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:08:43 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/12 17:37:04 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
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
	write(1, "sa\n", 3);
	s(a);
}

void	sb(t_pile **b)
{
	write(1, "sb\n", 3);
	s(b);
}

void	ss(t_pile **a, t_pile **b)
{
	write(1, "ss\n", 3);
	s(a);
	s(b);
}
