/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionlister.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:27:52 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/11/04 13:50:47 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONLISTER_H
# define FUNCTIONLISTER_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>

# define OPEN_FAIL 1
# define MALLOC_FAILED 2
# define OPEN_DIR_FAIL 3
# define MAX_FUNCS 200
# define MAX_FUNC_NAME_SIZE 128


int			ft_print_error(const char *str);
int			ft_return_error(short error);
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_isalnum(int a);
int			list_functions_of(const char *str);
int			print_functions(const int file_fd);
int			print_func(const char *str);
int			get_previous_word(char *str);
int			isnot_c_keyword(const char *keyword);

#endif