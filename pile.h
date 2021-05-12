/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:38:01 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/12 17:13:45 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILE_H
# define PILE_H

# include "struct.h"

/*
** pile.c
*/
int		pile_push_back(t_pile **pile_ptr, int value);
void	pile_clear(t_pile **pile_ptr);
void	pile_write(t_pile *pile_ptr);

#endif
