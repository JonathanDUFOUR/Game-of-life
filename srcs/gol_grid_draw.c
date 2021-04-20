/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_grid_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:09:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 17:32:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

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
}
