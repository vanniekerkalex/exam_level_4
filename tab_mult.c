/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 11:03:07 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/27 11:42:21 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_numstr(char *str)
{
	int  sum = 0;
	int i = 0;
	while (*(str + i))
		sum = (sum * 10) + str[i++] - '0';
	return (sum);
}

void ft_putnbr(int num)
{
	char c;

	if (num > 0)
	{
		c = num % 10 + '0';
		num /= 10;
		ft_putnbr(num);
		write(1, &c, 1);
	}

}

int main (int argc, char **argv)
{
	int i = 1;
	if (argc == 2 && *argv[1])
	{
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(ft_numstr(argv[1]));
			write(1, " = ", 3);
			ft_putnbr(ft_numstr(argv[1]) * i);
			write(1, "\n", 1);
			i++;
		}
	} else
	{
		write(1, "\n", 1);
	}
	return (0);	
}
