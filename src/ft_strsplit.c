/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 22:58:25 by gfielder          #+#    #+#             */
/*   Updated: 2019/05/01 08:07:43 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdlib.h>

char	*my_strdup(const char *str)
{
	char	*r;
	int		len;
	int		i;

	len = 0;
	while (str[len])
		len++;
	r = (char *)malloc((sizeof(char) * (len + 1)));
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		r[i] = str[i];
		i++;
	}
	return (r);
}

char	*my_strdup_to(const char *str, char c)
{
	char	*r;
	int		len;
	int		i;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	r = (char *)malloc((sizeof(char) * (len + 1)));
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		r[i] = str[i];
		i++;
	}
	r[len] = '\0';
	return (r);
}

size_t	my_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*my_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*my_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

int		my_strchr_idx(const char *s, int c)
{
	char	*p;

	if (!s)
		return (-1);
	p = my_strchr(s, c);
	if (!p)
		return (-1);
	return ((int)(p - s));
}

static int	count_words(const char *str, char c, char *groupers)
{
	int		i;
	int		count;
	int		idx;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		idx = my_strchr_idx(groupers, str[i]);
		if (str[i] && idx >= 0 && ((idx & 1) == 0))
		{
			count++;
			while (str[++i] && (str[i] != groupers[idx + 1] || !(i++)))
				;
		}
		else if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static void	strsplit_fill(char **ret, char const *str, char c, char *groupers)
{
	int		i;
	int		j;
	int		idx;

	i = 0;
	j = -1;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		idx = my_strchr_idx(groupers, str[i]);
		if (str[i] && idx >= 0 && ((idx & 1) == 0))
		{
			ret[++j] = my_strdup_to(str + (++i), groupers[idx + 1]);
			i += my_strlen(ret[j]);
			if (str[i] == groupers[idx + 1])
				i++;
		}
		else if (str[i])
		{
			ret[++j] = my_strdup_to(str + i, c);
			i += my_strlen(ret[j]);
		}
	}
}

char		**my_strsplit_grouping(char const *s, char c, char *groupers)
{
	char	**ret;
	int		word_count;

	if (!s || !groupers)
		return (NULL);
	word_count = count_words(s, c, groupers);
	ret = (char **)malloc(sizeof(char *) * (word_count + 1));
	strsplit_fill(ret, s, c, groupers);
	ret[word_count] = NULL;
	return (ret);
}

char		**my_strsplit(char const *s, char c)
{
	return (my_strsplit_grouping(s, c, ""));
}
