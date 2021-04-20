/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_grid_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:26:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 14:19:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

static uint32_t	gol_count_ngb(char *g, uint32_t size, uint32_t w, uint32_t i)
{
	uint32_t	x;
	uint32_t	y;

	x = i % w;
	y = i / w;
	if (!x && !y)
		return (g[i + 1] + g[i + w] + g[i + 1 + w]);
	else if (!x && y == (size / w - 1))
		return (g[i + 1] + g[i - w] + g[i + 1 - w]);
	else if (x == (w - 1) && !y)
		return (g[i - 1] + g[i + w] + g[i - 1 + w]);
	else if (x == (w - 1) && y == (w / size - 1))
		return (g[i - 1] + g[i - w] + g[i - 1 - w]);
	else if (!x)
		return (g[i + 1] + g[i + w] + g[i - w] + g[i + 1 + w] + g[i + 1 - w]);
	else if (x == (w - 1))
		return (g[i - 1] + g[i + w] + g[i - w] + g[i - 1 + w] + g[i - 1 - w]);
	else if (!y)
		return (g[i + 1] + g[i - 1] + g[i + w] + g[i + 1 + w] + g[i - 1 + w]);
	else if (y == (size / w - 1))
		return (g[i + 1] + g[i - 1] + g[i - w] + g[i + 1 - w] + g[i - 1 - w]);
	else
		return (g[i + 1] + g[i - 1] + g[i + w] + g[i - w] + g[i + 1 + w]
			+ g[i + 1 - w] + g[i - 1 + w] + g[i - 1 - w]);
}

void	gol_grid_update(char **grid, uint32_t size, uint32_t width)
{
	uint32_t	i;

	i = 0;
	while (i < size)
	{
		if (!grid[PREV][i] && gol_count_ngb(grid[PREV], size, width, i) == 3)
			grid[CURR][i] = 1;
		else if (grid[PREV][i]
			&& (gol_count_ngb(grid[PREV], size, width, i) < 2
				|| gol_count_ngb(grid[PREV], size, width, i) > 3))
			grid[CURR][i] = 0;
		++i;
	}
	i = 0;
	while (i < size)
	{
		grid[PREV][i] = grid[CURR][i];
		++i;
	}
}
