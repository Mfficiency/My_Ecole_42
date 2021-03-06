/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm <mm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:09:03 by mm          #+#    #+#             */
/*   Updated: 2021/11/05 11:32:01 by mm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// return the index of a substring in a string and free if necessary
char	*ft_substr(char *s, unsigned int start, size_t len, int f)
{
	char	*newstr;
	size_t	max_len;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (len > s_len + 1)
		max_len = s_len + 1;
	else
		max_len = len;
	newstr = (char *)malloc(sizeof(char) * (max_len + 1));
	if (!newstr)
		return (NULL);
	while (start < s_len && i < max_len)
		newstr[i++] = s[start++];
	newstr[i] = '\0';
	if (f == 1)
		free(s);
	return (newstr);
}

// return the length of a string
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

// return the difference between two strings
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

// duplicate a string and free
char	*ft_strdup(char *s, int f)
{
	char	*ret;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	if (f == 1)
		free(s);
	return (ret);
}

// join two strings
char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new_str;
	int		len;
	int		i;
	int		j;

	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	new_str = (char *)malloc(len * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}
