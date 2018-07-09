/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:21:22 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/15 13:25:51 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int* tab, unsigned int len)
{
	int		max_size;

	max_size = 0;
	if (len == 0)
		return (0);
	while (len--)
	{
		if (*(tab + len) > max_size)
			max_size = *(tab + len);
	}
	return (max_size);
}
