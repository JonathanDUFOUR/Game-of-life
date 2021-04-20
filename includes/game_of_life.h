/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:42:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 12:29:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OF_LIFE_H
# define GAME_OF_LIFE_H

# include <ncurses.h>
# include <stdint.h>
# include <stdbool.h>
# include <sys/types.h>

enum	e_ret
{
	SUCCESS,
	COLORS_NOT_SUPPORTED,
	AC_ERRNO,
	MALLOC_ERRNO
};

enum	e_colors
{
	ALIVE_COLOR = 1,
	DEAD_COLOR,
	ERR_MSG_COLOR
};

void	gol_ret_msg(int ret);
void	gol_setup(void);
void	gol_pause(char *grid, uint32_t size, uint32_t width, MEVENT *event);
void	gol_grid_draw(char *grid, uint32_t size, uint32_t width);
void	gol_grid_update(char *grid, uint32_t size, uint32_t width);
int		gol_run_game(uint32_t width, uint32_t height);
int		gol_atou(char const *s);
int		gol_multi_free(int ret, size_t n, ...);

#endif
