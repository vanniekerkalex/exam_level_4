/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 18:21:29 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/11 18:50:04 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void sort_int_tab(int *tab, unsigned int size)
{
    int i = 0;
    int j = 0;
    int temp = 0;

    while (i < (int)size - 1)
    {
        j = 0;
        while (j < (int)size - 1)
        {
            if (tab[j] > tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

int main (void)
{
    int tab[] = {2444,12,3,15,19,233,5,5,67,1,0};
    int size = 11;
    int i = 0;
    sort_int_tab(tab, (unsigned int)size);
    while (i < size)
        printf("%d, ", tab[i++]);
    return (0);
}
