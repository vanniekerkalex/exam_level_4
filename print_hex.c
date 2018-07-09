/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 11:48:58 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/27 12:14:39 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_numstr(char *str)
{
	int sum = 0;
	int i = 0;
	while (*(str + i))
		sum = (sum * 10) + str[i++] - '0';
	return (sum);
}

void	ft_puthex(int num)
{
	char c;
	char *str = "0123456789abcdef";
	
	if (num > 0)
	{
		c = str[num % 16];
		num /= 16;
		ft_puthex(num);
		write(1, &c, 1);
	}
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		ft_puthex(ft_numstr(argv[1]));
	}
	write(1, "\n", 1);
	return (0);
}
