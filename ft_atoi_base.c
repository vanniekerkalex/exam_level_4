/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:17:20 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/27 17:18:26 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int i;
	int num;
	int sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str == '\0')
		return (0);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ' || str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
			|| (str[i] >= 'A' && str[i] <= 'F'))
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			num = (num * str_base) + (10 + ((str[i] - 'a') % 'a'));
		else if (str[i] >= 'A' && str[i] <= 'F')
			num = (num * str_base) + (10 + ((str[i] - 'A') % 'A'));
		else
			num = (num * str_base) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int main (void)
{
	printf("%d", ft_atoi_base("     -122", 10));
	return (0);
}
