/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:58:43 by jrenier           #+#    #+#             */
/*   Updated: 2024/05/27 09:59:51 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c < 48 || c > 57)
		&& (c < 65 || c > 90) && (c < 97 || c > 122))
		return (0);
	return (1);
}
