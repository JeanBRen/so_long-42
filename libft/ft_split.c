/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:24:07 by jrenier           #+#    #+#             */
/*   Updated: 2024/05/24 10:53:32 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *s, char c)
{
	int	i;
	int	count;
	int	word_check;

	i = 0;
	count = 0;
	word_check = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c && word_check == 1)
		{
			word_check = 0;
			count++;
		}
		else if (s[i] == c)
			word_check = 1;
		i++;
	}
	return (count);
}

void	ft_free_all(char **result, int s_index)
{
	int	i;

	i = 0;
	while (i <= s_index)
	{
		free(result[i]);
		i++;
	}
}

void	ft_fill_line(const char *s, char c, char *result, int i)
{
	int	j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		result[j] = s[i];
		i++;
		j++;
	}
	result[j] = '\0';
}

int	ft_pre_split(const char *s, char c, char **result)
{
	int	i;
	int	s_index;
	int	j;

	i = 0;
	s_index = 0;
	while (s[i] != '\0')
	{
		j = 0;
		if (s[i] != c)
		{
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			result[s_index] = malloc((j + 1) * sizeof(char));
			if (!result[s_index])
				return (ft_free_all(result, s_index), 0);
			ft_fill_line(s, c, result[s_index], i);
			s_index++;
			i += j - 1;
		}
		i++;
	}
	result[s_index] = NULL;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = NULL;
	if (!s)
		return (NULL);
	result = malloc ((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (ft_pre_split(s, c, result) != -1)
	{
		free (result);
		return (NULL);
	}
	return (result);
}
