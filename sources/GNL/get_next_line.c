/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:38:25 by jrenier           #+#    #+#             */
/*   Updated: 2024/06/07 11:12:12 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	fill_stash(char buffer, t_list **stash)
{
	t_list	*temp;
	t_list	*last;

	temp = malloc (sizeof(t_list));
	if (!temp)
		return (1);
	temp->content = buffer;
	temp->next = NULL;
	if (!*stash)
		(*stash) = temp;
	else
	{
		last = (*stash);
		while (last->next)
			last = last->next;
		last->next = temp;
	}
	return (0);
}

int	get_stash(t_list **stash, int fd)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && line_is_complete(stash) == 0)
	{
		buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buffer)
			return (1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
			iter_buffer(buffer, stash);
		if (bytes_read < 0)
			return (free (buffer), free_all(stash), 1);
		free (buffer);
	}	
	return (0);
}

int	line_len(t_list **stash)
{
	int		i;
	t_list	*temp;

	temp = *stash;
	i = 0;
	while (temp && temp->next != NULL)
	{
		if (temp->content == '\n')
			return (i + 2);
		i++;
		temp = temp->next;
	}
	return (i + 2);
}

char	*get_current_line(t_list **stash)
{
	int		i;
	t_list	*temp;
	char	*line;

	temp = *stash;
	line = ft_calloc (line_len(stash), sizeof(char));
	if (!line)
		return (stash = NULL, NULL);
	i = 0;
	while ((*stash)->content != '\n' && (*stash)->next != NULL)
	{
		line[i] = (*stash)->content;
		i++;
		temp = *stash;
		*stash = (*stash)->next;
		free (temp);
	}
	temp = *stash;
	line[i] = (*stash)->content;
	*stash = (*stash)->next;
	free (temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line_is_complete(&stash) == 0)
	{
		if (get_stash (&stash, fd) == 1)
			return (NULL);
	}
	if (!stash)
	{
		free_all (&stash);
		return (NULL);
	}
	line = get_current_line(&stash);
	if (!line)
	{
		free_all (&stash);
		stash = NULL;
		free (line);
		return (NULL);
	}
	return (line);
}
