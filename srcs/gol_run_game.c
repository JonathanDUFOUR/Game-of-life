/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_run_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:45:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 20:33:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game_of_life.h"

static int	gol_safety_first(char **grid, uint32_t size, MEVENT **event)
{
	grid[CURR] = calloc(size, sizeof(char));
	if (!grid[CURR])
		return (gol_multifree(MALLOC_ERRNO, 1, grid));
	grid[PREV] = calloc(size, sizeof(char));
	if (!grid[PREV])
		return (gol_multifree(MALLOC_ERRNO, 2, grid[CURR], grid));
	*event = calloc(1, sizeof(MEVENT));
	if (!(*event))
		return (gol_multifree(MALLOC_ERRNO, 3, grid[CURR], grid[PREV], grid));
	return (SUCCESS);
}

int	gol_run_game(uint32_t width, uint32_t height)
{
	char		**grid;
	uint32_t	size;
	MEVENT		*event;
	int			ch;

	grid = calloc(2, sizeof(char *));
	if (!grid)
		return (MALLOC_ERRNO);
	size = width * height;
	if (gol_safety_first(grid, size, &event) != SUCCESS)
		return (MALLOC_ERRNO);
	ch = gol_pause(grid, size, width, event);
	while (ch != 'Q' && ch != 'q')
	{
		gol_grid_draw(grid[CURR], size, width);
		gol_grid_update(grid, size, width);
		napms(SLEEP);
		refresh();
		ch = getch();
		if (ch == ' ')
			ch = gol_pause(grid, size, width, event);
	}
	return (gol_multifree(SUCCESS, 4, grid[CURR], grid[PREV], grid, event));
}
