/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:22:56 by jrenier           #+#    #+#             */
/*   Updated: 2024/07/24 14:27:00 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		tot_len;
	int		i;
	int		j;
	char	*result;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	tot_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(tot_len * sizeof (char));
	if (!result)
		return (NULL);
	while (s1[++j] != '\0')
		result[++i] = s1[j];
	j = -1;
	while (s2[++j] != '\0')
		result[++i] = s2[j];
	result[i + 1] = '\0';
	free(s1);
	return (result);
}
