/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:15:39 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/10 12:12:56 by avan-ni          ###   ########.fr       */
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
			ft_putchar(*str);
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
				{
					argv--;
					break ;
				}
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
						argv++;
						break ;
					}
				}
		}
		argv++;
	}
}

int main (int argc, char **argv)
{
	char *str;
	int i = 4096;
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	while (i >= 0)
		str[i--] = '\0';
	if (argc == 2)
	{
		brainfuck(argv[1], str);
	}
	else
		write(1, "\n", 1);
	return (0);
}
