/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:47:15 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/21 17:42:52 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "ft.h"

int	op_len(t_op *op)
{
	int	ret;

	ret = 0;
	while (op)
	{
		ret++;
		op = op->next;
	}
	return (ret);
}

int	op_push_back(t_op **op_ptr, char *str)
{
	t_op	*ptr;

	if (!*op_ptr)
	{
		*op_ptr = (t_op *)malloc(sizeof(t_op));
		if (!*op_ptr)
			return (1);
		ft_strcpy((*op_ptr)->op, str);
		(*op_ptr)->next = NULL;
	}
	else
	{
		ptr = *op_ptr;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = (t_op *)malloc(sizeof(t_op));
		if (!ptr->next)
			return (1);
		ft_strcpy(ptr->next->op, str);
		ptr->next->next = NULL;
	}
	return (0);
}

void	op_clear_one_elem(t_op **op_ptr, int i)
{
	t_op	*ptr1;
	t_op	*ptr2;

	if (!*op_ptr)
		return ;
	ptr1 = *op_ptr;
	if (i == 0)
	{
		*op_ptr = ptr1->next;
		free(ptr1);
		return ;
	}
	ptr2 = ptr1->next;
	while (--i > 0)
	{
		ptr1 = ptr2;
		ptr2 = ptr2->next;
	}
	ptr1->next = ptr2->next;
	free(ptr2);
}

void	op_clear(t_op **op_ptr)
{
	t_op	*ptr1;
	t_op	*ptr2;

	ptr1 = *op_ptr;
	while (ptr1)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
		free(ptr2);
	}
	*op_ptr = NULL;
}

void	op_write(t_op *op_ptr)
{
	while (op_ptr)
	{
		write(1, op_ptr->op, ft_strlen(op_ptr->op));
		op_ptr = op_ptr->next;
	}
}
