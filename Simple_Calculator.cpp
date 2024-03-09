#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    cout << "Simple Calculator App"<<endl;
    vector<double> numbers;   //Storing the numbers in a vector for calculation.
    char operation = '\0';   //This will store the operation
    double number;          //This will get input number from the user and then we will .push_back the number into the vector.
    char my_Input = 'y';   //Allowing it first time to be a true value. Once it gets '=' character the loop will exit.

    cout << "Enter the numbers followed by an operation (+, -, *, /)." << endl;
    cout << "Enter '=' when you when you wish to calculate the answer." << endl;

    while (my_Input != '=')
    {
        cout << "Enter number: ";
        cin >> number;
        numbers.push_back(number); //appending the number input by the user to the end of the vector.

        cout << "Enter operation (+, -, *, /) or '=' to calculate: ";
        cin >> my_Input;

        if (my_Input != '=')
        {
            operation = my_Input;
        }
    }
    double result = numbers[0]; // starting with the first number in the vector.

    for (size_t i = 1; i < numbers.size(); ++i)
    {
        switch (operation)
        {
        case '+':
            result += numbers[i];
            break;

        case '-':
            result -= numbers[i];
            break;

        case '*':
            result *= numbers[i];
            break;

        case '/':
            if (numbers[i] != 0)
            {
                result /= numbers[i];
            }
            else
            {
                cout << "Division by zero is not allowed.";
                return 1;
            }
            break;

        default:
            cout << "Invalid operation.";
            return 1;
        }
    }

    cout << "Result: " << result << endl;
    return 0;
}