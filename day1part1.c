#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char *buffer;
   long length;
   long readlength;
   FILE *fp;
   fp = fopen("input2", "r");

   if (fp == NULL)
   {
      perror("ERROR: File doesn't exist\n");
      exit(EXIT_FAILURE);
   }

   fseek(fp, 0, SEEK_END);
   length = ftell(fp);
   fseek(fp, 0, SEEK_SET);

   buffer = (char *)malloc(length + 1);

   if (length) {
      readlength = fread(buffer, 1, length, fp);

      if (length != readlength) {
         free(buffer);
         perror("ERROR: Error reading file\n");
         exit(EXIT_FAILURE);
      }
   }

   fclose(fp);

   buffer[length] = '\0';

   // LOGIC

   int previousnum = 999999;
   int currentnum;
   char *currentstr = (char *)malloc(sizeof(char) * 5);
   int largerthan = 0;
   int j = 0;

   for (int i = 0; buffer[i] != '\0'; i++) {
      while (buffer[i] != '\n') {
         currentstr[j] = buffer[i];
         j++;
         i++;
      }
      j = 0;
      currentnum = atoi(currentstr);
      strcpy(currentstr, "");
      if (currentnum > previousnum) largerthan++;
      previousnum = currentnum;
      currentnum = 0;
   }

   printf("%d\n", largerthan);

   return 0;
}
