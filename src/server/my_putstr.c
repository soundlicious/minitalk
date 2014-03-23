/*
** my_putstr.c for my_putstr in /home/exposi_p/rendu/Piscine-C-Jour_04
** 
** Made by exposi_p
** Login   <exposi_p@epitech.net>
** 
** Started on  Thu Oct  3 11:23:27 2013 exposi_p
** Last update Fri Oct  4 23:06:32 2013 exposi_p
*/

int	my_putstr(char *str)
{
  int	a;

  a = 0;
  while (str[a] != 0)
    {
      my_putchar(str[a]);
      a = a +1;
    }
}
