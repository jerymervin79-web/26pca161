#include <iostream>
#include <string>

using namespace std;

class Book {
    string title;
    string author;

public:

    Book(string t, string a) {
        title = t;
        author = a;
    }


    void display() {
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "-------------------------\n";
    }
};

int main() {

    Book book1("The intermediate chess Basic to Intermediate ", "Jerymervin");
    Book book2("Wings of Fire", "A. P. J. Abdul Kalam");

    cout << "--- Book Details System ---\n";


    cout << "Book 1 Details:\n";
    book1.display();

    cout << "Book 2 Details:\n";
    book2.display();

    return 0;
}
