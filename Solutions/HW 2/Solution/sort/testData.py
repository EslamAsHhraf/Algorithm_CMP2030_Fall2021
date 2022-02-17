import sys
import os
if len(sys.argv) < 5:
    raise Exception("too few arguments")
# variables
dataSizes = [1000, 5000, 10000, 50000, 75000, 100000, 500000]
sortingMethods = ['Selection', 'Insertion', 'Merge', 'Quick', 'Hybrid']
inputFile, outFile, runtimeFile, cppOutFile = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4]
outputRuntime = [['size', *sortingMethods, *list(
    map(lambda x: f"{x} Sorted", sortingMethods))]]
print(outputRuntime)
backSlash = '\\'
# logic
ctr = 0
for size in dataSizes:
    outputRuntime.append([])
    ctr += 1
    outputRuntime[ctr].append(size)
    os.system(f"python3 runscript.py {size} {inputFile}")
    for i in range(2):
        methodNum = 0
        for sortingMethod in sortingMethods:
            os.system(
                f".{ backSlash if sys.platform == 'win32' else '/' }{cppOutFile} {methodNum} {outFile if i == 1 else inputFile} {outFile} {runtimeFile}")
            f = open(runtimeFile, "r")
            x = f.read()
            f.close()
            outputRuntime[ctr].append(x)
            print(f"{sortingMethod} {'Sorted' if i == 1 else ''} {size} ==> {x}")
            methodNum += 1

print(outputRuntime)


with open("all_data.txt", "w") as file:
    for row in outputRuntime:
        file.write(("{: >20} " * 11).format(*row).replace("\n", ""))
        file.write("\n")

