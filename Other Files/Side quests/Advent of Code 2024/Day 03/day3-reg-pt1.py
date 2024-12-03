import re

def mul(a: int, b: int) -> int:
    return (a * b)
file = open("day3.txt", "r")
data = file.read()
file.close()
new = re.findall("mul[(]\\d*[,]\\d*[)]", data)
for i in range(len(new)):    
    new[i] = new[i].split("mul(")[1]
    new[i] = new[i].split(")")[0]
res = 0
for element in new:
    a = int(element.split(',')[0])
    b = int(element.split(',')[1])
    res += a * b
print(res)