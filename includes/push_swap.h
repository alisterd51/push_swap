/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:34:00 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/15 17:25:20 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "struct.h"

/*
** parse.c
*/
int		parse(t_pile **a, int ac, char **av);

/*
** solve.c
*/
void	solve(t_pile **a, t_pile **b);

/*
** is_sorted.c
*/
int		pile_is_sorted(t_pile *pile);

#endif
