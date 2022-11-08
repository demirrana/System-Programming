#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
   FILE *fp;
   fp = fopen("movies.csv" , "r");

   char command[255];
   
   typedef struct {
      
      char movieName[255];
      char director[255];
      char year[255];
      char genre[255];
      int ID;
      
   } Movie;
   
   Movie movies[100]; //csv dosyasindaki tum movieler
   char buffer[255]; //satirlari okumak icin
   int num = 1;
   int count = 0; //film sayisi
   
   while (fgets(buffer , 255 , fp)) //her satiri okuyup bilgileri movieler arrayine kaydeder
   {
      Movie current;
      
      char *tokenPtr;
      
      tokenPtr = strtok(buffer , "\"");
      strcpy(current.movieName , tokenPtr);
      
      tokenPtr = strtok(NULL , "\""); //aradaki ,'den kurtulmak icin
      
      tokenPtr = strtok(NULL , "\"");
      strcpy(current.director , tokenPtr);
      
      tokenPtr = strtok(NULL , ",");
      strcpy(current.year , tokenPtr);
      
      tokenPtr = strtok(NULL , ",");
      strcpy(current.genre , tokenPtr);
      
      int *IDPtr = &current.ID; 
      *IDPtr = num;
      
      movies[num - 1] = current; //cunku num 1'den basliyor
      
      count++;    num++;
   }
   
   int controller = 0; //ilk defa girdi almayacaksak basinda karakter girdisi almaliyiz ki sorun cikmasin
   char temp;
   
   while (true)
   {
   
      printf("Please enter a command: " );
      if (controller == 0)
      {
         scanf("%[^\n]", command);
         controller++;
      }
      else
      {
         scanf("%c" , &temp);
         scanf("%[^\n]" , command);
      }
      
      //gecerli girdi vermesini saglar
      while (strcmp(command , "print") != 0 && strcmp(command , "update") != 0 && strcmp(command , "search") != 0 && strcmp(command , "exit") != 0)
      {
         printf("Please enter a valid command: " );
         scanf("%c" , &temp);
         scanf("%[^\n]", command); 
      }
      
      if (strcmp(command , "print") == 0) //print komutu girilmisse her satiri yazdirir.
      {
         for (int i = 0; i < count; i++)
         {
            Movie current = movies[i];
            printf("%d. \"%s\", \"%s\", %s, %s" , current.ID , current.movieName , current.director , current.year , current.genre);
         }
      }
      else if (strcmp(command , "update") == 0)
      {
         char ID[3];
         printf("ID: ");
         scanf("%c" , &temp);
         scanf("%[^\n]" , ID);
         
         char newInfo[255];
         printf("New info: ");
         scanf("%c" , &temp);
         scanf("%[^\n]" , newInfo);
         
         int numID = atoi(ID);
         Movie current = movies[numID - 1];
         Movie *mvPtr = &(movies[numID - 1]);
         
         char *tokenPtr; //girilen inputtaki tokenlari ayirmak icin pointer
         
         bool first = false , second = false; //ilk kisimda veya ikinci kisimda " varsa bunu belirliyorum

         char *ptr = newInfo;
         int lastIndex;
         for (int i = 0; ptr[i] != ','; i++) //ilk ,'e kadar " varsa ona gore pointerima atama yapiyorum
         {
            if (ptr[i] == '\"')
               first = true;
            lastIndex = i;
         }
         for (int i = lastIndex + 2; ptr[i] != ','; i++) //ikinci kisimda " varsa ona gore pointerima atama yapiyorum
            if (ptr[i] == '\"')
               second = true;
         
         if (first && second)
         {
            tokenPtr = strtok(newInfo , "\"");
            for (int i = 0; i < strlen(tokenPtr); i++)
               if (tokenPtr[i] != ' ')
               {
                  strcpy(mvPtr->movieName , tokenPtr);
                  break;
               }
             
            tokenPtr = strtok(NULL , "\"");
            
            tokenPtr = strtok(NULL , "\"");
            for (int i = 0; i < strlen(tokenPtr); i++)
               if (tokenPtr[i] != ' ')
               {
                  strcpy(mvPtr->director , tokenPtr);
                  break;
               }
         }
         else if (first && !second)
         {
            tokenPtr = strtok(newInfo , "\"");
            for (int i = 0; i < strlen(tokenPtr); i++)
               if (tokenPtr[i] != ' ')
               {
                  strcpy(mvPtr->movieName , tokenPtr);
                  break;
               }
             
             tokenPtr = strtok(NULL , ",");
             for (int i = 0; i < strlen(tokenPtr); i++)
               if (tokenPtr[i] != ' ')
               {
                  strcpy(mvPtr->director , tokenPtr);
                  break;
               }
         }
         else if (!first && second)
         {
            tokenPtr = strtok(newInfo , ",");
            for (int i = 0; i < strlen(tokenPtr); i++)
               if (tokenPtr[i] != ' ')
               {
                  strcpy(mvPtr->movieName , tokenPtr);
                  break;
               }
            
            tokenPtr = strtok(NULL , "\"");
            for (int i = 0; i < strlen(tokenPtr); i++)
               if (tokenPtr[i] != ' ')
               {
                  strcpy(mvPtr->director , tokenPtr);
                  break;
               }
         }
         else
         {
            tokenPtr = strtok(newInfo , ",");
            for (int i = 0; i < strlen(tokenPtr); i++)
               if (tokenPtr[i] != ' ')
               {
                  strcpy(mvPtr->movieName , tokenPtr);
                  break;
               }
            
            tokenPtr = strtok(NULL , ",");
            for (int i = 0; i < strlen(tokenPtr); i++)
               if (tokenPtr[i] != ' ')
               {
                  strcpy(mvPtr->director , tokenPtr);
                  break;
               }
         }
         
         tokenPtr = strtok(NULL , ",");
         for (int i = 0; i < strlen(tokenPtr); i++)
            if (tokenPtr[i] != ' ')
            {
               strcpy(mvPtr->year , tokenPtr);
               break;
            }
         
         tokenPtr = strtok(NULL , ",");
         
         for (int i = 0; i < strlen(tokenPtr); i++)
            if (tokenPtr[i] != ' ')
            {
               strcat(tokenPtr , "\n"); //tum genre'lerin sonunda \n var bu yuzden buna da ekliyorum
               strcpy(mvPtr->genre , tokenPtr);
               break;
            }
      }
      
      else if (strcmp(command , "search") == 0)
      {
         printf("Search condition: ");
         char srchLine[255];
         scanf("%c" , &temp);
         scanf("%[^\n]" , srchLine);
         
         char parameter[255];
         char operator[2];
         char value[255];
         
         char *tokenPtr;
         
         tokenPtr = strtok(srchLine , " ");
         strcpy(parameter , tokenPtr);
         
         tokenPtr = strtok(NULL , " ");
         strcpy(operator , tokenPtr);
         
         tokenPtr = strtok(NULL , " ");
         strcpy(value , tokenPtr);
         
         if (strcmp(parameter , "year") == 0)
         {
            rewind(fp);
            int year = atoi(value);
            
            if (strcmp(operator , ">") == 0)
            {
               for (int i = 0; i < count; i++)
                  if (atoi(movies[i].year) > year)
                     printf("%d. \"%s\", \"%s\", %s, %s" , movies[i].ID , movies[i].movieName , movies[i].director , movies[i].year , movies[i].genre);
            }
            else if (strcmp(operator , "<") == 0)
            {
               for (int i = 0; i < count; i++)
                  if (atoi(movies[i].year) < year)
                     printf("%d. \"%s\", \"%s\", %s, %s" , movies[i].ID , movies[i].movieName , movies[i].director , movies[i].year , movies[i].genre);
            }
            else if (strcmp(operator , "==") == 0)
            {
               for (int i = 0; i < count; i++)
                  if (atoi(movies[i].year) == year)
                     printf("%d. \"%s\", \"%s\", %s, %s" , movies[i].ID , movies[i].movieName , movies[i].director , movies[i].year , movies[i].genre);
            }
            else if (strcmp(operator , "!=") == 0)
            {
               for (int i = 0; i < count; i++)
                  if (atoi(movies[i].year) != year)
                     printf("%d. \"%s\", \"%s\", %s, %s" , movies[i].ID , movies[i].movieName , movies[i].director , movies[i].year , movies[i].genre);
            }
         }
         
         else if (strcmp(parameter , "genre") == 0) //genre'ya gore arama yapiyorsak
         {
            char genre[255];
            strcpy(genre , value);
            
            if (strcmp(operator , "==") == 0)
            {
               for (int i = 0; i < count; i++)
               {
                  bool same = true;
                  for (int j = 0; ; j++)
                  {
                     if (genre[j] == ' ' || genre[j] == '\0' || genre[j] == '\n' || (movies[i].genre)[j] == ' ' || (movies[i].genre)[j] == '\0' || (movies[i].genre)[j] == '\n')
                     {
                        if (same)
                           printf("%d. \"%s\", \"%s\", %s, %s" , movies[i].ID , movies[i].movieName , movies[i].director , movies[i].year , movies[i].genre);
                        break;
                     }
                     if (genre[j] != movies[i].genre[j])
                        same = false;
                  }
               }
            }
            else if (strcmp(operator , "!=") == 0)
            {
               for (int i = 0; i < count; i++)
               {
                  bool same = true;
                  for (int j = 0; ; j++)
                  {
                     if (genre[j] == ' ' || genre[j] == '\0' || genre[j] == '\n' || (movies[i].genre)[j] == ' ' || (movies[i].genre)[j] == '\0' || (movies[i].genre)[j] == '\n')
                     {
                        if (!same)
                           printf("%d. \"%s\", \"%s\", %s, %s" , movies[i].ID , movies[i].movieName , movies[i].director , movies[i].year , movies[i].genre);
                        break;
                     }
                     if (genre[j] != movies[i].genre[j])
                        same = false;
                  }
               }
            }
         }
      }
      else //exit girilmistir
      {
         printf("Exiting program.\n");
         fclose(fp);
         exit(0);
      }
   }

   return 0;
}
