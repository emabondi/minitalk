/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:30:18 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/05 20:40:31 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>

char	*get_next_line(int fd);
int		ft_strchr_gnl(const char *s, char c);
int		ft_strcpy_gnl(char *s1, char *s2);
size_t	ft_strlen_gnl(char const *str);
char	*ft_strdup_gnl(char *str);
char	*ft_strjoin_gnl(char *str, char *buffer);
char	*ft_split_gnl(char *str);

#endif