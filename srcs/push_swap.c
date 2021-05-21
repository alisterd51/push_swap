/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:07:40 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/21 21:46:35 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "push_swap.h"
#include "op.h"

int	main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (parse(&a, ac - 1, av + 1))
	{
		write(2, "Error\n", 6);
		pile_clear(&a);
		return (1);
	}
	solve(&a, &b);
	pile_clear(&a);
	pile_clear(&b);
	return (0);
}
