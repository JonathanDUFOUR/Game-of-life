/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_ret_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:53:32 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 00:04:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "game_of_life.h"

void	gol_ret_msg(int ret)
{
	if (ret == COLORS_NOT_SUPPORTED)
		printw("Error: Colors are not supported on you terminal\n");
	else
	{
		attron(COLOR_PAIR(ERR_MSG_COLOR));
		if (ret == AC_ERRNO)
			printw("Error: argument count is invalid\n");
		attroff(COLOR_PAIR(ERR_MSG_COLOR));
	}
	gol_pause();
}
