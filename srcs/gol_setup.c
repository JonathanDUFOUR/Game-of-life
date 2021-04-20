/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:17:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 12:09:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

void	gol_setup(void)
{
	start_color();
	init_pair(ALIVE_COLOR, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(DEAD_COLOR, COLOR_BLACK, COLOR_BLACK);
	init_pair(ERR_MSG_COLOR, COLOR_RED, COLOR_BLACK);
	mousemask(BUTTON1_PRESSED, NULL);
	scrollok(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();
}
