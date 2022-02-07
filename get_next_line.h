/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:23:10 by adlecler          #+#    #+#             */
/*   Updated: 2022/02/07 15:41:37 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
//# include <stdio.h>
//# include <fcntl.h>

//# define MAX_FD 1024
//# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_addbuff(int fd, char *str);
int		ft_strchr(char *s, int c);
//char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *str, char *buff, size_t i, size_t j);
size_t	ft_strlen(char *s);
char	*ft_addstr(char *str);
char	*ft_realloc(char *str, int i, int j, int adrien);

#endif
