package BookListPkg;

// import BookListPkg.Book;

public class BookList {
    private Book[] books;
    private int size;
    private final int MAX_BOOKS = 100; // Example: Maximum number of books allowed in the list

    public BookList() {
        books = new Book[MAX_BOOKS];
        size = 0;
    }

    // Add new book
    public void addBook(Book book) {
        if (size < MAX_BOOKS) {
            books[size++] = book;
            System.out.println("Book added successfully.");
        } else {
            System.out.println("Cannot add more books. Book list is full.");
        }
    }

    // Add more copies for a book
    public void addCopies(String bookId, int copies) {
        for (int i = 0; i < size; i++) {
            if (books[i].getBookId().equals(bookId)) {
                books[i].setTotalCopies(books[i].getTotalCopies() + copies);
                books[i].setAvailableCopies(books[i].getAvailableCopies() + copies);
                System.out.println("Copies added successfully.");
                return;
            }
        }
        System.out.println("Book with ID " + bookId + " not found.");
    }

    // Show all book details
    public void displayAllBooks() {
        if (size == 0) {
            System.out.println("No books available in the list.");
        } else {
            System.out.println("All Books:");
            for (int i = 0; i < size; i++) {
                System.out.println("Book ID: " + books[i].getBookId());
                System.out.println("Title: " + books[i].getTitle());
                System.out.println("Total Copies: " + books[i].getTotalCopies());
                System.out.println("Available Copies: " + books[i].getAvailableCopies());
                System.out.println("-----------------------------");
            }
        }
    }

    // Show details of a book
    public void displayBookDetails(String bookId) {
        for (int i = 0; i < size; i++) {
            if (books[i].getBookId().equals(bookId)) {
                System.out.println("Book ID: " + books[i].getBookId());
                System.out.println("Title: " + books[i].getTitle());
                System.out.println("Total Copies: " + books[i].getTotalCopies());
                System.out.println("Available Copies: " + books[i].getAvailableCopies());
                return;
            }
        }
        System.out.println("Book with ID " + bookId + " not found.");
    }

    public Book findBookById(String bookId) {
        for (int i = 0; i < size; i++) {
            if (books[i].getBookId().equals(bookId)) {
                return books[i];
            }
        }
        return null; // Book not found
    }

    public void decrementAvailableCopies(String bookId) {
        for (int i = 0; i < size; i++) {
            if (books[i].getBookId().equals(bookId)) {
                books[i].setAvailableCopies(books[i].getAvailableCopies() - 1);
                break;
            }
        }
    }

    public void incrementAvailableCopies(String bookId) {
        for (int i = 0; i < size; i++) {
            if (books[i].getBookId().equals(bookId)) {
                books[i].setAvailableCopies(books[i].getAvailableCopies() + 1);
                break;
            }
        }
    }
}

