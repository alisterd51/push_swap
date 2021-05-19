/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:56:38 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/19 19:07:59 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sort.h"
#include "struct.h"
#include "op.h"
#include "push_swap.h"

#include <unistd.h>

void	solve(t_pile **a, t_pile **b)
{
	t_op	*list_op[3];
	t_pile	*cpy_a[3];

	list_op[0] = NULL;
	list_op[1] = NULL;
	cpy_a[0] = piledup(*a);
	cpy_a[1] = piledup(*a);
	stupid_sort(&(list_op[0]), &(cpy_a[0]), b);
	one_pile_sort(&(list_op[1]), &(cpy_a[1]));
	if (op_len(list_op[0]) <= op_len(list_op[1]))
		op_write(list_op[0]);
	else
		op_write(list_op[1]);
	op_clear(&(list_op[0]));
	op_clear(&(list_op[1]));
	pile_clear(&(cpy_a[0]));
	pile_clear(&(cpy_a[1]));
}
