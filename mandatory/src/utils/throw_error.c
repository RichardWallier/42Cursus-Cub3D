/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:12:47 by mpinna-l          #+#    #+#             */
/*   Updated: 2024/05/11 20:12:26 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	throw_error(char *error_str)
{
	ft_putstr_fd("Error\ncub3d: ", STDERR_FILENO);
	ft_putstr_fd(error_str, STDERR_FILENO);
	return (1);
}
