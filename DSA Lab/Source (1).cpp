#include <iostream>
#include <stack>
using namespace std;

void sum(int n1, int n2)
{
    int remainder = 0, reversed_number = 0, r2 = 0, r = 0;
    stack<int> num1, num2, result;


    while (n1 != 0) {
        remainder = n1 % 10;
        reversed_number = reversed_number * 10 + remainder;
        n1 /= 10;
    }
    n1 = reversed_number;


    while (n1 > 0)
    {
        num1.push(n1 % 10);
        n1 /= 10;
    }



    while (n2 != 0) {
        r = n2 % 10;
        r2 = r2 * 10 + r;
        n2 /= 10;
    }
    n2 = r2;


    while (n2 > 0)
    {
        num2.push(n2 % 10);
        n2 /= 10;
    }

    // Add the digits in the two stacks, one by one
    int carry = 0;
    while (!num1.empty() || !num2.empty())
    {
        int d1 = 0,d2=0;
        if (!num1.empty())
        {
            d1 = num1.top();
            num1.pop();
        }
        else
            d1 = 0;
        if (!num2.empty()) {
            d2 = num2.top();
            num2.pop();
        }
        else
            d2 = 0;
        int sum = d1 + d2 + carry;
        result.push(sum % 10);
        carry = sum / 10;
    }

    // If there is a carry left over, push it onto the result stack
    if (carry > 0) 
        result.push(carry);

    // Print the result

    while (!result.empty())
    {
        cout << result.top();
        result.pop();
    }
}


void sum(string n1, string n2)
{
    int remainder = 0, reversed_number = 0, r2 = 0, r = 0;
    stack<int> num1, num2, result;
    int l1 = n1.length(), l2 = n2.length();

    for(int i=0 ; i< l1 ;i++)
    {
        num1.push(n1[i] - '0');
    }

    for (int i = 0; i < l2; i++)
    {
        num2.push(n2[i] - '0');
    }
    // Add the digits in the two stacks, one by one
    int carry = 0;
    while (!num1.empty() || !num2.empty())
    {
        int d1 = 0, d2 = 0;
        if (!num1.empty())
        {
            d1 = num1.top();
            num1.pop();
        }
        else
            d1 = 0;
        if (!num2.empty()) {
            d2 = num2.top();
            num2.pop();
        }
        else
            d2 = 0;
        int sum = d1 + d2 + carry;
        result.push(sum % 10);
        carry = sum / 10;
    }

    // If there is a carry left over, push it onto the result stack
    if (carry > 0)
        result.push(carry);

    // Print the result

    while (!result.empty())
    {
        cout << result.top();
        result.pop();
    }
}



int main()
{
    cout << "FOR INTEGERS " << endl;
    sum(1, 569);
    cout << endl;
    sum(12345, 99);
    cout <<endl<< "FOR STRINGS " << endl;
    sum("1", "569");
    cout << endl;
    sum("12345", "99");

}