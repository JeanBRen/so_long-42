/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:37:14 by jrenier           #+#    #+#             */
/*   Updated: 2024/05/16 16:29:28 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*us1;
	const unsigned char	*us2;
	size_t				i;

	i = 0;
	us1 = (const unsigned char *) s1;
	us2 = (const unsigned char *) s2;
	while (i < n)
	{
		if (us1[i] != us2[i])
		{
			return (us1[i] - us2[i]);
		}
		i++;
	}
	return (0);
}
