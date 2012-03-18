runtimejs = open('mocha/module/runtime/mocha_runtime.js', "rb").read()
iteratorjs = open('mocha/module/iterators.js', "rb").read()
def runtimeModuel(name,string):
    return 'const char ' + name + "[] = {" + string + "};\n"

def getascii(name,source):
    list = ""
    for val in source:
        list += str(ord(val))
        list += ','
    list = runtimeModuel(name,list + "0")
    return list

def buildRuntimelist(runtimeList):
    result = ""
    for val in runtimeList:
        result += '  map_.insert(RuntimePair(' + '"' + val + '",' + val + "));\n"
    return "void Runtime::BuildSource() {\n" + result + "}\n"

result = getascii('runtime',runtimejs)
result += getascii('iterators',iteratorjs)
result = "#include<mocha/roaster/runtime/runtime.h>\nnamespace mocha{\nnamespace runtime{\n" + result
result += buildRuntimelist(["runtime","iterators"])
result += "Runtime::RuntimeMap Runtime::map_;"
result += "}}"

fw = open('src/mocha/roaster/runtime/runtime.cc' , "w+b")
fw.write(result)
fw.close()
