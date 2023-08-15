/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:16:34 by aclement          #+#    #+#             */
/*   Updated: 2022/12/14 12:02:08 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	t_env_printf	var;

	ft_bzero(&var, sizeof(t_env_printf));
	va_start(var.ap, str);
	var.str = (char *)str;
	ft_firstparse(&var);
	va_end(var.ap);
	return (var.ret);
}
