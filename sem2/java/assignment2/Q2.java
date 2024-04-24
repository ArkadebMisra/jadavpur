class Address{
    int premissesNo;
    String street;
    String city;
    int pin;
    String state;

    Address(int premissesNo, String street, String city, int pin, String state){
        this.premissesNo = premissesNo;
        this.street = street;
        this.city = city;
        this.pin = pin;
        this.state = state;
    }

    void changePremissesNo(int premissesNo){
        this.premissesNo = premissesNo;
    }

    
    void changeStreet(String street){
        this.street = street;
    }

    
    void changeCity(String city){
        this.city = city;
    }

    
    void changePin(int pin){
        this.pin = pin;
    }

    
    void changeState(int premissesNo){
        this.premissesNo = premissesNo;
    } 
}

class person{
    String name;
    Address address;
    int phoneNo;
    String emailId;
    int studentOrFaculty; //0 if student 1 if faculty;

    int rollNo;
    String course;

    int employeeId;
    String department;
    String specialization;

    person(int studentOrFaculty, String name, int premissesNo, String street, String city, int pin, String state, int phoneNo, String emailId,
            int rollNo, String course){
                this.studentOrFaculty = studentOrFaculty;
                Address a = new Address(premissesNo, street, city, pin, state);
                this.address = a;
                this.name = name;
                this.phoneNo = phoneNo;
                this.emailId = emailId;
                this.rollNo = rollNo;
                this.course = course;
            }

    person(int studentOrFaculty, String name, int premissesNo, String street, String city, int pin, String state, int phoneNo, String emailId,
            int employeeId, String department, String specialization){
                this.studentOrFaculty = studentOrFaculty;
                Address a = new Address(premissesNo, street, city, pin, state);
                this.address = a;
                this.name = name;
                this.phoneNo = phoneNo;
                this.emailId = emailId;
                this.employeeId = employeeId;
                this.department = department;
                this.specialization = specialization;
            }

    void setName(String name){
        this.name = name;
    }

    
    void setPhoneNo(int phoneNo){
        this.phoneNo = phoneNo;
    }

    void setEmailId(String emailId){
        this.emailId = emailId;
    }

    void setRollNo(int rollNo){
        if(this.studentOrFaculty==0){
            this.rollNo = rollNo;
        }else{
            System.out.println("dont have any such attribute!");
        }
    }

    void setCourse(String course){
        if(this.studentOrFaculty==0){
            this.course = course;
        }else{
            System.out.println("dont have any such attribute!");
        }
    }

    void setEmployeeId(int employeeId){
        if(this.studentOrFaculty==1){
            this.employeeId = employeeId;
        }else{
            System.out.println("dont have any such attribute!");
        }
    }
    
    void setDepartment(String department){
        if(this.studentOrFaculty==1){
            this.department = department;
        }else{
            System.out.println("dont have any such attribute!");
        }
    }

    void setSpecialization(String specialization){
        if(this.studentOrFaculty==1){
            this.specialization = specialization;
        }else{
            System.out.println("dont have any such attribute!");
        }
    }

    void setAddress(int premissesNo, String street, String city, int pin, String state){
        Address a = new Address(premissesNo, street, city, pin, state);
        this.address = a;        
    }
}


public class Q2{
    public static void main(){
        person p = new person(0, "Arka", 101, "Uttar Chatra", "North 24 parganas", 743247, "West Bengal", 62955, "arka@gmail.com",
            16, "MCA");
    }
}
