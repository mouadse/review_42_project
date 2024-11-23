/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <hsennane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:08:58 by hsennane          #+#    #+#             */
/*   Updated: 2024/11/23 22:03:46 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_of_words(const char *s, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

static int	*get_word_len(const char *s, char c)
{
	int	i;
	int	j;
	int	*word_len;
	int	nbr_words;
	int	len;

	i = 0;
	j = 0;
	nbr_words = nbr_of_words(s, c);
	word_len = (int *)malloc(sizeof(int) * nbr_words);
	if (!word_len)
		return (NULL);
	while (s[i] && j < nbr_words)
	{
		len = 0;
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			len++;
			i++;
		}
		word_len[j++] = len;
	}
	return (word_len);
}

static void	free_array(char **t, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(t[i]);
		i++;
	}
	free(t);
}

static char	**allocate_array(const char *s, char c)
{
	int		nbr_words;
	int		*len;
	char	**t;
	int		i;

	i = 0;
	nbr_words = nbr_of_words(s, c);
	len = get_word_len(s, c);
	if (!len)
		return (NULL);
	t = (char **)malloc(sizeof(char *) * (nbr_words + 1));
	if (!t)
		return (free(len), NULL);
	while (i < nbr_words)
	{
		t[i] = (char *)malloc(sizeof(char) * (len[i] + 1));
		if (!t[i])
			return (free_array(t, i), free(len), NULL);
		i++;
	}
	t[nbr_words] = NULL;
	free(len);
	return (t);
}

char	**ft_split(const char *s, char c)
{
	char	**t;
	int		i;
	int		j;
	int		k;
	int		count;

	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	count = nbr_of_words(s, c);
	t = allocate_array(s, c);
	if (!t)
		return (NULL);
	while (s[i] && j < count)
	{
		while (s[i] == c)
			i++;
		k = 0;
		while (s[i] && s[i] != c)
			t[j][k++] = s[i++];
		t[j++][k] = '\0';
	}
	return (t);
}
