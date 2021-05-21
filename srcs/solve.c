/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:56:38 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/21 18:04:52 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sort.h"
#include "struct.h"
#include "op.h"
#include "push_swap.h"

static t_op	*selector(t_op *list_op[3])
{
	const int	len0 = op_len(list_op[0]);
	const int	len1 = op_len(list_op[1]);
	const int	len2 = op_len(list_op[2]);

	if (len0 < len1 && len0 < len2)
		return (list_op[0]);
	else if (len1 < len0 && len1 < len2)
		return (list_op[1]);
	else
		return (list_op[2]);
}

static void	solve_all(t_op *list_op[3], t_pile **a, t_pile **b)
{
	t_pile	*cpy_a[3];

	cpy_a[0] = piledup(*a);
	cpy_a[1] = piledup(*a);
	cpy_a[2] = piledup(*a);
	stupid_sort(&(list_op[0]), &(cpy_a[0]), b);
	one_pile_sort(&(list_op[1]), &(cpy_a[1]));
	opti_sort(&(list_op[2]), &(cpy_a[2]), b);
	op_write(selector(list_op));
	op_clear(&(list_op[0]));
	op_clear(&(list_op[1]));
	op_clear(&(list_op[2]));
	pile_clear(&(cpy_a[0]));
	pile_clear(&(cpy_a[1]));
	pile_clear(&(cpy_a[2]));
}

static void	solve_fast(t_op *list_op[3], t_pile **a, t_pile **b)
{
	t_pile	*cpy_a[2];

	cpy_a[0] = piledup(*a);
	cpy_a[1] = piledup(*a);
	stupid_sort(&(list_op[0]), &(cpy_a[0]), b);
	opti_sort(&(list_op[1]), &(cpy_a[1]), b);
	if (op_len(list_op[0]) < op_len(list_op[1]))
		op_write(list_op[0]);
	else
		op_write(list_op[1]);
	op_clear(&(list_op[0]));
	op_clear(&(list_op[1]));
	pile_clear(&(cpy_a[0]));
	pile_clear(&(cpy_a[1]));
}

void	solve(t_pile **a, t_pile **b)
{
	t_op	*list_op[3];

	list_op[0] = NULL;
	list_op[1] = NULL;
	list_op[2] = NULL;
	if (pile_len(*a) < 50)
		solve_all(list_op, a, b);
	else
		solve_fast(list_op, a, b);
}
