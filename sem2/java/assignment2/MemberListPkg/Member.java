package MemberListPkg;

public class Member {
    private String memberId;
    private String name;
    private String dob;
    private int booksIssued;

    public Member(String memberId, String name, String dob, int booksIssued) {
        this.memberId = memberId;
        this.name = name;
        this.dob = dob;
        this.booksIssued = booksIssued;
    }

    // Getters and setters

    public String getMemberId() {
        return memberId;
    }

    public void setMemberId(String memberId) {
        this.memberId = memberId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDob() {
        return dob;
    }

    public void setDob(String dob) {
        this.dob = dob;
    }

    public int getBooksIssued() {
        return booksIssued;
    }

    public void setBooksIssued(int booksIssued) {
        this.booksIssued = booksIssued;
    }
}