/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_run_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:45:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 12:28:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game_of_life.h"

int	gol_run_game(uint32_t width, uint32_t height)
{
	int			run;
	char		*grid;
	uint32_t	size;
	MEVENT		*event;

	size = width * height;
	grid = calloc(size, sizeof(char));
	if (!grid)
		return (MALLOC_ERRNO);
	event = calloc(1, sizeof(MEVENT));
	if (!event)
		return (gol_multi_free(MALLOC_ERRNO, 1, grid));
	gol_pause(grid, size, width, event);
	run = 1;
	while (run)
	{
		gol_grid_draw(grid, size, width);
		gol_grid_update(grid, size, width);
		refresh();
	}
	return (gol_multi_free(SUCCESS, 2, grid, event));
}
