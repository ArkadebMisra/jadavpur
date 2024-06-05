def fibgen(n):
    f = [0, 1]
    for i in range(n):
        if i == 0 or i == 1:
            yield f[i]
        else:
            t = f[0]+f[1]
            f[0], f[1] = f[1], t
            yield t


for f in fibgen(7):
    print(f)