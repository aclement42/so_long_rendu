/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:46:54 by aclement          #+#    #+#             */
/*   Updated: 2022/12/14 11:40:32 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*char	*ft_strdup(const char *s)
{
	char	*newchaine;
	int		i;

	i = 0;
	if (!(newchaine = malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		newchaine[i] = s[i];
		i++;
	}
	newchaine[i] = '\0';
	return (newchaine);
}*/
char	*ft_strdup(char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
