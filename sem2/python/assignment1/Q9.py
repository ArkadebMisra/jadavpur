# . Use map and zip to find the element-wise maximum amongst sequences of student list, 
# subject list and marks list

# students = ["arka", "somosree", "sohini", "jaidip", "abu"]
# subject = ["a", "b", "c"]
# subjects = []
# for s in students:
#     # print(subject[:])
#     subjects.append(subject[:])
# print(subjects)
# marks = [[80, 90, 100], [85, 90, 80], [95, 80, 87], [87, 89, 100], [100, 95, 70]]

# print(students)
# print(subjects)
# print(marks)


# def func(ele):
#     n = ele[0]
#     s = ele[1]
#     m = ele[2]
#     highest = max(m)
#     idx=0
#     for i in range(len(m)):
#         if m[i]==highest:
#             idx=i
#             break
#     return n, s[idx], m[idx]
    

# a = map(func,zip(students, subjects, marks))
# for e in a:
#     print(e)

#---------------------------------------------


# Lists of students, subjects, and their marks
s = ["arka", "somosree", "sohini", "jaidip", "abu"]
subjects = ["computer science", "physics", "math"]
marks = [[1, 2, 3, 4, 5], [5, 3, 2, 6, 2], [7, 9, 1, 2, 1]]

# Create a list of students repeated for each subject
students = [s[:] for i in range(len(subjects))]

# Define a function to find the highest 
# mark in each subject and the corresponding student
def func(ele):
    s = ele[0]  # Subject name
    st = ele[1] # List of students
    m = ele[2]  # Marks for the subject
    highest = max(m)  # Find the highest mark
    idx = 0  # Initialize index for the highest mark
    for i in range(len(m)):
        if m[i] == highest:
            # Get the index of the highest mark
            idx = i  
            break
    # Return the subject, student, and highest mark
    return s, st[idx], m[idx]  

# Use map and zip to apply the function 
# to each subject, student list, and marks list
a = map(func, zip(subjects, students, marks))

# Print the results
for e in a:
    print("in ", e[0], " ", e[1], " got highest marks ", e[2])


# s = max([5, 10, 12])
# print(s)




