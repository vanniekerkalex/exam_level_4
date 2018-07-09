/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 12:20:04 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/27 12:55:52 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print(char *str)
{
	int i = 0;
	while (*(str + i))
		write(1, &*(str + i++), 1);
}

void check(char *str)
{
	int i = 0;
	while(*(str + i))
	{
		while (((*(str + i) >= 65 && *(str + i) <= 90) ||
				(*(str + i) >= 97 && *(str + i) <= 122)) && *(str + i))
		{
			if (!(*(str + i + 1) >= 65 && *(str + i + 1) <= 90) &&
					!(*(str + i + 1) >= 97 && *(str + i + 1) <= 122))
			{
				if (*(str + i) >= 97 && *(str + i) <= 122)
					*(str + i) = *(str + i) - 32;
			}
			else
			{
				if (*(str + i) >= 65 && *(str + i) <= 90)
					*(str + i) = *(str + i) + 32;
			}
			i++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			check(argv[i]);
			print(argv[i]);
			write(1, "\n", 1);
			i++;
		}

	}
	write(1, "\n", 1);
	return (0);
}
