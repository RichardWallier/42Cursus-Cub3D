/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:19:44 by rwallier          #+#    #+#             */
/*   Updated: 2024/05/11 20:14:38 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_image *image, int x, int y, uint32_t color)
{
	char	*dst;

	dst = image->addr + (y * image->size_len + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}
