/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_pause.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:15:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 12:32:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

void	gol_pause(char *grid, uint32_t size, uint32_t width, MEVENT *event)
{
	int	ch;
	int	x;
	int	y;

	while (1)
	{
		ch = getch();
		if (grid && event && ch == KEY_MOUSE)
		{
			if (getmouse(event) == OK)
			{
				x = event->x / 2;
				y = event->y;
				if (x < width && y < (size / width))
					grid[x + y * width] ^= 1;
			}
		}
		else if (ch == ' ')
			break ;
		gol_grid_draw(grid, size, width);
		refresh();
	}
}
