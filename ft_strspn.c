/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:14:01 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/15 13:18:15 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t  ft_strspn(const char *s, const char *accept)
{
	size_t i;

	i = 0;
	if (!*accept || !*s)
		return (0);
	while ((*(s + i) == *(accept + i)) && *(accept + i) && *(s + i))
		i++;
	return (i);
}
