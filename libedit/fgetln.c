#include <stdio.h>
#include "compat.h"

#ifndef HAVE_FGETLN

#ifndef HAVE_GETLINE
/* The interface here is that of GNU libc's getline */
static int
getline (char **lineptr, size_t *n, FILE *stream)
{
#define EXPAND_CHUNK 16

  int n_read = 0;
  char *line = *lineptr;

  if (lineptr == NULL) return -1;
  if (n == NULL) return -1;
  if (stream == NULL) return -1;
  if (*lineptr == NULL || *n == 0) return -1;
  
#ifdef HAVE_FLOCKFILE
  flockfile (stream);
#endif  
  
  while (1)
    {
      int c;
      
#ifdef HAVE_FLOCKFILE
      c = getc_unlocked (stream);
#else
      c = getc (stream);
#endif      

      if (c == EOF)
        {
          if (n_read > 0)
	    line[n_read] = '\0';
          break;
        }

      if (n_read + 2 >= *n)
        {
	  size_t new_size;

	  if (*n == 0)
	    new_size = 16;
	  else
	    new_size = *n * 2;

	  if (*n >= new_size)    /* Overflowed size_t */
	    line = NULL;
	  else
	    line = (char *)*lineptr ? realloc (*lineptr, new_size) : malloc (new_size);

	  if (line)
	    {
	      *lineptr = line;
	      *n = new_size;
	    }
	  else
	    {
	      if (*n > 0)
		{
		  (*lineptr)[*n - 1] = '\0';
		  n_read = *n - 2;
		}
	      break;
	    }
        }

      line[n_read] = c;
      n_read++;

      if (c == '\n')
        {
          line[n_read] = '\0';
          break;
        }
    }

#ifdef HAVE_FLOCKFILE
  funlockfile (stream);
#endif

  return n_read - 1;
}
#endif /* ! HAVE_GETLINE */

char *fgetln(FILE *stream, size_t *len)
{
  char *ptr = NULL;
  int sz = 0;

  sz = getline(&ptr,  &sz, stream);
  if(len) {
    *len = sz;
  }

  return sz >= 0 ? ptr : NULL;
}
#endif
