/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:38:49 by ecortes-          #+#    #+#             */
/*   Updated: 2024/06/13 17:47:34 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdint.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*ptr;
	size_t	i;

	if (num >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	ptr = malloc(num * size);
	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr != NULL)
	{
		i = 0;
		while (i < num * size)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}
