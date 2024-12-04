import re
import itertools

file = open("input.txt", "r")
data = file.read()
file.close()
# Find all horizontal occurences
hor_norm = re.findall("XMAS", data)
hor_rev = re.findall("SAMX", data)
hor = len(hor_norm) + len(hor_rev)
# Find all vertical occurences
lines = data.split('\n')
ver = 0
for i in range(len(lines) - 3):
    for (a, b, c, d) in zip(lines[i], lines[i + 1], lines[i + 2], lines[i + 3]):
        if a == 'X' and b == 'M' and c == 'A' and d == 'S':
            ver += 1
        elif a == 'S' and b == 'A' and c == 'M' and d == 'X':
            ver += 1
# Find all diagonal occurences
dia = 0
# Diagonal starting from the left
for i in range(len(lines) - 3):
    for (a, b, c, d) in zip(lines[i], lines[i + 1][1:], lines[i + 2][2:], lines[i + 3][3:]):
        if a == 'X' and b == 'M' and c == 'A' and d == 'S':
            dia += 1
        elif a == 'S' and b == 'A' and c == 'M' and d == 'X':
            dia += 1
# Diagonal starting from the right
for i in range(len(lines) - 3):
    for (a, b, c, d) in zip(lines[i][3:], lines[i + 1][2:], lines[i + 2][1:], lines[i + 3]):
        if a == 'X' and b == 'M' and c == 'A' and d == 'S':
            dia += 1
        elif a == 'S' and b == 'A' and c == 'M' and d == 'X':
            dia += 1

print(dia + hor + ver)