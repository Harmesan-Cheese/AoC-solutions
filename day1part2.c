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

   int lnindex = 0;
   int previoussum = 999999;
   int currentsum = 0;
   int previousnum = 0;
   int currentnum;
   char *currentstr = (char *)malloc(sizeof(char) * 5);
   int largerthan = 0;
   int j = 0;

   for (int i = 0; buffer[i] != '\0'; i++) {
      for (int abc = 0; abc != 3; abc++) {
         if (abc == 1) lnindex = i - 1;
         while (buffer[i] != '\n' && buffer[i] != '\0') {
            currentstr[j] = buffer[i];
            j++;
            i++;
         }
         j = 0;
         currentnum = atoi(currentstr);
         strcpy(currentstr, "");

         currentsum += currentnum;
         currentnum = 0;
         i++;
      }

      if (currentsum > previoussum) largerthan++;
      previoussum = currentsum;
      currentsum = 0;
      if (buffer[i] != '\0') i = lnindex;
   }

   printf("%d\n", largerthan);

   return 0;
}
