#!/usr/bin/python
import os
import re
from values import values


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

def SetValue(content, lang, filename, current) :
    if values.has_key(filename) :
        if values[filename].has_key(current) :
            if values[filename][current].has_key(lang) :
                for key, value in values[filename][current][lang].items() :
                    content = content.replace('${' + key + '}', value)
        if values[filename].has_key(lang) :
            for key, value in values[filename][lang].items() :
                content = content.replace('${' + key + '}', value)
        if values[filename].has_key(current) :
            for key, value in values[filename][current].items() :
                content = content.replace('${' + key + '}', value)
    content = comp.sub('', content)
    return content

def BuildHTML(path, lang) :
    html = open('html/' + path, 'rb')
    nav = open('nav.html')
    body = html.read()
    html.close()
    body = body.replace('<table>', '<table class="table table-striped table-bordered table-condensed">')
    html = '<!doctype html>\n'
    html += "<html>\n"
    html += '<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">'
    html += '<head lang="ja">\n'
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
    html += SetValue(nav.read(), lang, 'nav.html', os.path.basename(path))
    html += '<div id="wrapper"><div id="inner">'
    current = os.path.basename(path)
    html += SetValue(body, lang, current, current)
    html += '</div></div>'
    html += "</body>"
    html += "</html>"
    fp = open('out_' + lang + '/' + path, 'w+b')
    fp.write(html);
    fp.close();

def Deploy(item_list, lang) :
    if not os.path.isdir('out_' + lang) :
        os.mkdir('out_' + lang)
    for item in item_list :
        if item.endswith('.html') :
            BuildHTML(item, lang)

Deploy(os.listdir('./html'), 'ja')
Deploy(os.listdir('./html'), 'en')
