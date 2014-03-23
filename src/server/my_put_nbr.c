/*
** my_put_nbr.c for minitalk in /home/exposi_p/rendu/PSU_2013_minitalk
**
** Made by exposi_p
** Login   <exposi_p@epitech.net>
**
** Started on  Sat Mar 22 15:45:17 2014 exposi_p
** Last update Sat Mar 22 15:45:36 2014 exposi_p
*/

#include "../../inc/server/server.h"

int	my_put_nbr(int nb)
{
  int	div;

  div = -1;
  if (nb < 0)
    my_putchar('-');
  else
    nb = -nb;
  while ((nb / -div) <= -10)
    div = div * 10;
  while (div < 0)
    {
      my_putchar((nb / div) + '0');
      nb = nb % div;
      div = div / 10;
    }
}
