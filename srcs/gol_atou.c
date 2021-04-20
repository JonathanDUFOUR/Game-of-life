/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol_atou.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:51:11 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/20 12:25:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>

static bool	gol_isspace(char const c)
{
	return (c == '\f'
		|| c == '\t'
		|| c == '\n'
		|| c == '\r'
		|| c == '\v'
		|| c == ' ');
}

static bool	gol_isdigit(char const c)
{
	return (c >= '0' && c <= '9');
}

int	gol_atou(char const *s)
{
	uint32_t	output;

	output = 0;
	while (gol_isspace(*s))
		++s;
	if (*s == '+')
		++s;
	while (gol_isdigit(*s))
	{
		output *= 10;
		output += *s - '0';
		++s;
	}
	return (output);
}
