#include <hdr/sort.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <chrono>

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
    int sum{0};
    for (int i=0; i<size/row_length;i++)
    {
        for (int j=0; j<row_length; j++)
        {
            std::cout<<std::setw(space)<<source[row_length*i+j];
            sum+=source[row_length*i+j];
        }
        std::cout<<std::endl;
    }
    if(last_row_length>0)
        for (int i=0; i<last_row_length;i++)
        {
            std::cout<<std::setw(space)<<source[size/row_length*row_length+i];
            sum+=source[size/row_length*row_length+i];
        } 
    std::cout<<std::endl<<"Sum of array: "<<sum<<std::endl;
}


int* bubble_sort    (int* source, int size)
{
    bool swap{true};
    int temp{0};
    while (swap)
    {
        swap=false;
        for (int j=1;j<size;j++)
           if (source[j-1]>source[j])
           {
               temp=source[j];
               source[j]=source[j-1];
               source[j-1]=temp;
               swap=true;
           }
    }
    return source;
}
int* insertion_sort (int* source,int size)
{
    int temp{0};
    int pos{0};
    for (int i=1;i<size;i++)
    {
        temp=source[i];
        pos=i;
        for (int j=i;j>0;j--)
            if (temp<source[j-1])
            {
                pos=j-1;
                source[j]=source[j-1];
            }
            else break;
        source[pos]=temp;
    }
    return source;
}
int* merge_sort     (int* source,int size)
{ 
    //array of size 1 is sorted
    if (1==size)
    {
        return source;
    }
    //partition array, calc pointers and sizes of parts 
    int first_part_size=size/2;
    int second_part_size = size-first_part_size;
    int* first_part = source;
    int* second_part = source+(size/2);
    //sorting recursively
    first_part=merge_sort(first_part, first_part_size);
    second_part=merge_sort(second_part, second_part_size);
    //merging sorted parts to temp array
    int* temp=new int[size]{};
    int pos1=0;
    int pos2=0;
    int pos_temp=0;
    while((pos1<first_part_size)&&(pos2<second_part_size))
    {
      if (first_part[pos1]<=second_part[pos2])  
          temp[pos_temp++]=first_part[pos1++];
      else
          temp[pos_temp++]=second_part[pos2++];
         
    }
    if (pos1==first_part_size)
        while(pos2<second_part_size)
            temp[pos_temp++]=second_part[pos2++];
    else
        while(pos1<first_part_size)
            temp[pos_temp++]=first_part[pos1++];
    //copy sorted contents to source array
    for (int i=0;i<size;i++)
        source[i]=temp[i];
   
    delete[] temp;

    return source;
}
int* quick_sort     (int* source,int size){return nullptr;}
int* heap_sort      (int* source,int size){return nullptr;}
int* selection_sort (int* source,int size){return nullptr;}


int main()
{
    int size{100};
    int range{100};
    int* test=create_source(size,range);
    std::cout<<"Source array"<<std::endl;
    show_array(test,size,4,10);
    merge_sort(test,size);
    std::cout<<std::endl<<"Sorted array"<<std::endl;
    show_array(test,size,4,10);
    delete[] test;
  return 0;
}



