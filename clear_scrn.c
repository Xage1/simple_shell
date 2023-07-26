#include "Alxhell.h"

/**
 * clear_screen - Function to handle the clear command
 */

void clear_screen(void)
{
#ifdef _WIN32
system("cls");
#else
system("clear");
#endif
}

