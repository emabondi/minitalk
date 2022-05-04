/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:28:52 by ebondi            #+#    #+#             */
/*   Updated: 2022/01/31 14:54:23 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_struct
{
	int	count;
	int	minus;
	int	zero;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	precision;
}				t_struct;

int		ft_printf(const char *str, ...);
void	ft_struct_init(t_struct *params);
int		ft_resolver(const char *str, va_list arg, t_struct *params);
int		ft_checkidentifier(char c);
void	resolver_c(const char *str, char c, t_struct *params);
void	write_spaces(int len, char c, t_struct *params);
int		check_minus(char c, t_struct *params);
int		find_wop(const char *str, int *j);
void	resolver_s(const char *str, char *word, t_struct *params);
void	resolver_d(int num, t_struct *params);
void	resolver_p(unsigned long i, t_struct *params);
void	ft_putnbr_base(unsigned long nbr, char *base, t_struct *params);
int		ft_putchar(char c);
void	resolver_u(int num, t_struct *params);

#endif
