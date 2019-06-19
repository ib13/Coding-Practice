/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Polynomial
{
public:
    int *degCoeff;
    int capacity;
    // Default Constructor
    Polynomial()
    {
        this->degCoeff = new int[1];
        for (int i = 0; i < 1; i++)
        {
            degCoeff[i] = 0;
        }
        this->capacity = 1;
    }

    // Copy constructor
    Polynomial(Polynomial const &p)
    {
        this->degCoeff = new int[p.capacity];
        this->capacity = p.capacity;
        for (int i = 0; i < p.capacity; i++)
        {
            this->degCoeff[i] = p.degCoeff[i];
        }
    }

    // setCoefficient
    void setCoefficient(int degree, int coeff)
    {
        if (degree > this->capacity - 1)
        {
            int prevcap = this->capacity;
            int *arr = new int[degree + 1];
            this->capacity = degree + 1;

            for (int i = 0; i < this->capacity; i++)
                arr[i] = 0;

            for (int i = 0; i < prevcap; i++)
                arr[i] = this->degCoeff[i];

            delete[] this->degCoeff;
            this->degCoeff = arr;
        }
        this->degCoeff[degree] = coeff;
    }

    // +
    Polynomial operator+(Polynomial const &p) const
    {
        Polynomial p2;
        int mincap;
        int mincappoly;
        int maxcap;
        if (this->capacity < p.capacity)
        {
            mincap = this->capacity;
            maxcap = p.capacity;
            mincappoly = 1;
        }
        else
        {
            mincap = p.capacity;
            maxcap = this->capacity;
            mincappoly = 0;
        }

        for (int i = 0; i < mincap; i++)
        {
            int coeffsum = this->degCoeff[i] + p.degCoeff[i];
            p2.setCoefficient(i, coeffsum);
        }
        for (int i = mincap; i < maxcap; i++)
        {
            if (mincappoly == 1)
                p2.setCoefficient(i, p.degCoeff[i]);
            else
                p2.setCoefficient(i, this->degCoeff[i]);
        }
        // int *temp = new int[p2.capacity];
        // p2.degCoeff = temp;
        return p2;
    }

    // -
    Polynomial operator-(Polynomial const &p) const
    {
        Polynomial p2;
        int mincap;
        int mincappoly;
        int maxcap;
        if (this->capacity < p.capacity)
        {
            mincap = this->capacity;
            maxcap = p.capacity;
            mincappoly = 1;
        }
        else
        {
            mincap = p.capacity;
            maxcap = this->capacity;
            mincappoly = 0;
        }

        for (int i = 0; i < mincap; i++)
        {
            int coeffsum = this->degCoeff[i] - p.degCoeff[i];
            p2.setCoefficient(i, coeffsum);
        }
        for (int i = mincap; i < maxcap; i++)
        {
            if (mincappoly == 1)
                p2.setCoefficient(i, -1 * p.degCoeff[i]);
            else
                p2.setCoefficient(i, this->degCoeff[i]);
        }
        return p2;
    }

    // *
    Polynomial operator*(Polynomial const &p)
    {
        Polynomial p2;
        int *arr = new int[p.capacity + this->capacity];
        for (int i = 0; i < p.capacity + this->capacity; i++)
        {
            arr[i] = 0;
        }

        for (int i = 0; i < p.capacity; i++)
        {
            for (int j = 0; j < this->capacity; j++)
            {
                arr[i + j] += (p.degCoeff[i] * this->degCoeff[j]);
            }
            p2.degCoeff = arr;
            p2.capacity = p.capacity + this->capacity;
        }
        return p2;
    }

    // =
    Polynomial operator=(Polynomial const &p)
    {
        Polynomial p2;
        this->degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
        return *this;
    }

    // print
    void print()
    {
        for (int i = 0; i < this->capacity; i++)
        {
            if (this->degCoeff[i] != 0)
                cout << this->degCoeff[i] << "x" << i << " ";
        }
        cout << endl;
    }
};

//Driver program to test above functions
int main()
{
    int count1, count2, choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for (int i = 0; i < count1; i++)
    {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++)
    {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++)
    {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for (int i = 0; i < count2; i++)
    {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++)
    {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++)
    {
        second.setCoefficient(degree2[i], coeff2[i]);
    }
    cin >> choice;

    Polynomial p3(first);

    switch (choice)
    {
        // Add
    case 1:
    {
        Polynomial result1 = first + second;
        result1.print();
        break;
    }
        // Subtract
    case 2:
    {
        Polynomial result2 = first - second;
        result2.print();
        break;
    }
        // Multiply
    case 3:
    {
        Polynomial result3 = first * second;
        result3.print();
        break;
    }
    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }
    }

    return 0;
}
