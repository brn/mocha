#!/usr/bin/python
import textile
file = open('../README.textile').read()
print textile
text = textile.textile(file)
print text
