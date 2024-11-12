/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:58:38 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 00:05:46 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_pf(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putunsigned_pf(n / 10);
		count += ft_putunsigned_pf(n % 10);
	}
	else
	{
		ft_putchar_pf(n + 48);
		count++;
	}
	return (count);
}
