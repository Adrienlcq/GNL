/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:22:58 by adlecler          #+#    #+#             */
/*   Updated: 2022/02/08 15:29:15 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//void destructor() __attribute__((destructor));

char	*ft_addbuff(int fd, char *str)
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;

	ret = 1;
	while (1)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buff[ret] = '\0';
		str = ft_strjoin(str, buff, 0, 0);
		if (ft_strchr(str, '\n') == 1 || ret == 0)
			break ;
	}
	return (str);
}

char	*ft_addstr(char *str, int i)
{
	int		j;
	char	*line;

	j = 0;
	line = NULL;
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_realloc(char *str, int i, int j, int tmp)
{
	char	*new_str;

	if (str[0] == '\0')
		return (ft_free(&str));
	j = ft_strlen(str);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	tmp = i;
	i = j - i;
	new_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_str)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		new_str[j] = str[tmp + j];
		j++;
	}
	//new_str[j] = '\0';
	ft_free(&str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str = NULL;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_addbuff(fd, str);
	if (!str)
		return (NULL);
	line = ft_addstr(str, 0);
	if (line == NULL)
		return (ft_free(&str));
	str = ft_realloc(str, 0, 0, 0);
	if (str == NULL)
		return (ft_free(&line));
	return (line);
}

/* int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [0%d] : %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [0%d] : %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [0%d] : %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */

/* void	destructor()
{
	system("leaks a.out");
} */