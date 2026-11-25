#include <iostream>
#include <string>
#include <limits>
using namespace std;
struct Course
{
string name;
Course* next;
};
struct Student
{
    int roll;
    string name;
    string department;
    Course* courses;
    Student* Next;
    Student* hashNext;
};
Student* head = NULL;
const int SIZE = 10;
Student* hashTable[SIZE] = {NULL};
// Hash Function
int hashFunction(int roll)
{
    return roll % SIZE;
}
// Register Student
void registerStudent()
{
    Student* s = new Student;
    cout << "Enter Roll Number: ";
    cin >> s->roll;
    int index = hashFunction(s->roll);
    Student* temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->roll == s->roll)
        {
            cout << "Roll Number already exists!\n";
            delete s;
            return;
        }
        temp = temp->hashNext;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Student Name: ";
    getline(cin, s->name);
    cout << "Enter Department: ";
    getline(cin, s->department);
    s->courses = NULL;
    // Insert into Linked List
    s->Next = head;
    head = s;
    // Insert into Hash Table
    s->hashNext = hashTable[index];
    hashTable[index] = s;
    cout << "Student Registered Successfully!\n";
}
// Search Student
void searchStudent()
{
    int roll;
    cout << "Enter Roll Number to search: ";
    cin >> roll;
    int index = hashFunction(roll);
    Student* temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            cout << "\nStudent Found!\n";
            cout << "Roll Number: " << temp->roll << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Department: " << temp->department << endl;
            cout << "Courses: ";
            Course* c = temp->courses;
            if (c == NULL)
                cout << "No courses enrolled";
            while (c != NULL)
            {
                cout << c->name << " ";
                c = c->next;
            }

            cout << endl;
            return;
        }

        temp = temp->hashNext;
    }

    cout << "Student Not Found!\n";
}
// Display All Students
void displayStudents()
{
    Student* temp = head;
    if (temp == NULL)
    {
        cout << "No Student Records Available!\n";
        return;
    }
    cout << "\n--- All Student Records ---\n";
    while (temp != NULL)
    {
        cout << "\nRoll Number: " << temp->roll << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Department: " << temp->department << endl;
        cout << "Courses: ";
        Course* c = temp->courses;
        if (c == NULL)
            cout << "No courses enrolled";
        while (c != NULL)
        {
            cout << c->name << " ";
            c = c->next;
        }
        cout << endl;
        temp = temp->Next;
    }
}
// Update Student
void updateStudent()
{
    int roll;
    cout << "Enter Roll Number to update: ";
    cin >> roll;
    int index = hashFunction(roll);
    Student* temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter New Name: ";
            getline(cin, temp->name);
            cout << "Enter New Department: ";
            getline(cin, temp->department);
            cout << "Student Updated Successfully!\n";
            return;
        }

        temp = temp->hashNext;
    }
    cout << "Student Not Found!\n";
}
// Enroll Student in Course
void enrollCourse()
{
    int roll;
    cout << "Enter Roll Number: ";
    cin >> roll;
    int index = hashFunction(roll);
    Student* temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            Course* c = new Course;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter Course Name: ";
            getline(cin, c->name);
            Course* check = temp->courses;
            while (check != NULL)
            {
                if (check->name == c->name)
                {
                    cout << "Student already enrolled in this course!\n";
                    delete c;
                    return;
                }

                check = check->next;
            }

            c->next = temp->courses;
            temp->courses = c;
            cout << "Course Enrolled Successfully!\n";
            return;
        }

        temp = temp->hashNext;
    }

    cout << "Student Not Found!\n";
}
// Withdraw Student from Course
void withdrawCourse()
{
    int roll;
    cout << "Enter Roll Number: ";
    cin >> roll;
    int index = hashFunction(roll);
    Student* temp = hashTable[index];
    while (temp != NULL)
    {
            if (temp->roll == roll)
        {
            string courseName;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter Course Name to withdraw: ";
            getline(cin, courseName);
            Course* c = temp->courses;
            Course* prev = NULL;
            while (c != NULL)
            {
                if (c->name == courseName)
                {
                    if (prev == NULL)
                        temp->courses = c->next;
                    else
                        prev->next = c->next;
                    delete c;
                    cout << "Course Withdrawn Successfully!\n";
                    return;
                }
                prev = c;
                c = c->next;
            }
            cout << "Course Not Found!\n";
            return;
        }

        temp = temp->hashNext;
    }

    cout << "Student Not Found!\n";
}
// Remove Student Record
void removeStudent()
{
    int roll;
    cout << "Enter Roll Number to remove: ";
    cin >> roll;
    int index = hashFunction(roll);
    Student* temp = hashTable[index];
    Student* prevHash = NULL;
    while (temp != NULL)
        {
        if (temp->roll == roll)
        {
            // Remove from Hash Table
            if (prevHash == NULL)
                hashTable[index] = temp->hashNext;
            else
                prevHash->hashNext = temp->hashNext;
            // Remove from Linked List
            Student* current = head;
            Student* prev = NULL;

            while (current != NULL)
            {
                if (current->roll == roll)
                {
                    if (prev == NULL)
                        head = current->Next;
                    else
                        prev->Next = current->Next;

                    break;
                }

                prev = current;
                current = current->Next;
            }

            // Delete enrolled courses
            Course* c = temp->courses;

            while (c != NULL)
            {
                Course* del = c;
                c = c->next;
                delete del;
            }

           delete temp;

            cout << "Student Record Removed Successfully!\n";
            return;
                    }

        prevHash = temp;
        temp = temp->hashNext;
    }

    cout << "Student Not Found!\n";
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n--- University Student Registration System ---\n";
        cout << "1. Register Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display All Students\n";
        cout << "4. Update Student\n";
        cout << "5. Enroll in Course\n";
        cout << "6. Withdraw from Course\n";
        cout << "7. Remove Student\n";
        cout << "8. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerStudent();
                break;

            case 2:
                searchStudent();
                break;

            case 3:
                displayStudents();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                enrollCourse();
                break;

            case 6:
                withdrawCourse();
                break;

            case 7:
                removeStudent();
                break;

            case 8:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 8);

    return 0;
}
