/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:59:24 by hrischma          #+#    #+#             */
/*   Updated: 2024/06/02 15:59:25 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				len;

	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	addr = (unsigned long)ptr;
	len = 2;
	ft_putstr("0x");
	len += ft_puthex(addr);
	return (len);
}
