/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:42:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 20:29:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game_of_life.h"

int	main(int ac, char **av)
{
	int			ret;

	initscr();
	if (has_colors() == FALSE)
		ret = COLORS_NOT_SUPPORTED;
	else
	{
		gol_setup();
		if (ac == 3)
			ret = gol_run_game(gol_min(gol_atou(av[1]), 47), gol_atou(av[2]));
		else if (ac == 1)
			ret = gol_run_game(gol_min(getmaxx(stdscr) / 2, 47),
					getmaxy(stdscr) - 1);
		else
			ret = AC_ERRNO;
	}
	if (ret != SUCCESS)
		gol_ret_msg(ret);
	endwin();
	return (SUCCESS);
}
