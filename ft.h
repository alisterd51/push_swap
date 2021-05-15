/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:43:04 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/15 15:46:46 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stddef.h>

/*
** ft_is.c
*/
int		ft_isspace(int c);
int		ft_isdigit(int c);

/*
** ft_secure_atoi.c
*/
int		ft_secure_atoi(const char *str);

/*
** ft_atoi.c
*/
int		ft_atoi(const char *str);

/*
** get_next_line.c
*/
int		get_next_line(int fd, char **line);

/*
** ft_strdup.c
*/
char	*ft_strdup(const char *s1);

/*
** ft_strjoin.c
*/
char	*ft_strjoin(char const *s1, char const *s2);

/*
** ft_strlen.c
*/
size_t	ft_strlen(const char *s);

/*
** ft_strcpy.c
*/
char	*ft_strcpy(char *dest, const char *src);

#endif
