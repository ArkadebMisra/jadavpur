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


s = ["arka", "somosree", "sohini", "jaidip", "abu"]
subjects = ["comp", "phy", "math"]
marks = [[1, 2, 3, 4, 5], [5, 3, 2, 6, 2], [7, 9, 1, 2, 1]]
# subjects = [sub[:] for i in range(len(sub))]
students = [s[:] for i in range(len(subjects))]
# print(subjects)





def func(ele):
    s = ele[0]
    st = ele[1]
    m = ele[2]
    highest = max(m)
    idx=0
    for i in range(len(m)):
        if m[i]==highest:
            idx=i
            break
    return s, st[idx], m[idx]
    

a = map(func, zip(subjects, students, marks))
for e in a:
    print(e)

# s = max([5, 10, 12])
# print(s)




