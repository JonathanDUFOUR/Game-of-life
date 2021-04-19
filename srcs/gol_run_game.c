/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_run_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:45:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 00:02:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdbool.h>
#include "game_of_life.h"

void	gol_run_game(int dim)
{
	bool	run;

	gol_pause();
	run = true;
	while (run)
	{
		printw("A");
		refresh();
	}
}
