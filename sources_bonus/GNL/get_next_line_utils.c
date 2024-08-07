/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:38:29 by jrenier           #+#    #+#             */
/*   Updated: 2024/06/07 11:10:57 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*res;
	size_t			tot_size;
	size_t			i;
	unsigned char	*res1;

	if (!nmemb || !size)
		return (NULL);
	i = 0;
	tot_size = nmemb * size;
	if (nmemb != 0 && tot_size / nmemb != size)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	res1 = (unsigned char *) res;
	while (i < tot_size)
	{
		res1[i] = 0;
		i++;
	}
	return (res);
}

int	line_is_complete(t_list **stash)
{
	t_list	*temp;

	if (!*stash)
		return (0);
	temp = *stash;
	while (temp->next)
	{
		if (temp->content == '\n')
			return (1);
		temp = temp->next;
	}
	if (temp->content == '\n')
		return (1);
	return (0);
}

void	free_all(t_list **stash)
{
	t_list	*temp;

	if (!stash || !*stash)
		return ;
	while (*stash)
	{
		temp = *stash;
		*stash = (*stash)->next;
		free(temp);
	}
}

int	iter_buffer(char *buffer, t_list **stash)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (fill_stash (buffer[i], stash) == 1)
			return (free (buffer), free_all(stash), 1);
		i++;
	}
	return (0);
}
