/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:46:43 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/26 17:25:53 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1]
		write(1, &str[i], 1);

	}
}*/

int main (int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2 && argv[1])
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
			{
				if (argv[1][i + 1] == '.' && argv[1][i + 1])
				{

				} else if (argv[1][i + 1] > 32 && argv[1][i + 1])
					write(1, " ", 1);
			}
			else if (argv[1][i] != ' ' && argv[1][i] != '\t')
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
