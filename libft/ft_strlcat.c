/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:48:23 by jrenier           #+#    #+#             */
/*   Updated: 2024/05/21 10:22:12 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	length_dest;
	size_t	length_src;

	i = 0;
	length_dest = 0;
	length_src = 0;
	if ((!src || !dst) && siz == 0)
		return (0);
	length_dest = ft_strlen(dst);
	length_src = ft_strlen(src);
	if (siz == 0 || siz <= length_dest)
		return (length_src + siz);
	dst += length_dest;
	while (i < (siz - length_dest - 1) && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (length_dest + length_src);
}
