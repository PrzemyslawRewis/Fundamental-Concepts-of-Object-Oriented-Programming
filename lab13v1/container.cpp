#include "container.h"

Container *Container::mem_ptr=nullptr;
int Container::mem_size=0;

int &Container::value()
{
    return _var;
}

void *Container::operator new(size_t)
{
    
    return mem_ptr;
    exit(0);

   /* if(mem_ptr==nullptr)
    {
        cout<<"Pierwszy obiekt na stercie - alokuje kontener na 100 elementow"<<endl;
        mem_ptr=static_cast<Container*>(malloc(100*sizeof(Container)));
    }
    mem_size++;
    cout<<"--- Alokuje 1 --- Wolne miejsca: "<<MEM_MAX-mem_size<<endl;
    return mem_ptr+mem_size-1;*/
}

void Container::operator delete(void *)
{    

    /*mem_size--;
    cout<<"--- Zwalniam 1 --- Wolne miejsca: "<<MEM_MAX-mem_size<<endl;
    if(mem_size==0)
    {
        free(mem_ptr);
        mem_ptr=nullptr;
        cout<<"Ostatni obiekt na stercie, zwalnia kontener"<<endl;
    }*/
}

void *Container::operator new[](size_t size)
{
    return mem_ptr;
    /*if(mem_ptr==nullptr)
    {
        cout<<"Pierwszy obiekt na stercie - alokuje kontener na 100 elementow"<<endl;
        mem_ptr=static_cast<Container*>(malloc(100*sizeof(Container)));
    }
    mem_size+=size/sizeof(Container);
    cout<<"--- Alokuje ["<<size/sizeof(Container)<<"] --- Wolne miejsca: "<<MEM_MAX-mem_size<<endl;
    return mem_ptr+mem_size-size/sizeof(Container);*/
}

void Container::operator delete[](void *ptr)
{
    
    /*cout<<"--- Zwalniam [""] --- Wolne miejsca: "<<MEM_MAX-mem_size<<endl;
    if(mem_size==0)
    {
        free(mem_ptr);
        mem_ptr=nullptr;
        cout<<"Ostatni obiekt na stercie, zwalnia kontener"<<endl;
    }*/
}