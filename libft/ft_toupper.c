/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:17:37 by ecortes-          #+#    #+#             */
/*   Updated: 2023/09/11 17:17:39 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	a;

	a = c;
	if (a >= 'A' && a <= 'Z')
		return (a);
	if (a >= 'a' && a <= 'z')
		return (a - 32);
	return (c);
}
