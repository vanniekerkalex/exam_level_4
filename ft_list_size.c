/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 17:28:55 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/26 17:38:45 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int count;
	t_list temp;

	temp = begin_list;
	count = 0;
	while (*(temp))
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
