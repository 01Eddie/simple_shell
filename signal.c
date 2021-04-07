#include "shell.h"
/**
 * ctrlC - function of detected ctrl + c or ANSI C signal handling
 * @sig_num: Integer
 * Return: void
 *
 * Reset handler to catch SIG_IGN next time.
 * Refer http://en.cppreference.com/w/c/program/signal
 * Signal Handler for SIG_IGN
 */
 /* Esto seria bueno que lo pongamos en el main */
void ctrlC(int sig_num)
{
	signal(sig_num, SIG_IGN);
	fflush(stdout);
}
