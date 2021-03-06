/*
** my_getnbrbase.c for rtv1 in /home/exposi_p/rendu/MUL_2014_rtv1
**
** Made by exposi_p
** Login   <exposi_p@epitech.net>
**
** Started on  Sat Mar 15 14:01:07 2014 exposi_p
** Last update Sat Mar 22 10:05:16 2014 exposi_p
*/

#include "../../inc/client/client.h"
static int	my_pow(int base_len, int place)
{
  int	ret;

  ret = 1;
  while (place > 0)
    {
      ret = ret * base_len;
      place--;
    }
  return (ret);
}

static int	find_base(char str, char *base)
{
  int	i;

  i = 0;
  while (base[i])
    {
      if (str == base[i])
	return (i);
      i++;
    }
  return (0);
}

int	my_getnbrbase(char *str, char *base)
{
  int	i;
  int	neg;
  int	base_len;
  int	str_len;
  int	ret;

  i = 0;
  neg = 1;
  base_len = my_strlen(base);
  while (str[i] == '-')
    {
      if (str[i] == '-')
	neg = -1;
      i++;
    }
  str_len = my_strlen(str + i) - 1;
  while (str[i])
    {
      ret = ret + find_base(str[i], base) * my_pow(base_len, str_len);
      str_len--;
      i++;
    }
  return (ret * neg);
}
