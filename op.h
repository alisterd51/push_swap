/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:47:05 by user42            #+#    #+#             */
/*   Updated: 2021/05/15 14:34:30 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "struct.h"

/*
** pile.c
*/
int		pile_push_back(t_pile **pile_ptr, int value);
void	pile_clear(t_pile **pile_ptr);
void	pile_write(t_pile *a, t_pile *b);

/*
** op.c
*/
int		op_push_back(t_op **op_ptr, char *str);
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
