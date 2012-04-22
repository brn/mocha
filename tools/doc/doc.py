#!/usr/bin/python
import os
import re
title =  'mocha ES Next Translator'

active_class = 'class="active"'

values = {
'index.html' : {
        'active_index' : active_class
        },
'first_step_guide.html' : {
        'active_first_step' : active_class
        },
'es_next_detail.html' : {
        'active_grammar' : active_class
        },
'api_guide.html' : {
        'active_api' : active_class
        }
}

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

comp = re.compile(r'\$\{.+?\}')

def SetNav(current) :
    nav = open('nav.html')
    content = nav.read()
    if values.has_key(current) :
        for key, value in values[current].items() :
            content = content.replace('${' + key + '}', value)
    content = comp.sub('', content)
    return content

def BuildHTML(path) :
    html = open('html/' + path, 'rb')
    body = html.read()
    html.close()
    body = body.replace('<table>', '<table class="table table-striped table-bordered table-condensed">')
    html = '<?xml version="1.0" encoding="UTF-8"?>\n'
    html += '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml-strict.dtd">\n'
    html += "<html>\n"
    html += '<head xmlns="http://www.w3.org/1999/xhtml" xml:lang="ja" lang="ja">\n'
    html += '<meta http-equiv="Content-Type" content="application/xhtml+xml; charset=UTF-8" />\n'
    html += "<style>\n"
    html += open('bootstrap/css/prettify.css').read()
    html += open('bootstrap/css/bootstrap.min.css').read().replace('../img', 'img')
    html += open('css.template').read()
    html += "</style>\n"
    html += InsertScript('bootstrap/js/jquery.js')
    html += InsertScript('bootstrap/js/prettify.js')
    html += InsertScript('bootstrap/js/bootstrap.min.js').replace('../img', 'img')
    html += "</head>\n"
    html += '<body onload="prettyPrint()">'
    html += SetNav(os.path.basename(path))
    html += '<div id="wrapper"><div id="inner">'
    html += body
    html += '</div></div>'
    html += "</body>"
    html += "</html>"
    fp = open('out/' + path, 'w+b')
    fp.write(html);
    fp.close();

if not os.path.isdir('out') :
    os.mkdir('out')

item_list = os.listdir('./html')
for item in item_list :
    if item.endswith('.html') :
        BuildHTML(item)

