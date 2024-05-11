/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:01 by rwallier          #+#    #+#             */
/*   Updated: 2024/05/11 20:13:14 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	hooks_init(t_data *data)
{
	mlx_do_key_autorepeatoff(data->mlx_ptr);
	mlx_hook(data->win, 2, 1L << 0, key_pressed, data);
	mlx_hook(data->win, 3, 1L << 1, key_released, data);
	mlx_loop_hook(data->mlx_ptr, hook, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (throw_error("Usage: ./cub3d <scene_file>\n"));
	if (check_extension(argv[1], ".cub"))
		return (throw_error("Invalid file extension\n"));
	if (data_init(&data, argv[1]))
		return (1);
	hooks_init(&data);
	return (0);
}
