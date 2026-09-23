#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int choice;
    int Rollno[100];
    float marks[100];
    int searchRollno;

    do
    {
        cout << "\n\n======= Student Management System =======";
        cout << "\n1. Add student";
        cout << "\n2. Display student";
        cout << "\n3. Search student using Rollno";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter Rollno: ";
            cin >> Rollno[n];

            cout << "Rollno added!";
            
            cout << "\nEnter marks: ";
            cin >> marks[n];

            n++;
        }
        else if (choice == 2)
        {
            cout << "\nRoll no of students:\n";

            for (int i = 0; i < n; i++)
            {
                cout << "Roll No: " << Rollno[i]
                     << "  Marks: " << marks[i] << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Enter Roll no to search: ";
            cin >> searchRollno;

            bool found = false;

            for (int i = 0; i < n; i++)
            {
                if (Rollno[i] == searchRollno)
                {
                    found = true;
                    cout << "Roll no found: " << Rollno[i] << endl;
                    break;
                }
            }

            if (!found)
            {
                cout << "Roll no not found!";
            }
        }
        else if (choice == 4)
        {
            cout << "Thank you!";
        }
        else
        {
            cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}

