/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:47:15 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/12 20:58:55 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

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

void	pile_write(t_pile *a, t_pile *b)
{
	while (a || b)
	{
		if (a)
		{
			printf("%d ", a->value);
			a = a->next;
		}
		else
			printf("  ");
		if (b)
		{
			printf("%d\n", b->value);
			b = b->next;
		}
		else
			printf(" \n");
	}
	printf("\n");
}
