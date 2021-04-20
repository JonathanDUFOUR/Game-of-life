/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:42:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 17:42:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game_of_life.h"

int	main(int ac, char **av)
{
	int			ret;
	uint32_t	width;
	uint32_t	height;

	initscr();
	if (has_colors() == FALSE)
	{
		gol_ret_msg(COLORS_NOT_SUPPORTED);
		endwin();
	}
	gol_setup();
	if (ac == 3)
	{
		ret = gol_run_game(gol_atou(av[1]), gol_atou(av[2]));
		if (ret != SUCCESS)
			gol_ret_msg(ret);
	}
	else if (ac == 1)
	{
		width = getmaxx(stdscr);
		height = getmaxy(stdscr);
		fprintf(stderr, "term size = {%3d, %3d}\n", width, height);
		ret = gol_run_game(width / 2 - 1, height - 1);
		if (ret != SUCCESS)
			gol_ret_msg(ret);
	}
	else
		gol_ret_msg(AC_ERRNO);
	endwin();
	return (SUCCESS);
}
