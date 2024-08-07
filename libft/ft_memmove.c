/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:12:31 by jrenier           #+#    #+#             */
/*   Updated: 2024/05/16 13:49:09 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src1;
	unsigned char		*dest1;

	src1 = (const unsigned char *) src;
	dest1 = (unsigned char *) dest;
	if (!dest && !src)
		return (NULL);
	if (dest1 < src1)
	{
		while (n--)
			*dest1++ = *src1++;
	}
	else
	{
		dest1 += n;
		src1 += n;
		while (n--)
			*--dest1 = *--src1;
	}
	return (dest);
}
