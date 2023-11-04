/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_of.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:21:15 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/11/04 16:22:35 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functionlister.h"

int	isnot_c_keyword(const char *keyword)
{
	int					i;
    static const char	*c_keywords[] = {
        "if", "while", "for", "switch", "do", "return", "goto", "sizeof", \
		"break","\0"
    };

	i = 0;
    while (i < 10) {
        if (ft_strcmp(keyword, c_keywords[i++]) == 0)
			return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int	get_previous_word(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (--size <= 0)
		return (-1);
	if (str[size] == ' ' || str[size] == '\t' || str[size] == '\n')
	{
		while (size >= 0 && (str[size] == ' ' || str[size] == '\t' \
			|| str[size] == '\n'))
			size--;
		if (size == 0)
			return (0);
		else
			str[size + 1] = '\0';
	}
	if (!ft_isalnum(str[size]))
		return (-1);
	while (size >= 0)
	{
		if (!ft_isalnum(str[size]) && str[size] != '_')
			return (size + 1);
		size--;
	}
	return (size);
}

int	print_func(const char *str)
{
	write(STDOUT_FILENO, "\t", 1);
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, "()\n", 3);
	return (EXIT_SUCCESS);
}

int	add_to_function_list(char functions[][MAX_FUNC_NAME_SIZE], char *new_function)
{
	int fun_counter;
	int	index_counter;

	fun_counter = -1;
	index_counter = 0;
	while(++fun_counter < MAX_FUNCS && functions[fun_counter][0] != '\0')
		if (ft_strcmp(new_function, functions[fun_counter]) == 0)
			return (EXIT_FAILURE);
	if (fun_counter >= 200)
		return (EXIT_FAILURE);
	while(index_counter <= MAX_FUNC_NAME_SIZE - 2 && new_function[index_counter])
	{
		functions[fun_counter][index_counter] = new_function[index_counter];
		index_counter++;
	}
	return (EXIT_SUCCESS);
}

int	print_functions(const int file_fd)
{
	char	buffer[BUFFER_SIZE];
	char	functions[MAX_FUNCS][MAX_FUNC_NAME_SIZE];
	int		index;
	int		read_bytes;
	int		word_index;

	index = 0;
	word_index = 0;
	ft_bzero(&functions, sizeof(char *) * MAX_FUNCS + sizeof(char) * MAX_FUNC_NAME_SIZE);
	read_bytes = read(file_fd, &buffer[index], 1);
	while (read_bytes > 0 && index < BUFFER_SIZE)
	{
		if (buffer[index] == '(')
		{
			buffer[index] = '\0';
			word_index = get_previous_word(buffer);
			if (word_index != -1 && isnot_c_keyword(&buffer[word_index]) )
				add_to_function_list(functions, &buffer[word_index]);
			index = -1;
		}
		++index;
		if (index < 1024)
			read_bytes = read(file_fd, &buffer[index], 1);	
	}
	word_index = -1;
	while (++word_index < 200 && functions[word_index][0] != '\0')
		print_func(functions[word_index]);
	return (EXIT_SUCCESS);
}

int	list_functions_of(const char *str)
{
	int		size;
	int		file_fd;

	size = ft_strlen(str);
	if (size  <= 2 || str[size - 1] != 'c' || str[size - 2] != '.')
		return (EXIT_SUCCESS);
	file_fd = open(str, O_RDONLY);
	if (file_fd == -1)
		return (ft_return_error(OPEN_FAIL));
	write(STDOUT_FILENO, "Within file: ", 13);
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, "\n", 1);
	print_functions(file_fd);
	write(STDOUT_FILENO, "\n", 1);
	close(file_fd);
	return (EXIT_SUCCESS);
}