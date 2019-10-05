#include<iostream>
using namespace std;
// This function first print the value the execute the next statement i.e (recursive call)
void fun1(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        fun1(n-1);
    }
}

int main()
{
    int x=3;
    fun1(3);
    return 0;
}
