#ifndef _HISTORY_
#define _HISTORY_

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history(){
  List* history = (List*)malloc(sizeof(List));
  history -> root = NULL; /*initlizes root to null*/
  return history;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  static int counter = 0 /* holds current counter */;
  Item *new_item = (Item*)malloc(sizeof(Item));
  new_item -> id = counter++;
  new_item -> str = strdup(str); /*allocates memory for string */
  new_item -> next = NULL;

  if (list -> root = NULL){
    list -> root = new_item;
  }
  else {
    Item *current= list -> root;
    while (current -> next != NULL){
      current = current -> next;
    }
    current -> next = new_item;
  }
  
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *current = list -> root; /*gets item of list*/
  while (current){
    if (current -> id == id){
      return current -> str;
    }
    curent = current -> next; /*goes to next entry if id dont match */
  }
  return NULL; /*id number was not found*/
}

/*Print the entire contents of the list. */
void print_history(List *list);

/*Free the history list and the strings it references. */
void free_history(List *list);

#endif
