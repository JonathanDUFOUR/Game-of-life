/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_grid_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:09:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 20:46:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

static void	gol_borders_draw(uint32_t size, uint32_t width)
{
	uint32_t	height;
	uint32_t	i;

	height = size / width;
	i = 0;
	while (i < height)
	{
		attron(COLOR_PAIR(BORDER_COLOR));
		mvprintw(i, width * 2, "XX");
		attroff(COLOR_PAIR(BORDER_COLOR));
		++i;
	}
	i = 0;
	while (i < (width + 1))
	{
		attron(COLOR_PAIR(BORDER_COLOR));
		mvprintw(height, i * 2, "XX");
		attroff(COLOR_PAIR(BORDER_COLOR));
		++i;
	}
}

void	gol_grid_draw(char *grid, uint32_t size, uint32_t width)
{
	uint32_t	i;

	i = 0;
	while (i < size)
	{
		if (grid[i])
			attron(COLOR_PAIR(ALIVE_COLOR));
		else
			attron(COLOR_PAIR(DEAD_COLOR));
		mvprintw(i / width, (i % width) * 2, "XX");
		attroff(COLOR_PAIR(DEAD_COLOR));
		attroff(COLOR_PAIR(ALIVE_COLOR));
		++i;
	}
	gol_borders_draw(size, width);
}
