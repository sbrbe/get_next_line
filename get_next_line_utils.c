/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:59:04 by sbarbe            #+#    #+#             */
/*   Updated: 2023/11/02 18:09:52 by sbarbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	if (!c)
		return (((char *)s) + ft_strlen(s));
	i = -1;
	while (((char *)s)[++i])
		if (((char *)s)[i] == (unsigned char) c)
			return (((char *)s) + i);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tmp;
	void	*ar;

	tmp = nmemb * size;
	if (!nmemb || !size)
		return (malloc(1));
	if (tmp / size != nmemb)
		return (0);
	ar = malloc(tmp);
	if (ar)
	{
		while (tmp > 0)
		{
			((char *)ar)[tmp - 1] = '\0';
			tmp--;
		}
	}
	return (ar);
}
