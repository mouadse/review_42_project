/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:27:05 by hsennane          #+#    #+#             */
/*   Updated: 2024/11/18 22:33:41 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s1) {
  size_t len;
  size_t i;
  char *res;

  // if (s1 == NULL)
  //   return (NULL);
  i = 0;
  len = ft_strlen(s1);
  res = (char *)malloc(len + 1);
  if (!res) {
    return (NULL);
  }
  while (i < len) {
    res[i] = s1[i];
    i++;
  }
  res[i] = '\0';
  return (res);
}
