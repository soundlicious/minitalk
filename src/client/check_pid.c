/*
** check_pid.c for minitalk in /home/exposi_p/rendu/PSU_2013_minitalk
**
** Made by exposi_p
** Login   <exposi_p@epitech.net>
**
** Started on  Mon Mar 17 18:15:50 2014 exposi_p
** Last update Mon Mar 17 18:19:05 2014 exposi_p
*/

int	check_pid(char *pid)
{
  int	i;

  i = 0;
  while (pid[i])
    {
      if (pid[i] < '0' || pid[i] > '9')
	{
	  write(2, "Error : Invalid PID\n", 20);
	  return (-1);
	}
      i++;
    }
  return (0);
}
