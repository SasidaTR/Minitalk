/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:38:30 by hrischma          #+#    #+#             */
/*   Updated: 2024/06/14 15:26:04 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h> 
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_puthex(unsigned long n);
int		ft_puthex_upper(unsigned int n);
int		ft_putptr(void *ptr);
int		ft_printf(const char *format, ...);

/* libc Functions */
size_t	ft_strlen(const char *s);
int		ft_isprint(int c);
int		ft_atoi(const char *str);

/* Additional Functions */
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putchar_fd(char c, int fd);

#endif
