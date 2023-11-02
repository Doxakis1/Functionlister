/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_of.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:21:15 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/11/02 10:47:15 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functionlister.h"

int	tokenise(const char *str)
{
	char	types[200][100];
	char	variables[30][100];
	char	functions_names[200][100];
	char	*line;

	ft_bzero(&types, sizeof(char *) * 200 + sizeof(char) * 100);
	ft_bzero(&variables, sizeof(char *) * 30 + sizeof(char) * 100);
	ft_bzero(&functions_names, sizeof(char *) * 200 + sizeof(char) * 100);

	
}

int	list_functions_of(const char *str)
{
	int		size;
	int		file_fd;
	char	*line;

	size = ft_strlen(str);
	if (size  <= 2 || str[size - 1] != 'c' || str[size - 2] != '.')
		return (EXIT_SUCCESS);
	file_fd = open(str, O_RDONLY);
	if (file_fd == -1)
		return (ft_return_error(OPEN_FAIL));
	write(STDIN_FILENO, "Within file: ", 13);
	write(STDIN_FILENO, str, size);
	write(STDIN_FILENO, "\n", 1);
	tokenise()
}