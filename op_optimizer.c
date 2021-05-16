/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_optimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:22:03 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/16 17:00:54 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft.h"
#include "op.h"

static int	check_rr_rrr(t_op **list_op, t_op *op1, t_op *op2, int i)
{
	if ((!ft_strcmp(op1->op, "ra\n") && !ft_strcmp(op2->op, "rb\n"))
		|| (!ft_strcmp(op1->op, "rb\n") && !ft_strcmp(op2->op, "ra\n")))
	{
		op_clear_one_elem(list_op, i);
		ft_strcpy(op2->op, "rr\n");
		return (1);
	}
	if ((!ft_strcmp(op1->op, "rra\n") && !ft_strcmp(op2->op, "rrb\n"))
		|| (!ft_strcmp(op1->op, "rrb\n") && !ft_strcmp(op2->op, "rra\n")))
	{
		op_clear_one_elem(list_op, i);
		ft_strcpy(op2->op, "rrr\n");
		return (1);
	}
	return (0);
}

static int	check_ri_rri_pp(t_op **list_op, t_op *op1, t_op *op2, int i)
{
	if ((!ft_strcmp(op1->op, "ra\n") && !ft_strcmp(op2->op, "rra\n"))
		|| (!ft_strcmp(op1->op, "rb\n") && !ft_strcmp(op2->op, "rrb\n"))
		|| (!ft_strcmp(op1->op, "rr\n") && !ft_strcmp(op2->op, "rrr\n"))
		|| (!ft_strcmp(op1->op, "rra\n") && !ft_strcmp(op2->op, "ra\n"))
		|| (!ft_strcmp(op1->op, "rrb\n") && !ft_strcmp(op2->op, "rb\n"))
		|| (!ft_strcmp(op1->op, "rrr\n") && !ft_strcmp(op2->op, "rr\n")))
	{
		op_clear_one_elem(list_op, i);
		op_clear_one_elem(list_op, i);
		return (1);
	}
	if ((!ft_strcmp(op1->op, "pa\n") && !ft_strcmp(op2->op, "pb\n"))
		|| (!ft_strcmp(op1->op, "pb\n") && !ft_strcmp(op2->op, "pa\n")))
	{
		op_clear_one_elem(list_op, i);
		op_clear_one_elem(list_op, i);
		return (1);
	}
	return (0);
}

static int	check_pile(t_op **list_op)
{
	int		i;
	t_op	*op1;
	t_op	*op2;

	if (!*list_op || !(*list_op)->next)
		return (0);
	op1 = *list_op;
	op2 = op1->next;
	i = 0;
	while (op1 && op2)
	{
		if (check_rr_rrr(list_op, op1, op2, i))
			return (1);
		if (check_ri_rri_pp(list_op, op1, op2, i))
			return (1);
		op1 = op2;
		op2 = op2->next;
		i++;
	}
	return (0);
}

void	op_optimizer(t_op **list_op)
{
	int	change;

	change = 1;
	while (change)
	{
		change = check_pile(list_op);
	}
}
