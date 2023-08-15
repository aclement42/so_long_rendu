/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:58:22 by aclement          #+#    #+#             */
/*   Updated: 2023/01/25 18:48:10 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	unsigned int	ft_len(int c)
{
	unsigned int	i;

	i = 0;
	if (c <= 0)
		i = 1;
	while (c != 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int c)
{
	char			*new;
	int				signe;
	int				n;
	unsigned int	nbr;

	n = ft_len(c);
	signe = '\0';
	nbr = c;
	new = malloc(sizeof(char) * (n + 1));
	if (!(new))
		return (0);
	if (c < 0)
	{
		signe = '-';
		nbr = c * (-1);
	}
	new[n] = '\0';
	while (--n >= 0)
	{
		new[n] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (signe)
		new[0] = '-';
	return (new);
}
