#!/bin/sh
html_prefix="<!doctype html>\\n<html>\\n<head>\\n"
html_suffix="</head>\\n<body>\\n</body>\\n</html>"
head_content=""
ret=`ls *.js`
for arg in $ret
do
    if [ $arg != "browser_test.sh" -a $arg != "prototype-cmp.js" -a $arg != "test.html" ]; then
        head_content+="<script type=\"text/javascript\" src=\"${arg}\"></script>\\n"
    fi
done

html=$html_prefix$head_content$html_suffix
echo $html

