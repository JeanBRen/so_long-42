/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:56:21 by jrenier           #+#    #+#             */
/*   Updated: 2024/05/23 10:19:56 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	tc;
	size_t	i;

	tc = (char) c;
	i = ft_strlen(s);
	if (tc == 0)
		return ((char *)s + ft_strlen(s));
	s += ft_strlen(s) - 1;
	while (i > 0)
	{
		if (*s == tc)
			return ((char *) s);
		s--;
		i--;
	}
	return (NULL);
}
