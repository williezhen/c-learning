#include "alloc.h"

using namespace std;

int Alloc1::total_allocations = 0;
int Alloc1::net_allocations = 0;
int Alloc1::total_bytes = 0;

char* Alloc1::new_char_array(size_t n_bytes) {
	++net_allocations;
	++total_allocations;
	total_bytes += n_bytes;
	return new char[n_bytes];
}

void Alloc1::delete_char_array(char* p) {
	if (p != nullptr) {
		--net_allocations;
		delete[] p;
	}
	else {
		cout << "DELETE nullptr;" << endl;
	}
}

void Alloc1::report_allocations() {
	cout << "Total allocations: " << total_allocations << endl;
	cout << "Total bytes: " << total_bytes << endl;
	if (net_allocations != 0) {
		cout << "ERROR: Mismatching number of new/delete: "
			<< net_allocations << endl;
	}
	else {
		cout << "Yay! All allocated memory has been freed! (probably)" << endl;
	}
}