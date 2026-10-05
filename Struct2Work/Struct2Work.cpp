#include <iostream>
#include <conio.h>
using namespace std;

struct Book
{
    char name[50];
    char author[50];
    char published[50];
    char genre[50];
    int date;
    int price;
};

void ShowBooks(Book books)
{
    cout << "Name : " << books.name << endl;
    cout << "Author : " << books.author << endl;
    cout << "Published by : " << books.published << endl;
    cout << "Genre : " << books.genre << endl;
    cout << "Date : " << books.date << endl;
    cout << "Price : " << books.price << endl << endl;
}

void ShowBooksByAuthor(Book* books, char author[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(books[i].author, author) == 0)
        {
            ShowBooks(books[i]);
        }
    }
}

void ShowBooksByName(Book* books, char name[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(books[i].name, name) == 0)
        {
            ShowBooks(books[i]);
        }
    }
}

void ShowBooksByPublish(Book* books, char publish[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(books[i].published, publish) == 0)
        {
            ShowBooks(books[i]);
        }
    }
}

void ShowBooksByGenre(Book* books, char genre[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(books[i].genre, genre) == 0)
        {
            ShowBooks(books[i]);
        }
    }
}

Book* AddNewBook(Book* library, int& size)
{
    Book* temp = new Book[size + 1];
    for (int i = 0; i < size+1; i++)
    {
        temp[i] = library[i];
        if (i == size)
        {
            cout << "Enter new book's name : ";
            cin >> temp[i].name;
            cout << "Enter new book's author : ";
            cin >> temp[i].author;
            cout << "Enter new book's publisher : ";
            cin >> temp[i].published;
            cout << "Enter new book's genre : ";
            cin >> temp[i].genre;
            cout << "Enter new book's publish date : ";
            cin >> temp[i].date;
            cout << "Enter new book's cost : ";
            cin >> temp[i].price;
            break;
        }
    }
    delete[]library;
    size++;
    return temp;
}

void ChangeData(Book* books, int size)
{
    char bookName[50];
    cout << "Enter book's name: ";
    cin >> bookName;

    int newCost;
    cout << "Enter book's new cost: ";
    cin >> newCost;

    for (int i = 0; i < size; i++)
    {
        if (strcmp(books[i].name, bookName) == 0)
        {
            books[i].price = newCost;
        }
    }
}

Book* DeleteBook(Book* library, int& size)
{
    char bookName[50];
    cout << "Enter book's name to delete : ";
    cin >> bookName;

    int bookIDdeleted;

    Book* temp = new Book[size - 1];
    for (int i = 0; i < size; i++)
    {
        if (strcmp(library[i].name, bookName) == 0)
        {
            bookIDdeleted = i;
        }
    }
    for (int i = 0; i < bookIDdeleted; i++)
    {
        temp[i] = library[i];
    }
    for (int i = bookIDdeleted; i < size; i++)
    {
        temp[i] = library[i];
    }
    delete[]library;
    size--;
    return temp;
}

int main()
{
    int choice;
    char name[50];
    int size = 10;
    Book* library = new Book[size]{
        { "Book","Shakespear","Library","Happy",1001,200 },
        { "1984", "George Orwell", "Secker & Warburg", "Dystopian", 1002, 328 },
        { "To Kill a Mockingbird", "Harper Lee", "J. B. Lippincott", "Fiction", 1003, 281 },
        { "The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "Classic", 1004, 180 },
        { "Pride and Prejudice", "Jane Austen", "T. Egerton", "Romance", 1005, 279 },
        { "The Catcher in the Rye", "J.D. Salinger", "Little, Brown", "Fiction", 1006, 234 },
        { "The Hobbit", "J.R.R. Tolkien", "George Allen & Unwin", "Fantasy", 1007, 310 },
        { "Fahrenheit 451", "Ray Bradbury", "Ballantine Books", "Sci-Fi", 1008, 256 },
        { "Moby-Dick", "Herman Melville", "Harper & Brothers", "Adventure", 1009, 378 },
        { "Brave New World", "Aldous Huxley", "Chatto & Windus", "Dystopian", 1010, 311 }
    };

    do
    {
        system("cls");
        cout << "---------------- Menu -------------------" << endl;
        cout << "Change book(price)           [1]" << endl;
        cout << "Show all books               [2]" << endl;
        cout << "Search by author             [3]" << endl;
        cout << "Search by name               [4]" << endl;
        cout << "Search by published          [5]" << endl;
        cout << "Search by genre              [6]" << endl;
        cout << "Add new book                 [7]" << endl;
        cout << "Delete a book                [8]" << endl;
        cout << "Exit                         [0]" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 0:
            cout << "Goodbye!" << endl;
            break;
        case 1:
            ChangeData(library, size);
            break;
        case 2:
            for (int i = 0; i < size; i++)
            {
                ShowBooks(library[i]);
            }  
            break;
        case 3:
            cout << "Enter author : ";
            cin.getline(name, 50);
            ShowBooksByAuthor(library, name, size);
            break;
        case 4:
            cout << "Enter book's name : ";
            cin.getline(name, 50);
            ShowBooksByName(library, name, size);
            break;
        case 5:
            cout << "Enter book's publisher : ";
            cin.getline(name, 50);
            ShowBooksByPublish(library, name, size);
            break;
        case 6:
            cout << "Enter book's genre : ";
            cin.getline(name, 50);
            ShowBooksByGenre(library, name, size);
            break;
        case 7:
            library = AddNewBook(library, size);
            break;
        case 8:
            library = DeleteBook(library, size);
            break;
        default:
            break;
        }
        if (choice != 0)
        {
            cout << "Enter any key...";
            _getch();
        }
    } while (choice != 0);
    

    delete[]library;
}
