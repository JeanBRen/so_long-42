/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:45:02 by jrenier           #+#    #+#             */
/*   Updated: 2024/05/23 10:13:43 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{	
	char	tempc;

	tempc = (char) c;
	if (tempc == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == tempc)
			return ((char *)s);
		s++;
	}
	return (0);
}
