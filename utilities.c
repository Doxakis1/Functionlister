/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:15:38 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/11/02 11:45:46 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functionlister.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned long	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

int	ft_print_error(const char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str)
		write(STDERR_FILENO, str, i);
	return (i);
}

int	ft_return_error(short error)
{
	if (error == OPEN_FAIL)
		ft_print_error("Error\nFailed to open a file!\n");
	if (error == MALLOC_FAILED)
		ft_print_error("Error\nSuprise, suprise.... Malloc failed!\n");
	if (error == OPEN_DIR_FAIL)
		ft_print_error("Error\nFailed to open a folder!\n");
	return (EXIT_FAILURE);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	source_length;
	size_t	destination_length;

	source_length = ft_strlen(src);
	if (size == 0)
		return (source_length);
	destination_length = ft_strlen(dst);
	if (size <= destination_length)
		return (source_length + size);
	while (size-- > (destination_length + 1) && *src != '\0')
		*(dst++ + destination_length) = *(src++);
	*(dst + destination_length) = '\0';
	return (destination_length + source_length);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_length;

	src_length = ft_strlen(src);
	if (size == 0)
		return (src_length);
	while (--size > 0)
	{
		if (!*src)
			break ;
		*(dst++) = *(src++);
	}
	*dst = '\0';
	return (src_length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	size_t	calculatedsize;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	calculatedsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	final = malloc(calculatedsize);
	if (!final)
		return (NULL);
	ft_strlcpy(final, s1, calculatedsize);
	ft_strlcat(final, s2, calculatedsize);
	return (final);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

int	ft_isalnum(int a)
{
	if ((a >= '0' && a <= '9') || (a >= 'a' && a
			<= 'z') || (a >= 'A' && a <= 'Z'))
		return (1);
	else
		return (0);
}

