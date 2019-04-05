/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 22:14:40 by kaboujna          #+#    #+#             */
/*   Updated: 2019/03/29 22:15:21 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char const	*ft_strndup(char const *str, size_t size)
{
	char *new_str;

	new_str = (char*)malloc(sizeof(*new_str) * size);
	if (!new_str)
		return (NULL);
	return (ft_strncpy(new_str, str, size));
}
