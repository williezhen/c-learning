#include "Alloc.h"

int Alloc::total_allocations = 0;
int Alloc::net_allocations = 0;
int Alloc::total_bytes;

char * Alloc::new_char_array(size_t n_bytes)
{
    ++net_allocations;
    ++total_allocations;
    total_bytes += n_bytes;
    return new char[n_bytes];

}

void Alloc::delete_char_array(char * p)
{
    if (p != nullptr)
    {
        --net_allocations;
        delete[] p;
    }
    else
        cout << "DELETE nullptr;" << endl;

}

void Alloc::report_allocations()
{   
    cout << "Total allocations: " << total_allocations << endl;
    cout << "Total bytes: " << total_bytes << endl;
    if (net_allocations != 0)
        cout << "ERROR: Mismatching number of new/delete: " << net_allocations << endl;
    else
        cout << "Yay! All allocated memory has been freed! (probably)" << endl;
}

