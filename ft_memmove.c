/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:10:14 by hsennane          #+#    #+#             */
/*   Updated: 2024/11/19 12:48:59 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;
	char	*lastd;
	char	*lasts;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	lastd = d + len - 1;
	lasts = s + len - 1;
	if (!dst && !src)
	{
		return (NULL);
	}
	if (dst == src)
	{
		return (dst);
	}
	if (d < s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*lastd = *lasts;
			lastd--;
			lasts--;
			i++;
		}
	}
	return (dst);
}
