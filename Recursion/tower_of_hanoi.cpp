#include<iostream>
using namespace std;
int i=0;
void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        i++;
        cout<<"\nStep"<<i<<"."<<from<<"->"<<to;
        return;
    }
    towerOfHanoi(n-1, from, aux, to);
    i++;
    cout<<"\nStep"<<i<<"."<<from<<"->"<<to;
    towerOfHanoi(n-1, aux, to, from);
}
 
int main()
{
    int n;
    cin>>n;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}