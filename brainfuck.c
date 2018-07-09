/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:15:39 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/09 18:17:46 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	brainfuck(char *argv, char *str)
{
	int loop = 0;
	while (*argv != '\0')
	{
		if (*argv == '>')
			str++;
		if (*argv == '<')
			str--;
		if (*argv == '+')
			*str += 1;
		if (*argv == '-')
			*str -= 1;
		if (*argv == '.')
		{
			ft_putchar(*str);
			write(1," | ", 3);
			ft_putchar(*argv);
			write(1, "\n", 1);
		}
		if (*argv == '[' && *str == 0) 
		{
			loop = 0;
			while (1)
			{
				if (*argv == '[')
					loop++;
				if (*argv == ']')
					loop--;
				argv++;
				if (loop == 0)
					break ;
			}
		}
		if (*argv == ']' && *str != 0)
		{
				loop = 0;
				while (1)
				{
					if (*argv == ']')
						loop++;
					if (*argv == '[')
						loop--;
					argv--;
					if (loop == 0)
					{
						argv += 2;
						break ;
					}
				}
		}
		argv++;

	//ft_putchar(*argv);
	//write(1," | ", 3);
	//ft_putchar(*str);
	//write(1, "\n", 1);
	}
}

int main (int argc, char **argv)
{
	char *str;
	int i = 4096;
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	while (i >= 0)
		str[i--] = '0';

	if (argc == 2)
	{
		brainfuck(argv[1], str);
	}
	return (0);
}
