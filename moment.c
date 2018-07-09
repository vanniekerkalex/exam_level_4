/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 12:14:14 by exam              #+#    #+#             */
/*   Updated: 2018/06/26 13:37:10 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char    *moment(unsigned int duration)
{
	char *str;
	char *s;
	int ans;
	int temp;
	int count;
	int i;

	i = 0;
	temp = 0;
	count = 0;
	s = (char *)malloc(sizeof(char) * 50);
	ans = 0;
	if (duration < 60)
	{
		ans = duration;
		str = "seconds ago";
		if (ans == 1)
			str = "second ago";
	}
	else if (duration < 3600)
	{
		ans = duration / (60);
        str = "minutes ago";
        if (ans == 1)
            str = "minute ago";
	}
	else if (duration < 86400)
    {
        ans = duration / (60 * 60);
        str = "hours ago.";
        if (ans == 1)
            str = "hour ago";
    }
	else if (duration < 2592000)
    {
        ans = duration / (60 * 60 * 24);
        str = "days ago.";
		        if (ans == 1)
            str = "day ago";
    }
	else if (duration < 31104000)
    {
        ans = duration / (60 * 60 * 24 * 30);
        str = "months ago.";
		        if (ans == 1)
            str = "month ago";
    }
	temp = ans;	

	while (temp != 0)
	{
		temp = temp / 10;
		count++;
	}
	
	temp = ans;
	*(s + count) = '\0';
	while (count-- > 0)
	{
		*(s + count) = (temp % 10) + '0';
		temp = temp / 10;
	}
	if (ans == 0)
		*s = '0';
	
	while (*(s + i))
		i++;
	*(s + i++) = ' ';
	while (*str)
	{
		*(s + i++) = *str++;
	}
	*(s + i) = '\0';
	return (s);	
}

int main (void)
{
	printf("%s", moment (2400));
	return (0);
}
