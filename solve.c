/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:56:38 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/15 17:51:56 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sort.h"
#include "struct.h"
#include "op.h"
#include "push_swap.h"

void	solve(t_pile **a, t_pile **b)
{
	t_op	*list_op;

	list_op = NULL;
	stupid_sort(&list_op, a, b);
	op_write(list_op);
	op_clear(&list_op);
}
