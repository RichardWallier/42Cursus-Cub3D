/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:30:57 by rwallier          #+#    #+#             */
/*   Updated: 2024/05/11 20:14:38 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_line(const char *line)
{
	while (*line && ft_strchr(" 01NSWE", *line))
		line++;
	if (*line == '\0' || *line == '\n')
		return (true);
	return (false);
}
