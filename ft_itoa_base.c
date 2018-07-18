/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:47:06 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/11 19:20:29 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     num_len(int val, int base)
{
    int len = 0;
    if (val <= 0)
    {
        if (base == 10)
            len++;
        val *= -1;
    }
    while (val > 0)
    {
        len++;
        val /= base;
    }
    return (len);
}

char    *ft_itoa_base(int value, int base)
{
    char *val = "0123456789ABCDEF";
    int len = num_len(value, base);
    int i = len - 1;
    char *str = (char *)malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    if (value == -2147483648)
    {
        str = "-2147483648";
        return (str);
    }
    if (value == 0)
    {
        str[0] = '0';
        return (str);
    }
    if (value < 0 && base == 10)
    {
        str[0] = '-';
        value *= -1;
    }
    if (value < 0 && base != 10)
        value *= -1;
    while (value > 0)
    {
        str[i--] = val[value % base];
        value /= base;
    }
    return (str);
}

int main (void)
{
    int num = -196849156;
    int base = 3;
    printf("%s", ft_itoa_base(num, base));
    return (0);
}
