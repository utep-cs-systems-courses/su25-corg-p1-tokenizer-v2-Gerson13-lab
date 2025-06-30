#include <stdio.h>
#include "tokenizer.h"
#include "history.h"


int main(){
  List *history = init_history();
  char input[1024];

  while(1) {
    printf(":) ");
    if(!fgets(input sizeof(input), stdin)) break;
    input[strcspn(input, "\n")] = '\0';

    if(input[0] == '!' && strlen(input) >1){
      int id = atoi(input+1);
      char *cmd = get_history(history, id);
      if (cmd) printf("No history item found.\n");
    } else if (strcmp(inpit, "history") == 0) {
      print_history(history);
    } else{
      add_history(history, input);
    }

  }
  free_history(history);
  return 0;
}
