/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 10:52:12 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/26 15:45:36 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define ROW 5
#define COL 8

void	ft_recursive(char **tab, t_point size, t_point begin, char c)
{
	t_point temp = begin;

	if (begin.y > 0 && tab[begin.y - 1][begin.x]) // Up
		if (tab[begin.y - 1][begin.x] == c)
		{	
			temp.y--;
			tab[temp.y][temp.x] = 'F';
			ft_recursive(tab, size, temp, c);
		}
	temp = begin;
	if (begin.y < size.y - 1 && tab[begin.y + 1 ][begin.x]) // Down
        if (tab[begin.y + 1][begin.x] == c)
        {	
			temp.y++;
			tab[temp.y][begin.x] = 'F';
            ft_recursive(tab, size, temp, c);
        }
	temp = begin;
	if (begin.x > 0 && tab[begin.y][begin.x - 1]) // Left
        if (tab[begin.y][begin.x - 1] == c)
        {   
			temp.x--;
			tab[begin.y][temp.x] = 'F';
            ft_recursive(tab, size, temp, c);
        }
	temp = begin;
	if (begin.x < size.x - 1 && tab[begin.y][begin.x + 1]) // Right
        if (tab[begin.y][begin.x + 1] == c)
        { 
			temp.x++;
			tab[begin.y][temp.x] = 'F';
            ft_recursive(tab, size, temp, c);
        }
}

void    flood_fill(char **tab, t_point size, t_point begin)
{
    int i;
    int j;
    char c;

    i = --begin.y;
    j = --begin.x;
	c = tab[i][j];
	tab[i][j] = 'F';
	printf("x: %d y: %d\n", begin.y, begin.x);
	ft_recursive(tab, size, begin, c);
}

char    **make_area(char *zone[])
{
    int i;
    int j;
    char **area;

    i = 0;
    area = (char**)malloc(sizeof(char*) * ROW);
    while (i < COL)
        area[i++] = (char*)malloc(sizeof(char) * COL);
    i = 0;
    while (i < ROW)
    {
        j = 0;
        while (j < COL)
        {
            area[i][j] = zone[i][j];
            j++;
        }
        i++;
    }
    return (area);
}

void print_tab(char **area)
{
    int i;
    int j;

    i = 0;
    while (i < ROW)
    {
        j = 0;
        while (j < COL)
        {
            printf("%c ", area[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int    main(void)
{
    char **area;
    t_point size = { COL, ROW }; //{cols, rows}
    t_point begin = { 3, 3 }; //{col. row}
    char *zone[] = {
        "11111111",
        "10001001",
        "10010001",
        "10100101",
        "11100001"
    };

    area = make_area(zone);
    print_tab(area);
	write(1, "yes\n",4);
    flood_fill(area, size, begin);
	write(1, "no\n", 3);
    printf("\n");;
    print_tab(area);
    return (0);
}
