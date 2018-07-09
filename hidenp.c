/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:17:07 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/26 19:10:47 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int main(int argc, char **argv)
{	
	char *s1;
	char *s2;
	int i = 0;
	int j = 0;
	int len = 0;
	int count = 0;

	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		len = ft_strlen(s1);

		while (*(s2 + j))
		{
			if(*(s1 + i) == *(s2 + j))
			{
				i++;
				count++;
			}
			j++;
			if (count == len)
			{
				write(1, "1", 1);
				break ;
			}
		}
		if (count != len)
			write (1, "0", 1);
	}
	write(1,"\n", 1);
	return (0);
}
