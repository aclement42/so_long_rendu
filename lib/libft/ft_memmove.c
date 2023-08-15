/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:37:34 by aclement          #+#    #+#             */
/*   Updated: 2019/11/22 19:34:22 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	i = 0;
	if (src == dst)
		return (dst);
	if (pdst > psrc)
	{
		while (++i <= len)
			pdst[len - i] = psrc[len - i];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
