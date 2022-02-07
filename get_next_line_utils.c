/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:23:22 by adlecler          #+#    #+#             */
/*   Updated: 2022/02/07 15:35:35 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

/* int	ft_check(char *kurkiputcheck, char c)
{
	int	i;

	i = 0;
	while (kurkiputcheck[i])
	{
		if (kurkiputcheck[i] == c)
		{
			i++;
			return (i);
		}
		i++;
	}
	return (-1);
} */

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/* char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
} */

char	*ft_strjoin(char *str, char *buff, size_t i, size_t j)
{
	char	*new;

	new = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buff)) + 1));
	if (new == NULL)
		return (NULL);
	if (str)
	{
		while (str[i] != '\0')
		{
			new[i] = str[i];
			i++;
		}
	}
	while (buff[j] != '\0')
	{
		new[i] = buff[j];
		i++;
		j++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}
