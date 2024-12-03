def mul(a: int, b: int) -> int:
    return (a * b)

def valid(data: str) -> bool:
    commas = 0
    for char in data:
        if char.isdigit() == False and char != ',':
            return False
        if char == ',':
            commas += 1
    if commas != 1:
        return False
    if not data[0].isdigit() and not data[-1].isdigit():
        return False
    return True

# get the data
file = open("day3.txt", "r")
data = file.read()
file.close()
# splitting the data at every 'do()'
trimd = data.split("do()")
# getting rid of everything after a 'don't()'
for i in range(len(trimd)):
    trimd[i] = trimd[i].split('don\'t()')[0]

# create a new string to be processed like in part 1
new_str = ""
for element in trimd:
    new_str += element

# split the data into a list everytime "mul" is found
new = new_str.split("mul")
# get rid of elements that don't start with a '(' after the mul
# get rif of elements that do not containt a ')' or ','
for element in new:
    if element[0] != '(':
        new.remove(element)
    if ')' not in element:
        if element in new:
            new.remove(element)
    if ',' not in element:
        if element in new:
            new.remove(element)
# get rid of every thing after ')' and the '('
for i in range(len(new)):
    new[i] = new[i].split(')')[0]
    new[i] = new[i].split('(')[1]
# remove everything that contains invalid chars, not exactly 1 comma and doesn't end and start with a digit
for element in new:
    if not valid(element):
        new.remove(element)
# splitting by the comma and multiplying both values -> adding it to the result
res = 0
for element in new:
    a = int(element.split(',')[0])
    b = int(element.split(',')[1])
    res += a * b

print(res)
# print(new)
