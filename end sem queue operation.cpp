#include <iostream>
#define MAX 100
using namespace std;

class LibraryQueue {
    int queue[MAX];
    int front, rear;

public:
    LibraryQueue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        if (front == -1 || front > rear)
            return true;
        return false;
    }
    bool isFull() {
        if (rear == MAX - 1)
            return true;
        return false;
    }
    void addStudent(int studentID) {
        if (isFull()) {
            cout << "Queue is Full! Cannot add more students.\n";
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = studentID;
        cout << "Student ID " << studentID << " added to the queue.\n";
    }
    void serveStudent() {
        if (isEmpty()) {
            cout << "Queue is Empty! No students waiting to be served.\n";
            return;
        }
        cout << "Student ID " << queue[front] << " has been served and removed from the queue.\n";
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty! No students waiting.\n";
            return;
        }
        cout << "Current Students waiting in queue (IDs): ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << "\n";
    }
};
int main() {
    LibraryQueue q;
    int choice, id;

    do {
        cout << "\n Library Counter   \n";
        cout << "1. Add Student\n";
        cout << "2. Serve Student\n";
        cout << "3. Display Waiting Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Student ID: ";
                cin >> id;
                q.addStudent(id);
                break;
            case 2:
                q.serveStudent();
                break;
            case 3:
                q.displayQueue();

                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
