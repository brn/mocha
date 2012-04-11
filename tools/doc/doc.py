#!/usr/bin/python
import os
from textile import textile
title =  'mocha ES Next Translator'

def InsertScript(path, *issource) :
    html = '\n<script type="text/javascript">\n'
    html += '//<![CDATA[\n'
    if len(issource) == 0 :
        html += open(path).read()
    else :
        html += path
    html += '//]]>\n'
    html += '</script>'
    return html

def BuildTextile(path) :
    textile_file = open('textiles/' + path, 'rb')
    body = textile(textile_file.read()).replace('<br />', '\n').replace('&#8217;', '\'')
    textile_file.close()
    html = '<?xml version="1.0" encoding="UTF-8"?>\n'
    html += '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml-strict.dtd">\n'
    html += "<html>\n"
    html += '<head xmlns="http://www.w3.org/1999/xhtml" xml:lang="ja" lang="ja">\n'
    html += '<meta http-equiv="Content-Type" content="application/xhtml+xml; charset=UTF-8" />\n'
    html += "<style>\n"
    html += open('shCoreDefault.css').read()
    html += open('css.template').read()
    html += "</style>\n"
    html += InsertScript('shCore.js')
    html += InsertScript('shBrushJScript.js')
    html += InsertScript('SyntaxHighlighter.all();', True)
    html += "</head>\n"
    html += '<body><div id="wrapper">'
    html += '<h1><a href="index.html">' + title + '</a></h1>'
    html += body
    html += '</div>'
    html += "</body>"
    html += "</html>"
    fp = open('out/' + path.replace('.textile', '.html'), 'w+b')
    fp.write(html);
    fp.close();

if not os.path.isdir('out') :
    os.mkdir('out')

item_list = os.listdir('./textiles')
for item in item_list :
    if item.endswith('.textile') :
        BuildTextile(item)

