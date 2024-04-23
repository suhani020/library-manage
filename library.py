books = []

def add_book(title, author):
    books.append({"title": title, "author": author})
    print("Book added successfully.")

def display_books():
    if books:
        print("Books available in the library:")
        for book in books:
            print(f"Title: {book['title']}, Author: {book['author']}")
    else:
        print("No books available in the library.")

def find_book(title):
    for book in books:
        if book['title'] == title:
            return book
    return None

def update_book(title, new_title):
    book = find_book(title)
    if book:
        book['title'] = new_title
        print("Book updated successfully.")
    else:
        print("Book not found.")

def delete_book(title):
    book = find_book(title)
    if book:
        books.remove(book)
        print("Book deleted successfully.")
    else:
        print("Book not found.")

def main():
    while True:
        print("\n1. Add Book")
        print("2. Display Books")
        print("3. Find Book")
        print("4. Update Book")
        print("5. Delete Book")
        print("6. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            title = input("Enter book title: ")
            author = input("Enter book author: ")
            add_book(title, author)
        elif choice == '2':
            display_books()
        elif choice == '3':
            title = input("Enter book title to search: ")
            book = find_book(title)
            if book:
                print("Book found:", book)
            else:
                print("Book not found.")
        elif choice == '4':
            title = input("Enter book title to update: ")
            new_title = input("Enter new title: ")
            update_book(title, new_title)
        elif choice == '5':
            title = input("Enter book title to delete: ")
            delete_book(title)
        elif choice == '6':
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Please try again.")


if _name_ == "_main_":
    main()
