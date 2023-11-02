/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:27:31 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/11/02 10:21:01 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functionlister.h"

//NOTE: currently does not handle symlinks!

int	main(int ac, char **av)
{
	char	*pwd;
	char	*temp;
	char	*temp2;
	DIR		*folder;
	struct dirent *entry;

	if (ac < 2)
		pwd = getenv("PWD");
	else
		pwd = av[1];
	folder = opendir(pwd);
    if (folder == NULL) {
        ft_return_error(OPEN_DIR_FAIL);
    }
	temp = (void *)0;
	temp2 = (void *)0;
    while ((entry = readdir(folder)) != NULL)
	{
		if (entry->d_type == DT_DIR && ft_strcmp(entry->d_name, ".") \
			&& ft_strcmp(entry->d_name, ".."))
		{
			temp = ft_strjoin(pwd, "/");
			temp2 = ft_strjoin(temp, entry->d_name);
			main(2, (char **){av[0], temp2, (void *)0});
			free(temp);
			temp = (void *)0;
			free(temp2);
			temp2 = (void *)0;
		}
		else if (entry->d_type != DT_DIR)
		{
			temp = ft_strjoin(pwd, "/");
			temp2 = ft_strjoin(temp, entry->d_name);
			list_functions_of(temp2);
			free(temp);
			temp = (void *)0;
			free(temp2);
			temp2 = (void *)0;
		}
    }
    closedir(folder);
	return (EXIT_SUCCESS);
}