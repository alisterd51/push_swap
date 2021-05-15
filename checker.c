/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:47:07 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/15 16:22:47 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "push_swap.h"
#include "ft.h"
#include "op.h"

static void	op_2(t_op **list_op, char *line, t_pile **a, t_pile **b)
{
	if (line[0] == 's' && line[1] == 'a')
		sa(list_op, a);
	else if (line[0] == 's' && line[1] == 'b')
		sb(list_op, b);
	else if (line[0] == 's' && line[1] == 's')
		ss(list_op, a, b);
	else if (line[0] == 'p' && line[1] == 'a')
		pa(list_op, a, b);
	else if (line[0] == 'p' && line[1] == 'b')
		pb(list_op, a, b);
	else if (line[0] == 'r' && line[1] == 'a')
		ra(list_op, a);
	else if (line[0] == 'r' && line[1] == 'b')
		rb(list_op, b);
	else if (line[0] == 'r' && line[1] == 'r')
		rr(list_op, a, b);
}

static void	op_3(t_op **list_op, char *line, t_pile **a, t_pile **b)
{
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		rra(list_op, a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		rrb(list_op, b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
		rrr(list_op, a, b);
}

static void	apply_op(t_op **list_op, char *line, t_pile **a, t_pile **b)
{
	int	len;

	len = ft_strlen(line);
	if (len == 2)
		return (op_2(list_op, line, a, b));
	else if (len == 3)
		return (op_3(list_op, line, a, b));
	else
		return ;
}

static void	apply_input(t_pile **a, t_pile **b)
{
	char	*line;
	t_op	*list_op;

	line = NULL;
	list_op = NULL;
	while (get_next_line(0, &line) > 0)
	{
		apply_op(&list_op, line, a, b);
		free(line);
	}
	if (!*b && pile_is_sorted(*a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	op_clear(&list_op);
}

int	main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (parse(&a, ac - 1, av + 1))
	{
		write(2, "Error\n", 6);
		pile_clear(&a);
		return (2);
	}
	apply_input(&a, &b);
	pile_clear(&a);
	pile_clear(&b);
	return (0);
}
