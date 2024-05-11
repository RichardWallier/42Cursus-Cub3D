/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:28:59 by rwallier          #+#    #+#             */
/*   Updated: 2024/05/11 20:13:14 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	end;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	end = 0;
	if (len > ft_strlen(s))
		substr = (char *)malloc(ft_strlen(s) + 1);
	else
		substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && end < len)
		{
			substr[end] = s[i];
			end++;
		}
		i++;
	}
	substr[end] = '\0';
	return (substr);
}
