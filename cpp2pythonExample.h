#include <stdio.h>
class A
{
private:
    /* data */
    int m_i=0;
public:
    A(int i):m_i(i){}
    int getI() const
    {
        return m_i;
    }
};
void printA(const A &a)
{
    printf("The value of A instance is %i.\n", a.getI());
}