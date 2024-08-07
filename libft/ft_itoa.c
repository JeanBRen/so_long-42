/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:14:07 by jrenier           #+#    #+#             */
/*   Updated: 2024/05/23 10:21:51 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n >= 10)
	{
		count++;
		n /= 10;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;
	long	temp;
	int		neg;

	neg = 0;
	temp = (long)n;
	size = ft_size(temp);
	result = malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		temp = (long)n * -1;
		neg = 1;
	}
	result[size] = '\0';
	while (size > neg)
	{
		result[size - 1] = temp % 10 + '0';
		size--;
		temp /= 10;
	}
	return (result);
}
