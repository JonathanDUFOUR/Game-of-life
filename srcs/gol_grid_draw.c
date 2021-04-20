/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_grid_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:09:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 12:28:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "game_of_life.h"

void	gol_grid_draw(char *grid, uint32_t size, uint32_t width)
{
	uint32_t	i;

	move(0, 0);
	i = 0;
	while (i++ < size)
	{
		if (*grid++)
			attron(COLOR_PAIR(ALIVE_COLOR));
		else
			attron(COLOR_PAIR(DEAD_COLOR));
		printw("  ");
		attroff(COLOR_PAIR(DEAD_COLOR));
		attroff(COLOR_PAIR(ALIVE_COLOR));
		if (!(i % width))
			printw("\n");
	}
}
