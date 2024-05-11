/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:11:50 by rwallier          #+#    #+#             */
/*   Updated: 2024/05/11 20:14:38 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_file(int fd)
{
	char	*tmp;
	char	*file;
	char	buffer[4097];
	int		readed;

	if (fd == -1)
		return (NULL);
	file = ft_strdup("");
	readed = 4096;
	while (readed == 4096)
	{
		readed = read(fd, buffer, 4096);
		buffer[readed] = '\0';
		tmp = ft_strjoin(file, buffer);
		free(file);
		file = tmp;
	}
	return (file);
}
