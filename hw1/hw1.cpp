/* Two things need to notice:
	1. Dynamic Memory allocation in C and C++:
		in C:
			int n;
			int* b;
			cin >> n;
			b = (int*) malloc(n*sizeof(int));
			for(int i = 0; i < n; i++) {
				cin >> b[i];
			}
			// operations, and for  good coding practice, whould probably also check whether 
				// b == NULL before dereferencing it.
			free(b);
			b = NULL;

		in C++:
			int n;
			int *b, *p;
			cin >> n;
			b = new int[n];
			*p = new int;
			// operation
			delete [] b;
			delete p;
			b = NULL;
			p = NULL;
	2. The time measuring method:
		see the coding advice for C++
 */


#include <iostream>
#include <ctime>
#include <new>
using namespace std;
int sumof(int *, int);

int main(void) {
	int *a;
	int n, i; // number of elements in the array a
	int sum; // use this for adding numbers
	clock_t start, finish;
	double dur;

	cin>>n; // dynamic allocate the size of array
	a = new int[n];

	start = clock();
	// initial the value of the array 
	for(i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	sum = sumof(a, n);
	cout << "The result:" << sum << endl;
	delete a;
	a = NULL;
	finish = clock();

	dur = (double)(finish - start);
	dur /= CLOCKS_PER_SEC;
	cout << "Elapsed seconds: "<< scientific << dur << endl;
	return 0;

}

int sumof(int *a, int n) {
	int sum;
	if(n == 0) {
		return 0;
	} else {
		sum = sumof(a, (n - 1)) + *(a + (n - 1));
	}
	return sum;
}

