/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_multifree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:30:00 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 14:12:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "game_of_life.h"

int	gol_multifree(int ret, size_t n, ...)
{
	void	*dent;
	va_list	va;

	va_start(va, n);
	while (n--)
	{
		dent = va_arg(va, void *);
		free(dent);
	}
	va_end(va);
	return (ret);
}
