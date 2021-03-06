import os
initjs = open('src/mocha/v8wrap/init.js', "rb").read()
driver = open('mocha/test_driver.js').read()
def runtimeModuel(name,string):
    return 'const char ' + name + "[] = {" + string + "};\n"

def getascii(name,source):
    list = ""
    for val in source:
        list += str(ord(val))
        list += ','
    list = runtimeModuel(name,list + "0")
    return list
result = getascii('initjs',initjs)
result = "#ifndef mocha_v8wrap_init_js_\n#include<mocha/roaster/runtime/runtime.h>\nnamespace mocha{namespace packed_script {\n" + result
result += getascii('test_driver', driver)
result += "}}\n#endif"
fw = open('src/mocha/v8wrap/initjs.h' , "w+b")
fw.write(result)
fw.close()
