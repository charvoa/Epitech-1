/*
** signal.c for signal in /home/garcia_t/42/execution
**
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
**
** Started on  Mon May 19 11:27:27 2014 garcia antoine
** Last update Wed May 28 14:27:22 2014 Nicolas Charvoz
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "../parser/parser.h"
#include "execution.h"

t_signal	g_signal[] =
  {
    {SIGSEGV, "Segmentation fault"},
    {SIGALRM, "Clock Alarm"},
    {SIGIOT, "IOT Trap"},
    {SIGSTKFLT, "Stack Fault"},
    {SIGPROF, "Profiling alarm Clock"},
    {SIGPWR, "Power failure restart"},
    {SIGTSTP, "Suspend by keyboard"},
    {SIGBUS, "Bus error"},
    {SIGABRT, "Abort"},
    {SIGFPE, "Floating point exception"},
    {SIGILL, "Illegal instruction"},
    {SIGKILL, "Killed"},
    {SIGPIPE, "Broken pipe"},
    {SIGTRAP, "Trace trap"},
    {SIGCHLD, "Child stop"},
    {SIGXCPU, "CPU limit reached"},
    {SIGTERM, "Terminated"},
    {SIGUSR1, "User signal 1"},
    {SIGUSR2, "User signal 2"}
  };

int	check_signal(int status)
{
  int	i;

  i = 0;
  if (status == 0)
    return (0);
  while (g_signal[i].nb)
    {
      if (status == g_signal[i].nb)
	printf("%s\n", g_signal[i].msg);
      i++;
    }
  return (-1);
}
