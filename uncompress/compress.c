
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

// TODO: Check for malloc/realloc pointers
// TODO: Take String form File / Commandprompt?

char * uncompress(char **head) {

  char * subStr=NULL;
  char * genString=NULL;

  if ( **head == '\0' ) {
    return NULL;
  }

  int repeat=0;
  repeat=strtol(*head, NULL, 10);

  while(**head != '[') 
    (*head)++;

  // Move [
  (*head)++;

  //Allocate one byte with NULL, so that it can be used in Strncat
  genString=(char *) malloc(sizeof(char));
  genString[0]='\0';

  // Move Chars
  int totalSize=0;
  while (**head != ']') {

    char * strPtr= *head;
    int preChar=0; 
    while (**head >= 'a' && **head <= 'z' ) {
      (*head)++;
      preChar++;
    }
    totalSize+=preChar;
    genString=(char *) realloc(genString, totalSize); 
    strncat(genString,strPtr,preChar); 

    if ( **head >= '0' &&  **head <='9') {
      subStr = uncompress(head);
      totalSize+=strlen(subStr);
      genString= realloc(genString, totalSize); 
      strncat(genString,subStr,strlen(subStr)); 
      // Free string from previous
      free(subStr);
    }
  }
  // Move out of ]
  (*head)++;

  // Create final String 
  char * unzipStr=NULL;
  unzipStr= (char *)malloc(totalSize*repeat); 
  unzipStr[0]='\0'; 
  // Any repeatations
  for(int i=0; i<repeat; i++) {
    strncat(unzipStr,genString,totalSize); 
  }
  free(genString);
  return unzipStr;
}



int main() {

  char *compress="2[3[a]b]";
  char * unzip=NULL;
  unzip=uncompress(&compress);
  printf("Uncompress=%s\n", unzip);
  return 0;

}
