#include<iostream>
using namespace std;

struct Array{
	int* A;
	int size;
	int length;
};

void add(struct Array &arr,int x) {
	arr.A[arr.length] = x;
	arr.length++;
}

void insert(struct Array& arr, int k, int m) {
	for (int i = arr.length; i > k; --i) {
		arr.A[i] = arr.A[i - 1];
	}
	arr.A[k] = m;
	arr.length++;
}


void Delete(struct Array& arr,int in) {
	int x = arr.A[in];
	for (int i = in; i < arr.length;++i) {
		arr.A[i] = arr.A[i + 1];

	}
	arr.length = arr.length - 1;
}

void L_search(struct Array& arr, int s_in) {

	for (int i = 0; i < arr.length; ++i) {
		if (s_in == arr.A[i]) {
			cout << s_in << " at index of " << i << endl;
		}
		
	}
}

void Display(struct Array arr) {
	int i;
	cout << "Display array: ";
	for (i = 0; i < arr.length; ++i) {
		cout << arr.A[i]<<" ";
	}
	cout << endl;

	cout << arr.length << endl;
	cout << arr.size<<endl;
}
int main()
{
	struct Array arr;
	int n, i;
	cout << "enter the size of an array: ";
	cin >> arr.size;

	arr.A = new int[arr.size];
	arr.length = 0;

	cout << endl;
	cout << "enter the  number of numbers: ";
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> arr.A[i];
		
	}
	arr.length = n;
	Display(arr);
	
	//adding element
g1:
	int x=0;
	cout << "enter a new element for array: ";
	cin >> x;
	add(arr, x);
	cout << "add ->";
	Display(arr);
	string y;
	cout << endl << "Enter (y) to add another Element or press (x): ";
	cin >> y;


	if (y == "y") {
		goto g1;
	}
	

	//inserting an element
	int k, m;
	cout << endl << "enter the index number and element: ";
	cin >> k >> m;
	if (k <= arr.length) {
		insert(arr, k, m);
	}
	else {
		cout << "index is larger than the exixting one" << endl;
	}
	
	Display(arr);


	//delete and array element
	cout << endl;
	int in;
	cout << "enter the index number to delete and element: ";
	cin >> in;

	if (in <=arr.length) {
		Delete(arr, in);
	}
	else {
		cout << "The length of the array is " << arr.length << endl;;
	}
	
	Display(arr);


	cout << endl;
	//searchinng an element
	int s_in;

	cout << "enter the element number to search: ";
	cin >> s_in;
	L_search(arr, s_in);


	return 0;
}