/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:42:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 00:05:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "game_of_life.h"

int	main(int ac, char **av)
{
	initscr();
	if (has_colors() == FALSE)
	{
		gol_ret_msg(COLORS_NOT_SUPPORTED);
		endwin();
	}
	gol_setup();
	if (ac == 2)
		gol_run_game(gol_atoi(av[1]));
	else
		gol_ret_msg(AC_ERRNO);
	endwin();
	return (SUCCESS);
}
