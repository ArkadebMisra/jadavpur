import re

# m=0

def remove_sp_char(lines):
    s = set('!@#*$%^():;?.\'\"')
    for line in lines:
        l=''
        for c in line:
            if(c not in s):
                l+= c
        print(l)

def remove_single_ch(lines):
    for line in lines:
        ln = line.split(r" ")
        lin=''
        for c in ln:
            if(len(c)!=1):
                lin+= c+' '
        print(lin)

def substitute_multiple_spaces(lines):
    for line in lines:
        ln = re.split('\s+',line)
        lin=''
        for c in ln:
            lin+= c+' '
        print(lin)

def lower(lines):
    l=''
    for line in lines:
        l+= line.lower()
        print(l)

def covert_from_contracted(lines):
    for line in lines:
        line = line.replace('n\'t'," not")
        print(line)
 
if __name__ == "__main__":
    file = open("text.txt", "r")
    lines = file.readlines()

    remove_sp_char(lines)
    remove_single_ch(lines)
    substitute_multiple_spaces(lines)
    lower(lines)
    covert_from_contracted(lines)