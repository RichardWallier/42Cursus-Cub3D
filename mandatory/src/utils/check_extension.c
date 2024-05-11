/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:05 by rwallier          #+#    #+#             */
/*   Updated: 2024/05/11 20:13:14 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_extension(const char *file, const char *extension)
{
	size_t	extension_len;
	int		file_len;

	extension_len = ft_strlen(extension);
	file_len = ft_strlen(file) - extension_len;
	if (file_len < 0)
		return (1);
	if (ft_strncmp(file + file_len, extension, extension_len))
		return (1);
	return (0);
}
