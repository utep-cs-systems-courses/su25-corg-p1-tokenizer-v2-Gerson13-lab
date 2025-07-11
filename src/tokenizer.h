#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdlib.h>
#include <string.h>


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  return((c == ' ') || (c == '\t'));
}


/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  return(!space_char(c));
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){
  char *p = str; 
  while(space_char(*p)){
      p++;
    }
  if (*p == '\0'){
      return NULL;
    }
  return p;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
    /*checks if empty*/
    if (!token){ return NULL;}
    
    char *p = token;
    while (*p != '\0' && non_space_char(*p)){
	p++;
      }
      return p;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
      int count=0;
      char *start = token_start(str);
      while(start){
	count++;
	char *end = token_terminator(start);
	start = token_start(end); /*moves to next token*/
      }
      return count;
}
      

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *str_copy = malloc(len +1); /*len+1 to store end char*/
  for (short i=0; i< len; i++) {
    str_copy[i] = inStr[i];
  }
  str_copy[len] = '\0'; /*last entry*/
  return str_copy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
      int count = count_tokens(str);
      char **tokens = malloc((count+1) * sizeof(char *));
      char *start = token_start(str);
      int i=0;

      while(start){
	char *end = token_terminator(start);
	int len = end - start;

	tokens[i] = copy_str(start, len);
	i++;
	start = token_start(end);
      }
      tokens[i] = NULL;
      return tokens;
}
 
 /* Prints all tokens. */
 void print_tokens(char **tokens){
   printf("[");
   for(int i=0; tokens[i] != NULL; i++) {
     printf("\"%s\"", tokens[i]);
     if(tokens[i+1] != NULL) {
       printf(", ");
     }
   }
   printf("]\n");
 }

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  char **p = tokens;
  while(*p){
    free(*p);
    p++;
  }
  free(tokens);
}

#endif
