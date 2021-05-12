/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:34:15 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/12 16:19:03 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "op.h"

static void	r(t_pile **pile_ptr)
{
	t_pile	*ptr;

	if (!*pile_ptr || !(*pile_ptr)->next)
		return ;
	ptr = *pile_ptr;
	while (ptr->next->next)
		ptr = ptr->next;
	ptr->next->next = *pile_ptr;
	*pile_ptr = ptr->next;
	ptr->next = NULL;
	*pile_ptr = (*pile_ptr)->next;
}

void	rra(t_pile **a)
{
	r(a);
}

void	rrb(t_pile **b)
{
	r(b);
}

void	rrr(t_pile **a, t_pile **b)
{
	r(a);
	r(b);
}
