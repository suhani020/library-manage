#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class LibraryItem {
private:
    string itemName;
    string itemAuthor;
    int publicationYear;
    int itemId;
public:
    LibraryItem(string name, string author, int year, int id) : itemName(name), itemAuthor(author), publicationYear(year), itemId(id) {}

    string getItemName() const { return itemName; }
    string getItemAuthor() const { return itemAuthor; }
    int getPublicationYear() const { return publicationYear; }
    int getItemId() const { return itemId; }

    void displayInfo() const {
        cout << "Name: " << itemName << endl;
        cout << "Author: " << itemAuthor << endl;
        cout << "Year: " << publicationYear << endl;
        cout << "Item ID: " << itemId << endl;
    }
};

class Library {
private:
    vector<LibraryItem> items;
public:
    void addItem(const LibraryItem& item) {
        items.push_back(item);
    }

    void displayItems() const {
        if (items.empty()) {
            cout << "No items in the library." << endl;
        } else {
            cout << "Items in the library:" << endl;
            for (const auto& item : items) {
                item.displayInfo();
                cout << endl;
            }
        }
    }

    void updateItem(int itemId, const LibraryItem& newItem) {
        auto it = find_if(items.begin(), items.end(), [itemId](const LibraryItem& item) {
            return item.getItemId() == itemId;
        });
        if (it != items.end()) {
            *it = newItem;
            cout << "Item updated successfully." << endl;
        } else {
            cout << "Item not found." << endl;
        }
    }

    void removeItem(int itemId) {
        auto it = find_if(items.begin(), items.end(), [itemId](const LibraryItem& item) {
            return item.getItemId() == itemId;
        });
        if (it != items.end()) {
            items.erase(it);
            cout << "Item removed successfully." << endl;
        } else {
            cout << "Item not found." << endl;
        }
    }
};

int main() {
    Library library;

    while (true) {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Display Items" << endl;
        cout << "3. Update Item" << endl;
        cout << "4. Remove Item" << endl;
        cout << "5.
