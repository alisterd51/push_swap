/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:39:13 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/13 18:09:37 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft.h"
#include "pile.h"

static int	parse_line(t_pile **a, char *str)
{
	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		if (!ft_secure_atoi(str))
			return (1);
		if (*str && pile_push_back(a, ft_atoi(str)))
			return (1);
		while (ft_isdigit(*str))
			str++;
		while (ft_isspace(*str))
			str++;
		if (*str && !ft_isdigit(*str))
			return (1);
	}
	return (0);
}

static int	parse_value(t_pile **a, char *str)
{
	if (ft_secure_atoi(str))
		return (1);
	return (pile_push_back(a, ft_atoi(str)));
}

int	parse(t_pile **a, int ac, char **av)
{
	int	i;

	if (ac == 1)
		return (parse_line(a, *av));
	i = 0;
	while (i < ac)
		if (parse_value(a, av[i++]))
			return (1);
	return (0);
}
