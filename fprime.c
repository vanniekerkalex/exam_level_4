/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:07:12 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/11 17:07:49 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv)
{
    int num = 0;
    int i = 2;
    if (argc == 2)
    {
        num = atoi(argv[1]);
        if (num == 1)
            printf("1");
        while (num > 1)
        {
            if (num % i == 0)
            {
                printf("%d", i);
                num /= i;
                if (num > 1)
                    printf("*");
            }
            else
                i++;
        }
    }
    printf("\n");
    return (0);
}
