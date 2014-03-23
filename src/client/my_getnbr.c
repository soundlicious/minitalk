/*
** my_getnbr.c for my_get_nbr.c in /home/exposi_p/rendu/Piscine-C-Jour_04
**
** Made by exposi_p
** Login   <exposi_p@epitech.net>
**
** Started on  Thu Oct  3 19:05:02 2013 exposi_p
** Last update Tue Dec  3 15:47:38 2013 exposi_p
*/

int	my_getnbrbis(int nbr, int idx, char *str)
{
  int	a;

  a = 0;
  while (str[idx] >= '0' && str[idx] <= '9')
    {
      nbr =  nbr * 10 + (str[idx] - '0');
      idx = idx + 1;
      if (str[idx] < '0' || str[idx] > '9')
	{
	  return (nbr);
	}
    }
  if (nbr <= -2147483648 || nbr > 2147483647)
    {
      return (a);
    }
  else
    {
      return (nbr);
    }
}

int	my_getnbr(char *str)
{
  int	idx;
  int	nbr;
  int	neg;

  idx = 0;
  nbr = 0;
  neg = 1;
  while (str[idx] == '+' || str[idx] == '-')
    {
      if (str[idx] == '-')
        {
          neg  = neg * - 1;
        }
      idx = idx + 1;
    }
  if (str[idx] < '0' || str[idx] > '9')
    {
      return (nbr);
    }
  my_getnbrbis(nbr,idx,str);
  return (my_getnbrbis(nbr, idx, str) * neg);
}
