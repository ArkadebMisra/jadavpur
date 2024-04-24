package TransactionPkg;


public class TransactionList {
    private Transaction[] transactions;
    private int size;
    private final int MAX_TRANSACTIONS = 100; // Example: Maximum number of transactions allowed in the list

    public TransactionList(int capacity) {
        transactions = new Transaction[capacity];
        size = 0;
    }

    // Issue a book
    public void issueBook(String memberId, String bookId) {
        if (size < MAX_TRANSACTIONS) {
            transactions[size++] = new Transaction(memberId, bookId);
            System.out.println("Book issued successfully.");
        } else {
            System.out.println("Cannot issue more books. Transaction list is full.");
        }
    }

    // Return a book
    public void returnBook(String memberId, String bookId) {
        for (int i = 0; i < size; i++) {
            if (transactions[i].getMemberId().equals(memberId) && transactions[i].getBookId().equals(bookId)) {
                transactions[i].setMemberId("xxxx"); // Marking member id as 'xxxx'
                System.out.println("Book returned successfully.");
                return;
            }
        }
        System.out.println("No matching transaction found for book with ID " + bookId + " and member with ID " + memberId);
    }

    public int getSize() {
        return size;
    }

    public Transaction getTransaction(int index) {
        if (index >= 0 && index < size) {
            return transactions[index];
        }
        return null;
    }
}

