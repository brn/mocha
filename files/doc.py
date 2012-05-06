#!/usr/bin/python
import os
import re
import shutil
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

def InsertCss(path) :
    html = '<style>'
    html += open(path).read()
    html += '</style>'
    return html

def InsertInclude(path) :
    return open(path).read()

comp = re.compile(r'\$\{.+?\}')
_script_re = re.compile(r'\$script\{(.+?)\}')
_css_re = re.compile(r'\$css\{(.+?)\}')
_include_re = re.compile(r'\$include\{(.+?)\}')

def ReplaceScript(s) :
    path = s.group(1)
    return InsertScript(path)

def ReplaceCss(s) :
    path = s.group(1)
    return InsertCss(path)

def ReplaceInclude(s) :
    path = s.group(1)
    return InsertInclude(path)

def ProcessDirectives(content) :
    content = _include_re.sub(ReplaceInclude, content)
    content = _script_re.sub(ReplaceScript, content)
    content = _css_re.sub(ReplaceCss, content)
    return content

def ReplaceValues(content, lang, filename, current) :
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
    return content

def SetValue(content, lang, filename, current) :
    content = ProcessDirectives(content)
    content = ReplaceValues(content, lang, filename, current)
    content = ReplaceValues(content, lang, 'common', current)
    content = comp.sub('', content)
    return content

def BuildHTML(path, lang) :
    html = open('template/' + path, 'rb')
    body = html.read()
    html.close()
    current = os.path.basename(path)
    html = SetValue(body, lang, current, current)
    fp = open('../' + lang + '/' + path, 'w+b')
    fp.write(html);
    fp.close();

def Deploy(item_list, lang) :
    if not os.path.isdir('../' + lang) :
        os.mkdir('../' + lang)
    else :
        shutil.rmtree('../' + lang)
    shutil.copytree('images', '../' + lang + '/images')
    for item in item_list :
        if not item.startswith('_') :
            if item.endswith('.html') :
                BuildHTML(item, lang)

Deploy(os.listdir('./template'), 'ja')
Deploy(os.listdir('./template'), 'en')
