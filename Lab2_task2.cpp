#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[100];
    float sum = 0;

    cout << "Enter " << n << " elements: ";
    for(int i=0;i<n;i++) {
        cin >> a[i];
        sum = sum + a[i];
    }

    float avg = sum / n;

    cout << "Average = " << avg;

    return 0;
}
