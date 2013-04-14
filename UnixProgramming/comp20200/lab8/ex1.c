#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LEN 200

int main()
{

  FILE *fp_in, *fp_out;
  char *name_in = "input.txt";
  char *name_out = "output.txt";

  fp_in = fopen(name_in, "r");
  fp_out = fopen(name_out, "w");

  if(fp_in == NULL)
  {
    fprintf(stderr,"input.txt failed to open\n");
    return 0;
  }
  if(fp_out == NULL)
  {
    fprintf(stderr,"output.txt failed to open\n");
    return 0;
  }

  struct stat st;
  stat(name_in, &st);
  int size = st.st_size;

  char buffer[MAX_LEN]; 

  char c;
  int i=0;
  while(c != EOF)
  {
    c = fgetc(fp_in);
    buffer[i++] = c;
  }

  fprintf(fp_out,"%s", buffer);

  fclose(fp_in);
  fclose(fp_out);
  return 0;
}
