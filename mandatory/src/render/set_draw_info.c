/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_draw_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:43:25 by rwallier          #+#    #+#             */
/*   Updated: 2024/05/11 20:14:38 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_wall_position(t_ray *ray, t_draw_info *info)
{
	info->line_height = (int)(WINDOW_HEIGHT / ray->distance);
	if (info->line_height >= WINDOW_HEIGHT)
	{
		info->wall_start = 0;
		info->wall_end = WINDOW_HEIGHT;
	}
	else
	{
		info->wall_start = (WINDOW_HEIGHT / 2) - (info->line_height / 2);
		info->wall_end = info->wall_start + info->line_height;
	}
}

static void	get_texture(t_data *data, t_ray *ray, t_draw_info *info)
{
	if (ray->hit_direction == 'N')
		info->texture = &data->scene.no_texture;
	else if (ray->hit_direction == 'E')
		info->texture = &data->scene.ea_texture;
	else if (ray->hit_direction == 'W')
		info->texture = &data->scene.we_texture;
	else
		info->texture = &data->scene.so_texture;
}

static void	set_texture_position(t_data *data,
		t_player *player, t_ray *ray, t_draw_info *info)
{
	if (ray->hit_direction == 'N' || ray->hit_direction == 'S')
		info->wall_x = player->pos_x + ray->distance * ray->dir_x;
	else
		info->wall_x = player->pos_y + ray->distance * ray->dir_y;
	info->wall_x -= (int)info->wall_x;
	get_texture(data, ray, info);
	info->texture_x = (int)(info->wall_x * (double)info->texture->width);
	if (ray->hit_direction == 'S')
		info->texture_x = info->texture->width - info->texture_x - 1;
	if (ray->hit_direction == 'W')
		info->texture_x = info->texture->width - info->texture_x - 1;
	info->step = 1.0 * info->texture->height / info->line_height;
	info->texture_pos = (info->wall_start - WINDOW_HEIGHT / 2
			+ info->line_height / 2) * info->step;
}

void	set_draw_info(t_data *data, t_player *player,
							t_ray *ray, t_draw_info *info)
{
	set_wall_position(ray, info);
	set_texture_position(data, player, ray, info);
}
