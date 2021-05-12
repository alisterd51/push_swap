/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:07:40 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/12 18:15:51 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "op.h"
#include "pile.h"

int	main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	b = NULL;
	pile_push_back(&a, 2);
	pile_push_back(&a, 1);
	pile_push_back(&a, 3);
	pile_push_back(&a, 6);
	pile_push_back(&a, 5);
	pile_push_back(&a, 8);
	pile_write(a);
	sa(&a);
	pile_write(a);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	pile_write(a);
	rr(&a, &b);
	pile_write(a);
	rrr(&a, &b);
	pile_write(a);
	sa(&a);
	pile_write(a);
	pa(&a, &b);
	pa(&a, &b);
	pa(&a, &b);
	pile_write(a);
	pile_clear(&a);
	(void)ac;
	(void)av;
	(void)b;
	return (0);
}
