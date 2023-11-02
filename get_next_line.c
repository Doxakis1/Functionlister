/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:17:57 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/11/02 10:34:50 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	join(char **dest, char *src, char *src2, int check)
{
	long long	a;
	long long	c;
	long long	b;
	char		*final;

	final = NULL;
	a = ft_strlenmod(src, check);
	c = -1;
	b = ft_strlenmod(src2, 0);
	if (a + b > 0)
	{
		final = (char *)malloc(sizeof(char) * (a + b + 1));
	}
	while (final != NULL && ++c < a + b)
	{
		if (src != NULL && c < a)
			final[c] = src[c];
		else if (src2 != NULL && c < a + b)
			final[c] = src2[c - a];
		final[a + b] = '\0';
	}
	if (dest[0] != NULL)
		free(dest[0]);
	dest[0] = final;
	return (a + b);
}

int	ft_strlenmod(char *string, int instruction)
{
	int	length;

	length = 0;
	if (string == NULL)
		return (length);
	while (string[length] != '\0')
	{
		if (string[length++] == '\n' && instruction == -1)
			break ;
	}
	return (length);
}

int	ft_checklast(char *string)
{
	int	length;

	length = 0;
	if (string == NULL)
		return (length);
	while (string[length] != '\0')
		if (string[length++] == '\n')
			return (1);
	return (0);
}
char	*get_next_line(int fd)
{
	static char	*k[1024] = {0};
	int			a;
	char		*gnl;
	char		*b;
	int			i;

	i = 1;
	gnl = NULL;
	b = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (b && i > 0 && fd >= 0 && BUFFER_SIZE > 0 && read(fd, 0, 0) >= 0)
	{
		i = read(fd, b, BUFFER_SIZE);
		b[i] = '\0';
		a = join(&k[fd], k[fd], b, 0);
		if (ft_checklast(k[fd]) || i == 0)
		{
			a = join(&gnl, k[fd], 0, -1);
			a = join(&k[fd], &k[fd][a], 0, 0);
			break ;
		}
	}
	if (b)
		free(b);
	return (gnl);
}

