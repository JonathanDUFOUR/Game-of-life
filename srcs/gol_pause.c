/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_pause.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:15:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 17:52:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

static void	gol_get_input(char **grid, uint32_t size, uint32_t width,
	MEVENT *event)
{
	uint32_t	x;
	uint32_t	y;

	x = event->x / 2;
	y = event->y;
	fprintf(stderr, "  real coords = {%d, %d}\n", event->x, event->y);
	fprintf(stderr, "mapped coords = {%d, %d}\n", x, y);
	if (x < width && y < (size / width))
	{
		grid[CURR][x + y * width] ^= 1;
		grid[PREV][x + y * width] ^= 1;
	}
}

int	gol_pause(char **grid, uint32_t size, uint32_t width, MEVENT *event)
{
	int			ch;

	while (1)
	{
		ch = getch();
		if (grid && event && (ch == KEY_MOUSE) && (getmouse(event) == OK))
			gol_get_input(grid, size, width, event);
		else if (ch == ' ' || ch == 'Q' || ch == 'q')
			break ;
		if (grid)
			gol_grid_draw(grid[CURR], size, width);
		refresh();
	}
	return (ch);
}
