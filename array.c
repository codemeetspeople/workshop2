#include <stdio.h>
#include <stdlib.h>

#define LIST_INITIAL_SIZE 10

typedef struct {
    int* array;
    int size;
    int current;
} List;

void List_init(List* lst) {
    lst->size = LIST_INITIAL_SIZE;
    lst->current = 0;
    lst->array = (int*)malloc(lst->size*sizeof(int));
}

void List_info(List* lst) {
    printf("List (%d/%d)\n", lst->current, lst->size);
}

void List_push(List* lst, int value) {
    if ( lst->current == lst->size ) {
        int size = lst->size + LIST_INITIAL_SIZE;
        
        lst->array = (int*)realloc(lst->array, size*sizeof(int));
        lst->size = size;
    }

    lst->array[lst->current] = value;
    lst->current += 1;
}

void List_insert(List* lst, int index, int value) {
    if ( index < 0 || index > lst->size - 1) {
        printf("Wrong index!\n");
        return;
    }
    if ( lst->current == lst->size ) {
        int size = lst->size + LIST_INITIAL_SIZE;
        
        lst->array = (int*)realloc(lst->array, size*sizeof(int));
        lst->size = size;
    }
    lst->current += 1;

    for ( int i = lst->current; i > index; i-- ) {
        lst->array[i] = lst->array[i-1];
    }
    lst->array[index] = value;
}

int List_pop(List* lst) {
    if ( lst->current == 0 ) {
        printf("List is empty!\n");
        return 0;
    }

    lst->current -= 1;
    return lst->array[lst->current];
}

void List_print(List* lst) {
    if ( lst->current == 0 ) {
        printf("List is empty!\n");
        return;
    }

    int last = lst->current - 1;

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", lst->array[i]);
    }
    printf("%d\n", lst->array[last]);
}

void List_free(List* lst) {
    lst->size = 0;
    lst->current = 0;
    free(lst->array);
}

void List_empty(List* lst) {
    lst->size = LIST_INITIAL_SIZE;
    lst->current = 0;
    lst->array = (int*)realloc(lst->array, lst->size*sizeof(int));
}

int main() {
    List list;

    List_init(&list);
    List_info(&list);

    List_push(&list, 100);
    List_push(&list, 200);
    List_push(&list, 300);
    List_push(&list, 400);
    List_push(&list, 500);
    
    List_info(&list);
    List_print(&list);

    List_insert(&list, 3, 1000);

    List_info(&list);
    List_print(&list);

    List_insert(&list, 0, 1111);
    List_info(&list);
    List_print(&list);

    List_push(&list, 700);
    List_push(&list, 800);
    List_push(&list, 900);
    List_info(&list);
    List_print(&list);

    List_insert(&list, 3, 1488);
    List_info(&list);
    List_print(&list);

    List_free(&list);

    return 0;
}
