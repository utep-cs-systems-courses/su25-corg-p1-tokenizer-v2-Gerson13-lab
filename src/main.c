#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main(){
  List *history = init_history();
  char input[1024];

  while(1){
    printf(":) ");
    if(fgets(input, sizeof(input), stdin)) {
      input[strcspn(input, "\n")] = '\0';

      if(input[0] == '!' && strlen(input) > 1){/* checks if string is history query */
	int id = atoi(input +1); /* points to number after ! */
	char *fetch = get_history(history, id);
	if (!fetch) {
	  printf("No history at %d  \n", id);
	}
	else {
	  printf("History at %d : %s\n" ,id,  fetch);
	}
      }
      else {
	add_history(history, input);
	char **tokens = tokenize(input);
	print_tokens(tokens);
	free_tokens(tokens);
      }
    }
  }
  free_history(history);
  return 0;
}
