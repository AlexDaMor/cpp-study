#include <hdr/sort.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
//#include <ios>

int* create_source(int size, int range)
{
    std::srand(std::time(0));
    int* source=new int[size]{};
    for (int i=0; i<size; i++)
        source[i]=std::rand()%range;
    return source;
}

void show_array(int* source, int size, int space, int row_length)
{
    int last_row_length=size%row_length;
    for (int i=0; i<size/row_length;i++)
    {
        for (int j=0; j<row_length; j++)
            std::cout<<std::setw(space)<<source[row_length*i+j];
        std::cout<<std::endl;
    }
    if(last_row_length>0)
        for (int i=0; i<last_row_length;i++)
            std::cout<<std::setw(space)<<source[size/row_length+i];
    std::cout<<std::endl;
}


int* bubble_sort    (int* source){return nullptr;}
int* insertion_sort (int* source){return nullptr;}
int* merge_sort     (int* source){return nullptr;}
int* quick_sort     (int* source){return nullptr;}
int* heap_sort      (int* source){return nullptr;}
int* selection_sort (int* source){return nullptr;}


int main()
{
  int size{103};
  int range{100};
  int* test=create_source(size,range);
  show_array(test,size,4,10);
  return 0;
}

