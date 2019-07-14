/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:23:50 by hnam              #+#    #+#             */
/*   Updated: 2019/04/04 01:23:52 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_u(uint64_t n)
{
	if (n >= 10)
		ft_putnbr_u(n / 10);
	ft_putchar((n % 10) + '0');
}
