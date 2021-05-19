/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entropy_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:06:59 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/19 14:13:39 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "push_swap.h"
#include "op.h"

void	test(t_op **list_op, t_pile **a)
{
	(void)list_op;
	(void)a;
}

void	entropy_sort(t_op **list_op, t_pile **a)
{
	while (!pile_is_sorted(*a))
		test(list_op, a);
	op_optimizer(list_op);
}
