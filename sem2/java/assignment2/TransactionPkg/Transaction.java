package TransactionPkg;

public class Transaction {
    private String memberId;
    private String bookId;

    public Transaction(String memberId, String bookId) {
        this.memberId = memberId;
        this.bookId = bookId;
    }

    // Getters and setters

    public String getMemberId() {
        return memberId;
    }

    public void setMemberId(String memberId) {
        this.memberId = memberId;
    }

    public String getBookId() {
        return bookId;
    }

    public void setBookId(String bookId) {
        this.bookId = bookId;
    }
}