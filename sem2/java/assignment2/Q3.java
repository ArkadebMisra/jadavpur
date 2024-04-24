import BookListPkg.Book;
import BookListPkg.BookList;
import MemberListPkg.Member;
import MemberListPkg.MemberList;
import TransactionPkg.TransactionList;

public class Q3 {
    public static void main(String[] args) {
        // Create instances of BookList, MemberList, and TransactionList
        BookList bookList = new BookList(); // Example capacity
        MemberList memberList = new MemberList(100); // Example capacity
        TransactionList transactionList = new TransactionList(100); // Example capacity

        // Add new books
        Book book1 = new Book("B001", "Java Programming", 10, 10);
        Book book2 = new Book("B002", "Data Structures and Algorithms", 15, 15);
        bookList.addBook(book1);
        bookList.addBook(book2);

        // Add more copies for a book
        bookList.addCopies("B001", 5);

        // Show all book details
        bookList.displayAllBooks();

        // Show details of a book
        bookList.displayBookDetails("B001");

        // Add members
        Member member1 = new Member("M001", "John Doe", "1990-01-01", 0);
        Member member2 = new Member("M002", "Jane Smith", "1995-05-15", 0);
        memberList.addMember(member1);
        memberList.addMember(member2);

        // Show all members
        memberList.displayAllMembers();

        // Show details of a member
        memberList.displayMemberDetails("M001");

        // Issue a book
        issueBook(transactionList, bookList, memberList, "M001", "B001");

        // Return a book
        returnBook(transactionList, bookList, memberList, "M001", "B001");
    }

    private static void issueBook(TransactionList transactionList, BookList bookList, MemberList memberList, String memberId, String bookId) {
        // Implement logic to issue a book
        // Check book validity and availability
        Book book = bookList.findBookById(bookId);
        if (book != null && book.getAvailableCopies() > 0) {
            // Check member validity and eligibility
            Member member = memberList.findMemberById(memberId);
            if (member != null) {
                if (member.getBooksIssued() < memberList.getMaxBooksAllowed()) {
                    // Issue book
                    transactionList.issueBook(memberId, bookId);
                    bookList.decrementAvailableCopies(bookId);
                    memberList.incrementBooksIssued(memberId);
                    System.out.println("Book issued successfully.");
                } else {
                    System.out.println("Member has reached the maximum number of books allowed to be issued.");
                }
            } else {
                System.out.println("Invalid member ID.");
            }
        } else {
            System.out.println("Invalid book ID or no available copies.");
        }
    }

    private static void returnBook(TransactionList transactionList, BookList bookList, MemberList memberList, String memberId, String bookId) {
        // Implement logic to return a book
        // Check the validity of corresponding issue with book id and member id
        boolean found = false;
        for (int i = 0; i < transactionList.getSize(); i++) {
            if (transactionList.getTransaction(i).getMemberId().equals(memberId) && transactionList.getTransaction(i).getBookId().equals(bookId)) {
                found = true;
                // Return book
                transactionList.returnBook(memberId, bookId);
                bookList.incrementAvailableCopies(bookId);
                memberList.decrementBooksIssued(memberId);
                System.out.println("Book returned successfully.");
                break;
            }
        }
        if (!found) {
            System.out.println("No matching transaction found for book with ID " + bookId + " and member with ID " + memberId);
        }
    }
}
