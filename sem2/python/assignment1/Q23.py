tokens = {}

token=0
with open("test.txt", "r") as f:
    line = f.readline()
    while line != "":
        mapping = []
        line = line[:-1].split(" ")
        for w in line:
            w = w.strip().lower()
            if tokens.get(w, -1)==-1:
                tokens[w] = token
                mapping.append(token)
                token+=1
            else:
                mapping.append(tokens.get(w))

        print(mapping)

        line = f.readline()

print(tokens)


