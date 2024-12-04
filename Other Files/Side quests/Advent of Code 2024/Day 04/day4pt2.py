import re
import itertools

file = open("input.txt", "r")
data = file.read()
file.close()
lines = data.split('\n')
counter = 0
# Diagonal starting from the left
for i in range(len(lines) - 2):
    for (a, b, c, d, e) in zip(lines[i], lines[i + 2], lines[i + 2][2:], lines[i][2:], lines[i + 1][1:]):
        if a == 'M' and b == 'M' and c == 'S' and d == 'S' and e == 'A':
            counter += 1
        elif a == 'S' and b == 'S' and c == 'M' and d == 'M' and e == 'A':
            counter += 1
        elif a == 'S' and b == 'M' and c == 'M' and d == 'S' and e == 'A':
            counter += 1
        elif a == 'M' and b == 'S' and c == 'S' and d == 'M' and e == 'A':
            counter += 1
print(counter)