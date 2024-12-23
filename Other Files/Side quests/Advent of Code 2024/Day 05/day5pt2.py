from typing import List

# Function that returns the middle number of the list
def mid_num(updates: List[str]) -> int:
    index = int(len(updates)/2)
    return (int(updates[index]))

# Function that checks if the rules are followed
def check_rules(rules: List[List[str]], updates: List[str]) -> bool:
    for rule in rules:
        if rule[0] in updates and rule[1] in updates:
            if 0 < (updates.index(rule[0]) - updates.index(rule[1])):
                return False
        else:
            continue
    return True

# That swaps around values if the rules are not followed
def fix(rules: List[List[str]], updates: List[str]) -> List[str]:
    check_f = 0
    for rule in rules:
        if rule[0] in updates and rule[1] in updates:
            ind0 = updates.index(rule[0])
            ind1 = updates.index(rule[1])
            if 0 < (ind0 - ind1):
                updates[ind0], updates[ind1] = updates[ind1], updates[ind0]
        else:
            continue
    return (updates)

file = open("data", "r")
data = file.read()
file.close()
# Create a list of rules and updates
rules = data.split("\n\n")[0].split("\n")
updates = data.split("\n\n")[1].split("\n")
for i in range(len(rules)):
    rules[i] = rules[i].split("|")
for i in range(len(updates)):
    updates[i] = updates[i].split(",")

# Check rules for any update; Add mid number to the result if rules are met
res = 0
for update in updates:
    # If the rules are not followed we swap the values around until they are
    if not check_rules(rules, update):
        while (not check_rules(rules, update)):
            fix(rules, update)
        res += mid_num(update)

print(res)
