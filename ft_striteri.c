/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <hsennane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:59:56 by hsennane          #+#    #+#             */
/*   Updated: 2024/11/19 14:56:07 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_striteri(char *s, void (*f)(unsigned int, char *)) {
  unsigned int i;

  if (!s || !f) {
    return;
  }
  i = 0;
  while (s[i]) {
    f(i, &s[i]);
    i++;
  }
}
