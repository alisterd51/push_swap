/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:13:34 by user42            #+#    #+#             */
/*   Updated: 2021/05/19 18:44:34 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "struct.h"

/*
** stupid_sort.c
*/
void	stupid_sort(t_op **list_op, t_pile **a, t_pile **b);

/*
** one_pile_sort.c
*/
void	one_pile_sort(t_op **list_op, t_pile **a);

/*
** pre_sort.c
*/
void	pre_sort(t_pile **a);

/*
** opti_sort.c
*/
void	opti_sort(t_op **list_op, t_pile **a, t_pile **b);

#endif
