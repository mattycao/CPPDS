/* Notice here:
	It seems that in C++, it doesn't offer random generator, so here, we use the 
	C rand function to generate the random number.
 */

#include <iostream>
#include <ctime>
#include <new>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;
int max(int *, int);

int main (void)
{
int *a;
int n, i; // number of elements in the array a
int m; // we'll use this for the maximum
/* here goes code to read n numbers into a, probably from a file
Make sure to allocate space to a
*/
srand (time(NULL));

cin >> n;
a= new int[n];
for(i = 0; i < n; i++) {
	a[i] = rand() % 10000;
	cout << a[i] << endl;
}
// the next part is the loop you are supposed to replace by recursion.
m = max(a, n);
// This is the end of the loop.
cout << m << endl;
delete a;
a = NULL;
return 0;
}

int max(int *a, int n) {
	if(n == 1) {
		return *a;
	} else {
		if( *(a + (n - 1)) > max(a, (n - 1))) {
			return *(a + (n - 1));
		} else {
			return max(a, (n - 1));
		}
	}
}