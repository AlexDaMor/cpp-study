

int* bubble_sort    (int* source);
int* insertion_sort (int* source);
int* merge_sort     (int* source);
int* quick_sort     (int* source);
int* heap_sort      (int* source);
int* selection_sort (int* source);


int* create_source  (int size, int range); 
//returns ptr to an array with [size] random elemets with values from 0 to [range]
void show_array(int* source, int size, int space, int row_length);
