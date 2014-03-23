/*
** my_strlen.c for my_strlen in /home/exposi_p/rendu/Piscine-C-Jour_04
** 
** Made by exposi_p
** Login   <exposi_p@epitech.net>
** 
** Started on  Thu Oct  3 11:42:13 2013 exposi_p
** Last update Thu Oct 10 22:50:59 2013 exposi_p
*/

int	my_strlen(char *str)
{
  int	a;

  a = 0;
  while (str[a] != 0)
    a = a + 1;
  return (a);
}
