#include <iostream>

using namespace std;

typedef struct ListNode* List;

struct ListNode {
	char data;
	List next;

	ListNode(char new_data, List new_next) : data(new_data), next(new_next){
	/*	data = new_data;
		next = new_next;*/
		++net_allocations;
		++total_allocations;
		total_bytes += sizeof(ListNode);
	}

	~ListNode() {
		--net_allocations;
	}
	static List list_from_string(const char* s);
	static List list_copy(List L);
	static List list_reverse(List L);
	static List list_append(List L1, List L2);
	static List list_str(List haystack, List needle);
	static List list_chr(List str, int c);
	static List list_nth(List str, int n);
	static void list_delete(List L);
	static void print(ostream& out, List L);
	static int list_difference(List L1, List L2);
	static List list_last(List L);
	static int list_cmp(List L1, List L2);
	static int list_ncmp(List L1, List L2, int);
	static int list_length(List L);
	static void report_allocations() {
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
private:
	
	static int total_allocations;
	static int total_bytes;
	static int net_allocations;
};