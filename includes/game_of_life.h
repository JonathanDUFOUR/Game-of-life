/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:42:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 00:04:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OF_LIFE_H
# define GAME_OF_LIFE_H

enum	e_ret
{
	SUCCESS,
	COLORS_NOT_SUPPORTED,
	AC_ERRNO
};

enum	e_colors
{
	ALIVE_COLOR = 1,
	DEAD_COLOR,
	ERR_MSG_COLOR
};

void	gol_ret_msg(int ret);
void	gol_setup(void);
void	gol_pause(void);
void	gol_run_game(int dim);
int		gol_atoi(char const *s);

#endif
