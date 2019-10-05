#include<iostream>
using namespace std;

// This function first call itself again and again until the condition is not false ,
// afterthat it will go back to its last recursive call and then print the value..
void fun2(int n)
{
    if(n>0)
    {
        fun2(n-1);
        cout<<n<<" ";
    }
}

int main()
{
    int x=3;
    fun2(x);
    return 0;
}
