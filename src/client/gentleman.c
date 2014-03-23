/*
** gentleman.c for minitalk in /home/exposi_p/rendu/PSU_2013_minitalk
**
** Made by exposi_p
** Login   <exposi_p@epitech.net>
**
** Started on  Mon Mar 17 18:21:22 2014 exposi_p
** Last update Wed Mar 19 12:33:20 2014 exposi_p
*/

#include <signal.h>
#include "../../inc/client/client.h"

int	gentleman(int s_pid)
{
  int	c_pid;
  int	bit;
  char	*cc_pid;

  c_pid = getpid();
  bit = 31;
  while (bit >= 0)
    {
      if ((c_pid >> 1) & 1)
	{
	  if ((kill(s_pid, SIGUSR2)) == -1)
	    return (-1);
	}
      else
	if ((kill(s_pid, SIGUSR1)) == -1)
	  return (-1);
      if (usleep(1000) == -1)
	return (-1);
      bit--;
    }
  return (0);
}
