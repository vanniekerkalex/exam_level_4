/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:37:20 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/26 15:34:49 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int i;
	int sum;

	sum = 0;
	i = 0;
	if (str[0] == '-')
		return (0);
	
	while (*(str + i))
	{
		sum = sum * 10 + *(str + i) - '0';
		i++;
	}
	return (sum);
}

void ft_putnum(int num)
{
	char c;
	
	if (num > 0)
	{
		c = num % 10 + '0';
		num /= 10;
		ft_putnum(num);
		write(1, &c, 1);
	}
}

int ft_isprime(int n)
{
	int i;

	i = 2;
	while (i * i <= n)
		{
			if (n % i == 0)
				return (0);
			i++;
		}
	return (1);
}


int	ft_add_prime_sum(int sum)
{
	int i;
	int num;

	i = 3;
	num = 2;
	while (i <= sum)
	{
		if (ft_isprime(i))
			num += i;
		i++;
	}
	return (num);
}


int main(int argc, char **argv)
{
	int num;
	
	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		if (num <= 0)
			write(1, "0\n", 2);
		else
		{
			ft_putnum(ft_add_prime_sum(num));
			write(1, "\n", 1);
		}
	}
	else
		write(1, "0\n", 2);	
	return (0);
}
