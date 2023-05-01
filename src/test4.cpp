#include <iostream>

class MyInt
{
public:
    explicit MyInt(int *pdNum)
    //MyInt(int *pdNum)
    {
        std::cout << "in MyInt(int*)" << '\n';
        pdNimPtr = pdNum;
    }
    int getMyInt() const
    {
        return *pdNimPtr;
    }
    ~MyInt(void)
    {
        std::cout << "in ~MyInt()" << '\n';
        if (pdNimPtr != nullptr)
        {
            delete pdNimPtr;
        }
    }

private:
    int *pdNimPtr{nullptr};
};

/*
void Print(MyInt input)
{
    std::cout << "in print_MyInt" << '\n';
    std::cout << input.getMyInt() << '\n';
}
*/

void Print(const MyInt& input)
{
    std::cout << "in print_MyInt" << '\n';
    std::cout << input.getMyInt() << '\n';
}

int main(void)
{
    int *pdNum = new int(666);
    // Print(pdNum);
    MyInt myInt(pdNum);
    Print(myInt);
    int *pdNewNum = new int(888);
    *pdNum = 18;
    std::cout << *pdNewNum << '\n';
    delete pdNewNum;
    return 0;
}