/*
** check_arg.c for minitalk in /home/exposi_p/rendu/PSU_2013_minitalk
**
** Made by exposi_p
** Login   <exposi_p@epitech.net>
**
** Started on  Mon Mar 17 18:06:32 2014 exposi_p
** Last update Mon Mar 17 18:35:41 2014 exposi_p
*/

int	check_arg(int ac, char **av)
{
  if (ac != 3)
    {
      write(2, "Error : The Server PID and a message are needed\n", 48);
      return (-1);
    }
  if (!av[1] || !av[2])
    {
      write(2, "Error : Empty Arguments\n", 24);
      return (-1);
    }
  return (0);
}
