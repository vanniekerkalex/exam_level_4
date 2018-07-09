/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 17:40:20 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/26 18:17:01 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
	int size;
	int *num;
	size = end - start;
	if (size < 0)
		size = size * (-1) + 1;
	else
		size = size + 1;
	
	if(!(num = (int *)malloc(sizeof(int) * size + 1)))
		return (NULL);
	num[size--] = '\0';
	if (end > start)
		while (size >= 0)
			num[size--] = end--;
	else
		while (size >= 0)
			num[size--] = end++;
	return (num);
}

int main (void)
{
	int i = 0;
	int start = 0;
	int end = 0;
	int *num = ft_range(start, end);
	while (i < 1)
		printf("%d\n", num[i++]);
	return (0);
}
