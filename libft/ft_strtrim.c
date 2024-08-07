/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:12:41 by jrenier           #+#    #+#             */
/*   Updated: 2024/05/22 17:02:08 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_sepa(char c1, char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == c1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_length(char const *s1, char const *set)
{
	int	length;
	int	i;

	i = -1;
	length = ft_strlen(s1) - 1;
	while (ft_is_sepa((char) s1[length], (char *) set) == 1)
		length--;
	while (ft_is_sepa((char) s1[++i], (char *) set) == 1)
		length--;
	if (length < 0)
		length = -1;
	return (length);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	length = ft_length(s1, set);
	while (ft_is_sepa((char) s1[i], (char *) set) == 1)
		i++;
	result = malloc (length + 2 * sizeof(char));
	if (!result)
		return (NULL);
	while (j <= length)
	{
		result[j] = s1[i + j];
		j++;
	}
	result[j] = '\0';
	return (result);
}
