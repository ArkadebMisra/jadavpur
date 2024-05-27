n = 10
a = [(a, b, c) for a in range(n) for b in range(a) for c in range(a+b)]
b = filter(lambda x: x[0]**2+x[1]**2==x[2]**2, a)
for e in b:
    if(e[0]**2+e[1]**2!=e[2]**2):
        print("wrong")
        break
    print(e)