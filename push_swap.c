/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:07:40 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/12 21:04:44 by anclarma         ###   ########.fr       */
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
	pile_write(a, b);
	sa(&a);
	pile_write(a, b);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	pile_write(a, b);
	rr(&a, &b);
	pile_write(a, b);
	rrr(&a, &b);
	pile_write(a, b);
	sa(&a);
	pile_write(a, b);
	pa(&a, &b);
	pa(&a, &b);
	pa(&a, &b);
	pile_write(a, b);
	pile_clear(&a);
	(void)ac;
	(void)av;
	(void)b;
	return (0);
}
