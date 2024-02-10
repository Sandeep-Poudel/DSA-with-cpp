#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source = 'A', char destination = 'C', char auxiliary = 'B')
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << destination << "." << endl;
    }
    else
    {
        towerOfHanoi(n - 1, source, auxiliary, destination);
        cout << "Move "
             << "disk " << n << " from " << source << " to " << destination << "." << endl;
        towerOfHanoi(n - 1, auxiliary, destination, source);
    }
};

int main()
{
    int n;
    char source, auxiliary, destination;
    cout << "Enter the number of disks:";
    cin >> n;
    towerOfHanoi(n);
    return 0;
};