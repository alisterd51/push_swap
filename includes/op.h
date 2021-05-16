/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:47:05 by user42            #+#    #+#             */
/*   Updated: 2021/05/16 15:39:48 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "struct.h"

/*
** pile.c
*/
int		pile_len(t_pile *pile);
int		pile_elem_value(t_pile *pile, int i);
int		pile_push_back(t_pile **pile_ptr, int value);
void	pile_clear(t_pile **pile_ptr);

/*
** op_optimizer.c
*/
void	op_optimizer(t_op **list_op);

/*
** op.c
*/
int		op_push_back(t_op **op_ptr, char *str);
void	op_clear_one_elem(t_op **op_ptr, int i);
void	op_clear(t_op **op_ptr);
void	op_write(t_op *op_ptr);

/*
** swap.c
*/
void	sa(t_op **list_op, t_pile **a);
void	sb(t_op **list_op, t_pile **b);
void	ss(t_op **list_op, t_pile **a, t_pile **b);

/*
** push.c
*/
void	pa(t_op **list_op, t_pile **a, t_pile **b);
void	pb(t_op **list_op, t_pile **a, t_pile **b);

/*
** rotate.c
*/
void	ra(t_op **list_op, t_pile **a);
void	rb(t_op **list_op, t_pile **b);
void	rr(t_op **list_op, t_pile **a, t_pile **b);

/*
** rrotate.c
*/
void	rra(t_op **list_op, t_pile **a);
void	rrb(t_op **list_op, t_pile **b);
void	rrr(t_op **list_op, t_pile **a, t_pile **b);

#endif