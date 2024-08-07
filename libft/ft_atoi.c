/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:58:40 by jrenier           #+#    #+#             */
/*   Updated: 2024/05/15 16:59:57 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13 && nptr[i] != '\0') || nptr[i] == 32)
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{	
		if (nptr[i] == 45)
			sign *= -1;
		i++;
	}
	while ((nptr[i] > 47 && nptr [i] < 58) && nptr[i] != '\0')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}
