/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:15:06 by rwallier          #+#    #+#             */
/*   Updated: 2024/05/11 20:13:14 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	validate_colors(char *colors)
{
	int	commas;

	commas = 0;
	if (*colors == ',')
		return (1);
	while (*colors && commas < 3)
	{
		if (*colors == ',')
		{
			commas++;
			colors++;
		}
		if (!ft_isdigit(*colors))
			return (1);
		colors++;
	}
	if (commas != 2)
		return (1);
	return (0);
}
