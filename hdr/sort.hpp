

int* bubble_sort    (int* source,int size);
int* insertion_sort (int* source,int size);
int* merge_sort     (int* source,int size);
int* quick_sort     (int* source,int size);
int* heap_sort      (int* source,int size);
int* selection_sort (int* source,int size);


int* create_source  (int size, int range); 
//returns ptr to an array with [size] random elemets with values from 0 to [range]
void show_array(int* source, int size, int space, int row_length);
//prints source array of size elements, col width=space, col quantity=row_length
