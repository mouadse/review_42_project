/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:50:00 by hsennane          #+#    #+#             */
/*   Updated: 2024/11/19 13:00:26 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char *ft_strjoin(char const *s1, char const *s2) {
  size_t s1_len;
  size_t s2_len;
  char *p;
  size_t index[2];

  if (!s1 || !s2) {
    return (NULL);
  }
  s1_len = ft_strlen(s1);
  s2_len = ft_strlen(s2); // Fixed: Use s2 instead of s1
  p = malloc(sizeof(char) * (s1_len + s2_len + 1));
  if (!p) {
    return (NULL);
  }
  // Initialize indices
  index[0] = 0; // Index for s1 and p
  index[1] = 0; // Index for s2
  // Copy s1 into p
  while (index[0] < s1_len) {
    p[index[0]] = s1[index[0]];
    index[0]++;
  }
  // Copy s2 into p
  while (index[1] < s2_len) {
    p[index[0]] = s2[index[1]];
    index[0]++;
    index[1]++;
  }
  p[index[0]] = '\0'; // Fixed: Null terminator at the end of p
  return (p);
}
