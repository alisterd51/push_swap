/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:13:34 by user42            #+#    #+#             */
/*   Updated: 2021/05/15 12:17:59 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_pile	t_pile;
struct	s_pile
{
	int		value;
	t_pile	*next;
};

typedef struct s_op		t_op;
struct	s_op
{
	char	op[4];
	t_op	*next;
};

#endif
