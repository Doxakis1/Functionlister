/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionlister.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:27:52 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/11/02 10:45:06 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONLISTER_H
# define FUNCTIONLISTER_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#include <dirent.h>

# define OPEN_FAIL 1
# define MALLOC_FAILED 2
# define OPEN_DIR_FAIL 3


int		ft_print_error(const char *str);
int		ft_return_error(short error);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strlenmod(char *string, int instruction);
int		join(char **dest, char *src, char *src2, int check);
int		ft_checklast(char *string);
char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);

#endif