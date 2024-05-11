/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_released.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:17:38 by rwallier          #+#    #+#             */
/*   Updated: 2024/05/11 20:14:38 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_released(int keycode, t_data *data)
{
	t_player	*player;

	player = &data->player;
	if (keycode == W)
		player->walk_direction--;
	else if (keycode == A)
		player->turn_direction++;
	else if (keycode == S)
		player->walk_direction++;
	else if (keycode == D)
		player->turn_direction--;
	return (0);
}
