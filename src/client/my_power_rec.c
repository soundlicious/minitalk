/*
** my_power_rec.c for my_power_rec in /home/exposi_p/rendu/Piscine-C-Jour_05
** 
** Made by exposi_p
** Login   <exposi_p@epitech.net>
** 
** Started on  Fri Oct  4 17:08:33 2013 exposi_p
** Last update Mon Oct  7 19:19:40 2013 exposi_p
*/

int	my_power_rec(int nb, int power)
{
  if (power == 0 || nb == 0)
    return (1);
  if (power < 0)
    return (0);
  else
    return (nb * my_power_rec(nb, power -1));
}
