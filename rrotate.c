/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:34:15 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/12 17:38:28 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
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
	write(1, "rra\n", 4);
	r(a);
}

void	rrb(t_pile **b)
{
	write(1, "rrb\n", 4);
	r(b);
}

void	rrr(t_pile **a, t_pile **b)
{
	write(1, "rrr\n", 4);
	r(a);
	r(b);
}
