/*
** xmalloc.c for minitalk in /home/exposi_p/rendu/PSU_2013_minitalk
**
** Made by exposi_p
** Login   <exposi_p@epitech.net>
**
** Started on  Tue Mar 18 20:22:17 2014 exposi_p
** Last update Tue Mar 18 20:22:33 2014 exposi_p
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../../inc/server/server.h"

void		*xmalloc(int size)
{
  void		*tab;

  tab = malloc(size);
  if (tab == NULL)
    {
      write(2, "Error : malloc\n", 15);
      exit (-1);
    }
  return (tab);
}
