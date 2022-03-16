/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:38:08 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/16 19:50:30 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 1

char		*ft_strjoin_gnl(char *s1, char *s2);
char		*get_next_line(int fd);
char		*get_str(int fd, char *line);
char		*get_line(char *str);
char		*get_remain(char *str);
int			check_endl(char *str);

#endif
