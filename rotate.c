/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:34:15 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/12 17:38:05 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "op.h"

static void	r(t_pile **pile_ptr)
{
	t_pile	*ptr;

	if (!*pile_ptr || (*pile_ptr)->next)
		return ;
	ptr = *pile_ptr;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *pile_ptr;
	*pile_ptr = (*pile_ptr)->next;
	ptr->next->next = NULL;
}

void	ra(t_pile **a)
{
	write(1, "ra\n", 3);
	r(a);
}

void	rb(t_pile **b)
{
	write(1, "rb\n", 3);
	r(b);
}

void	rr(t_pile **a, t_pile **b)
{
	write(1, "rr\n", 3);
	r(a);
	r(b);
}
