mod_lines = []

with open("test1.txt", "r") as f:
    lines = f.readlines()
    m = 0
    for line in lines:
        m = max(m, len(line[:-1]))

    for line in lines:
        if(m>len(line[:-1])):
            m_line = line[:-1] + ("."*(m-len(line[:-1])))
            mod_lines.append(m_line)
        else:
            mod_lines.append(line[:-1])

    

with open("test2.text", "w") as f:
    for l in mod_lines:
        f.write(l+"\n")


