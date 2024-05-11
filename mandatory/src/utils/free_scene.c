/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:48:42 by rwallier          #+#    #+#             */
/*   Updated: 2024/05/11 20:13:14 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_scene(t_scene *scene)
{
	free_matrix(scene->map_grid);
	free(scene->no_texture.text);
	free(scene->no_texture.addr);
	free(scene->so_texture.text);
	free(scene->so_texture.addr);
	free(scene->we_texture.text);
	free(scene->we_texture.addr);
	free(scene->ea_texture.text);
	free(scene->ea_texture.addr);
}
