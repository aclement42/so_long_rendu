/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:52:18 by aclement          #+#    #+#             */
/*   Updated: 2023/01/25 18:51:26 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (dst[i] && dstsize > 0)
	{
		i++;
		dstsize--;
	}
	while (src[l] && dstsize > 1)
	{
		dst[i] = src[l];
		i++;
		l++;
		dstsize--;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	while (src[l])
	{
		l++;
		i++;
	}
	return (i);
}
