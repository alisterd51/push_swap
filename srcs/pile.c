/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:47:15 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/19 10:31:28 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"

int	pile_len(t_pile *pile)
{
	int	ret;

	ret = 0;
	while (pile)
	{
		ret++;
		pile = pile->next;
	}
	return (ret);
}

int	pile_elem_value(t_pile *pile, int i)
{
	while (i-- > 0)
		pile = pile->next;
	return (pile->value);
}

int	pile_push_back(t_pile **pile_ptr, int value)
{
	t_pile	*ptr;

	if (!*pile_ptr)
	{
		*pile_ptr = (t_pile *)malloc(sizeof(t_pile));
		if (!*pile_ptr)
			return (1);
		(*pile_ptr)->value = value;
		(*pile_ptr)->next = NULL;
	}
	else
	{
		ptr = *pile_ptr;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = (t_pile *)malloc(sizeof(t_pile));
		if (!ptr->next)
			return (1);
		ptr->next->value = value;
		ptr->next->next = NULL;
	}
	return (0);
}

void	pile_clear(t_pile **pile_ptr)
{
	t_pile	*ptr1;
	t_pile	*ptr2;

	ptr1 = *pile_ptr;
	while (ptr1)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
		free(ptr2);
	}
	*pile_ptr = NULL;
}

t_pile	*piledup(t_pile *src)
{
	t_pile	*ret;

	ret = NULL;
	while (src)
	{
		if (pile_push_back(&ret, src->value))
		{
			pile_clear(&ret);
			return (NULL);
		}
		src = src->next;
	}
	return (ret);
}
