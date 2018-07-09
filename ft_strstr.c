/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:17:07 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/26 18:55:13 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

int ft_strstr(char *s1, char *s2, int len)
{
	int j = 0;
	if (len == 0)
		return (1);
	while (*(s2 + j))
	{
		if (*(s1) == *(s2 + j) && *(s2 + j))
		{
			printf("s1: %c s2: %c len: %d\n", *s1, *(s2 + j), len);
			return (ft_strstr(s1 + 1, s2 + j + 1, len - 1));
		}
		j++;
	}
	return (0);
}

int main(int argc, char **argv)
{	
	char *s1 = argv[1];
	char *s2 = argv[2];
	int ret;
	
	if (argc == 3)
	{
		ret = ft_strstr(s1, s2, ft_strlen(s1));
		if (ret == 1)
			write(1, "1", 1);
		else
			write (1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
