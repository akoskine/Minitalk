/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:06:14 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 00:06:14 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	malloc_size;

	if (count == 0 || size == 0)
		return (ft_calloc (1, 1));
	malloc_size = size * count;
	if (malloc_size / size != count)
		return (NULL);
	ptr = malloc(malloc_size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, malloc_size);
	return (ptr);
}
