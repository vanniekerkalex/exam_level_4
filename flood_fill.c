/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:44:11 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/10 13:01:04 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void actual_flood_fill(char **tab, char colour, t_point size, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (x >= size.x || y >= size.y)
		return ;
	if (tab[y][x] != colour)
		return ;
	tab[y][x] = 'F';
	actual_flood_fill(tab, colour, size, x + 1, y);
	actual_flood_fill(tab, colour, size, x - 1, y);
	actual_flood_fill(tab, colour, size, x, y + 1);
	actual_flood_fill(tab, colour, size, x, y - 1);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
	actual_flood_fill(tab, tab[begin.y][begin.x], size, begin.x, begin.y);
}
