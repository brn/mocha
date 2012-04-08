/**
 * Invisible.js
 *
 * Requires:
 *   - jquery          http://jquery.com/
 *   - jquery.history  http://tkyk.github.com/jquery-history-plugin/
 *   - jarty           https://github.com/kotas/jarty
 *
 * Author: Kenji OTA (LIVEOUT.Inc)
 *
 * License: MIT License
 *
 * Description:
 *   'Invisible.js' is javascript document framework.
 *   - document auto loading (url anchor or html attribute)
 *   - switching parser (Markdown, Textile, Wiki, Json, Html)
 *   - dynamically switching between documents (browser back support)
 *   - attach jarty template engine (Smarty like language)
 *
 *   inspire plugin
 *   - jquery.markdown.js  http://plugins.jquery.com/project/markdown
 *
 *   include parser (data-format)
 *   - Markdown http://www.attacklab.net/
 *   - Textile  http://www.ben-daglish.net/textile.shtml
 *   - Wiki     http://remysharp.com/2008/04/01/wiki-to-html-using-javascript/
 *   - Json     http://www.kawa.net/works/js/jkl/dumper.html
 *
 *   include library
 *   - parseUri http://blog.stevenlevithan.com/archives/parseuri
 *
 */
/*
 * The MIT License
 * 
 * Copyright (c) 2011 LIVEOUT, Inc. <info@liveout.co.jp>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
*/

(function($) {

    $(function() {
        var default_name = 'default.txt';
        var default_ext = '.txt';
        var default_format = 'auto';
        var base_path = './';
        var href = window.location.href;
        var purl = parseUri(href);
        var base_title = document.title;
        if (purl.path.match(/(\.html\/)$/)) {
            var hrefs = purl.path.split('/');
            hrefs.pop();
            hrefs.pop();
            base_path = hrefs.join('/')+'/';
        }
        function getUrlVars() {
            var vars = [], hash;
            var hashes = window.location.href.slice(window.location.href.indexOf('?') + 1).split('&');
            for (var i=0; i<hashes.length; i++) {
                hash = hashes[i].split('=');
                vars.push(hash[0]);
                vars[hash[0]] = hash[1];
            }
            return vars;
        }
        function contentFileName(file_name) {
            var url_vars = getUrlVars();
            if (!file_name) {
                file_name = (purl['anchor']?purl['anchor']:'');
            }
            if (!file_name) {
                file_name = (url_vars['f']?url_vars['f']:'');
            }
            if (file_name.substr(file_name.length-1,1)=='/') {
                //file_name+=default_name;
                file_name=file_name.substr(0,file_name.length-1);
            }
            if (!file_name) {
                file_name = default_name;
            }
            return file_name;
        }
        function checkExt(file_name) {
            if (file_name.indexOf('.')<0) {
                file_name+=default_ext;
            }
            return file_name;
        }
        var chenge_title = function(){
            var t = $(this).text();
            var title = base_title;
            if (t) {
                var tname = t.split('\n')[0];
                if (title) {
                    title = tname + ' | ' + title;
                } else {
                    title = tname;
                }
            }
            document.title = title;
        };
        var search_content = function(el){
            $('*[data-file], .importdoc', $(el)).each(function(){
                if ($(this).attr('id') == 'content') {
                    return;
                }
                var file_name = $(this).attr('data-file');
                if (!file_name) {
                    var file_name = $(this).attr('id');
                }
                if (file_name) {
                    convert_content($(this), file_name);
                }
            });
        };
        var convert_content = function(el, file_name) {
            var $this = $(el);
            var format = $this.attr('data-format');
            var fnames = file_name.split('|');
            if (fnames.length > 1) {
                format = fnames[1];
                file_name = fnames[0];
            }
            if (!format) {
                format = default_format;
            }
            format = format.toLowerCase();
            if (format == 'auto') {
                var exts = checkExt(file_name).match(/.*\.(.*)$/);
                if (exts) {
                    var ext = exts[1];
                    if (format_ext[ext]) {
                        format = format_ext[ext];
                    }
                }
            }
            var content_refresh = function(){
                $this.unbind('render.invisible', content_refresh);
                $('a[href^=#]', $this).click(function(){
                    $.history.load($(this).attr('href').substr(1));
                    return false;
                });
                $('a[href^="http://"], a[href^="https://"]', $this).each(function(){
                	$(this).attr('target', '_blank');
                });
                search_content($this);
            };
            $this.bind('render.invisible',content_refresh);
            $this.invisible(format, base_path, checkExt(file_name));
        };
        search_content($('body'));
        var load_content = function(file_name) {
            var content_div = $('#content');
            content_div.bind('render.invisible', chenge_title);
            if (!file_name && content_div.attr('data-file')) {
                file_name = content_div.attr('data-file');
            }
            convert_content(content_div, contentFileName(file_name));
        };
        $.history.init(load_content);
    });

    /**
     * Plugin: jquery.markdown.js
     *
     * Requires: jquery.js and showdown.js
     *
     * Author: Frank Hellwig
     */

    /**
     * Resolves the path against the base and loads the Markdown document from
     * the resolved location. The Markdown document is converted to HTML using
     * the Showdown converter. On success, all non-absolute <a href="ref"> and
     * <img src="ref"> references are resolved against the path and then again
     * against the base. This allows for page-relative references in links and
     * images independent of the base directory containing the documents.
     */
    $.fn.invisible = function(format, base, path) {
        if (path) {
            path = makeRelative(path);
        }
        if (!format) {
            format = 'markdown';
        }
        var url = resolve(base, path);
        var $this = this;
        var useTemplateEngine = (window['Jarty'] != undefined);
        var json_name = $this.attr('data-json');
        var json_data = {};
        var get_template = function(){
	        $.ajax({
	            url: url,
	            cache: false,
	            type: 'GET',
	            dataType: 'text',
	            beforeSend: forceTextResponse,
	            success: function(text, textStatus, xhr) {
	                var original_text = text
	                if (useTemplateEngine) {
	                    text = Jarty.eval(text, json_data);
	                }
	                var html = convert(format, base, path, text, url);
	                html = removeResolvedSuffixes(html);
	                $this.each(function() {
	                    var tagName = this.tagName.toLowerCase();
	                    var $this= $(this);
	                    if (tagName === 'pre') {
	                        $this.text(html);
	                    } else {
	                        $this.html(html);
	                    }
	                    if ($this.attr('id') == 'content') {
	                        $('#source_content').text(original_text);
	                    }
	                    $this.trigger('render.invisible', xhr);
	                });
	            },
	            error: function(xhr, textStatus, errorThrown) {
	                $this.text(url + ' (' + xhr.status + ' ' + xhr.statusText + ')');
	                $this.trigger('render.invisible', xhr);
	            }
	        });
        };
        if (useTemplateEngine && json_name) {
        	var json_url = resolve(base, json_name);
	        $.ajax({
	            url: json_url,
	            cache: false,
	            type: 'GET',
	            dataType: 'json',
	            success: function(json, textStatus, xhr) {
	            	json_data = json;
	            	get_template();
	            },
	            error: function(xhr, textStatus, errorThrown) {
	                $this.text(json_url + ' (' + xhr.status + ' ' + xhr.statusText + ')');
	                $this.trigger('render.invisible', xhr);
	            }
	        });
        } else {
        	get_template();
        }
        return this;
    };

    /**
     * Firefox tries parsing the AJAX response as XML eventhough the dataType
     * is specified as 'text' and then indicates a syntax error because
     * markdown text is not XML. This function makes Firefox interpret the
     * response as text. Credit: <http://stackoverflow.com/questions/335409/
     * jquery-getjson-firefox-3-syntax-error-undefined/633031#633031>
     */
    function forceTextResponse(xhr) {
        if (xhr.overrideMimeType) {
            xhr.overrideMimeType("text/plain");
        }
    }

    //------------------------------------------------------------------------
    // Basic design decision: we convert to HTML first and then resolve
    // references. This allows the Showdown converter to do the heavy lifting
    // of determining what link and image references are real and which ones
    // are in code blocks. If we performed a global search-and-resolve for
    // [text](link) references we would also modify references in code blocks.
    //------------------------------------------------------------------------

    /**
     * Performs the transclusion, conversion, and reference resolution. Note
     * that we replace transclusions before converting to HTML. This is to
     * avoid stand-alone {{ref}} transclude tags from becoming <p>{{ref}}</p>
     * elements only to have the transclusion tag be replaced by a converted
     * Markdown document that would now be within <p> or some other block tag.
     */
    function convert(format, base, path, text, stack) {
        text = replaceTransclusions(format, base, path, text, stack);
        if (converter[format]) {
            text = converter[format].makeHtml(text);
        }
        text = resolveReferences(base, path, text);
        return text;
    }

    //------------------------------------------------------------------------
    // The following creates a TextBuffer class which is critical to properly
    // handling transclusions. The idea is that you always want to be replacing
    // tags *after* the last replacement. Otherwise, you end up matching tags
    // that were created by transclusions and not the tags that were found in
    // the original text.
    //------------------------------------------------------------------------

    /**
     * Creates a new TextBuffer object initialized with the specified string.
     */
    function TextBuffer(s) {
        // The internal text buffer (an array of string segments).
        this._buf = [s];
    }

    /**
     * Replaces the first occurance of match <m> with replacement <r>. The
     * search for <m> starts after any previous replacements were performed.
     * Returns true if the match was found, false if not.
     */
    TextBuffer.prototype.replace = function(m, r) {
        var cur = this._buf.length - 1; // last index in buffer
        var tmp = this._buf[cur]; // last string in buffer
        var i = tmp.indexOf(m); // find the match in the last string
        if (i < 0) {
            return false; // not found - do nothing and return false
        }
        this._buf[cur++] = tmp.substring(0, i);
        this._buf[cur++] = r;
        this._buf[cur] = tmp.substr(i + m.length);
        return true;
    };

    /**
     * Returns the string representation of this text buffer.
     */
    TextBuffer.prototype.toString = function() {
        return this._buf.join('');
    };

    //------------------------------------------------------------------------
    // The following functions handle transclusions. There are three types of
    // transclusions. Document transclusions, written as {{ref}}, recursively
    // replace the specified tag by converting the specified reference as a
    // Markdown document. Raw transclusions, written as {{!ref}}, simply
    // replace the specified tag with the file specified by the reference.
    // Example transclusions, written as {{%ref}}, are for writing about
    // transclusions. The % is removed and the tag is left in place.
    //
    // The resource specified by the tranclusion tag is read synchronously. Not
    // doing this would be a housekeeping challenge. Since transclusions are
    // performed from an asynchronous call (the original Markdown document
    // access), the user thread in the browser is not blocked.
    //------------------------------------------------------------------------

    // The following regular expressions use the default greedy evaluation and
    // match transclusion strings that do not include curly braces. This is
    // more efficient then using the reluctant quantifier. For further details,
    // see <http://blog.stevenlevithan.com/archives/greedy-lazy-performance>.

    // Finds all transclusion tags enclosed in curly braces.
    // They look like this: {{path}}, {{%path}}, or {{!path}}.
    var TRANSCLUDE_TAGS = /{{[%!]?[^{}]*}}/g;

    // Gets the transclusion reference between the curly braces.
    var TRANSCLUDE_REF = /{{([^{}]+)}}/;

    /**
     * Recursively handles transclusions by finding all {{<ref>}} tags and
     * replacing the tag with the text. Here's the resolution logic:
     *
     * base: content/
     * path: tutorial/javascript.txt
     *  tag: {{example.txt}} (in javascript.txt)
     *  ref: tutorial/example.txt
     *  url: content/tutorial/example.txt
     */
    function replaceTransclusions(format, base, path, text, urls) {

        var tags = text.match(TRANSCLUDE_TAGS);

        if (tags === null || tags.length === 0) {
            return text; // done - no more tags found
        }

        var buf = new TextBuffer(text);
        var n = tags.length;

        for (var i = 0; i < n; i++) {
            var tag = tags[i];
            var ref = tag.match(TRANSCLUDE_REF)[1]; // gets <ref> from {{<ref>}}

            if (ref.charAt(0) === '%') { // example transclusion
                buf.replace(tag, '{{' + ref.substr(1) + '}}');
                continue;
            }

            var raw = ref.charAt(0) === '!'; // raw text transclusion

            if (raw) {
                ref = ref.substr(1); // use the part after the !
            }

            // Resolve the reference against the page and the base.
            ref = resolve(path, ref);
            ref = makeRelative(ref);
            var url = resolve(base, ref);

            // Have we seen this URL before? If so, then it is a recursive
            // transclusion. We only check this if it is not a raw transclusion
            // since raw transclusions are not transitively transcluded.
            if (!raw && urls.indexOf(url) >= 0) {
                buf.replace(tag, 'RECURSIVE TRANSCLUSION: ' + tag);
                continue;
            }

            var tmp = getTranscludedText(url);

            if (!tmp) {
                buf.replace(tag, 'INVALID TRANSCLUSION: ' + tag);
                continue;
            }

            // Performe transitive transclusion via recursion. We add the URL
            // of the transcluded document to the URLs we've already seen.
            if (!raw) {
                var tmp = convert(format, base, ref, tmp, urls + url);
            }

            buf.replace(tag, tmp);
        }
        return buf.toString();
    }

    /**
     * Gets transcluded text from the specified URL. This is a synchronous call
     * but it is being called from an asynchronous handler.
     */
    function getTranscludedText(url) {
        var retval = null;
        $.ajax({
            url: url,
            async: false,
            cache: false,
            type: "GET",
            dataType: "text",
            beforeSend: forceTextResponse,
            success: function(text, textStatus, xhr) {
                retval = $.trim(text);
            }
        });
        return retval;
    }

    //------------------------------------------------------------------------
    // The following functions resolve references with respect to a base
    // directory and the document path. This allows for absolute references
    // (references that start with a slash) in Markdown documents that are
    // resolved against a base directory instead of the site root.
    //------------------------------------------------------------------------

    /**
     * Returns the result of resolving the specified reference against the
     * specified base and path.
     */
    function resolveReference(base, path, ref) {
        // Don't modify absolute links.
        if (isAbsolute(ref)) {
            return ref;
        }
        ref = resolve(path, ref);
        ref = makeRelative(ref);
        ref = resolve(base, ref);
        return ref;
    }

    /**
     * Resolves link and image references in the specified text. The tags have
     * the '_resolved' suffix appended to them so that they are not modified
     * multiple times in transclusions. (References in the referring document
     * are modified after the referenced document has been transcluded.) These
     * '_resolved' suffixes are removed before updating the matched set.
     */
    function resolveReferences(base, path, text) {
        text = text.replace(/<a\shref="([^"]+)/g, function(s, href) {
            return '<a_resolved href="' + resolveReference(base, path, href);
        });
        text = text.replace(/<img\ssrc="([^"]+)/g, function(s, src) {
            return '<img_resolved src="' + resolveReference(base, path, src);
        });
        return text;
    }

    /**
     * Removes the '_resolved' suffixes from link and image tags that were
     * added to resolved references.
     */
    function removeResolvedSuffixes(text) {
        text = text.replace(/<a_resolved /g, '<a ');
        text = text.replace(/<img_resolved /g, '<img ');
        return text;
    }

    //------------------------------------------------------------------------
    // Functions that check, modify, and resolve URIs and paths.
    //------------------------------------------------------------------------

    var ABSOLUTE_URI = /^[a-zA-Z][a-zA-Z\d\+\-\.]*:/;

    var ENTITIES_URI = /&#/;

    var ANCHOR_URI = /^#/;

    /**
     * Returns true if the specified value is non-null and begins with a scheme
     * (e.g., http:) or looks like an mangled email address (with entities).
     */
    function isAbsolute(uri) {
        return uri && (ABSOLUTE_URI.test(uri) || ENTITIES_URI.test(uri) || ANCHOR_URI.test(uri));
        //return true;
    }

    /**
     * Returns a relative version of the specified path by removing all leading
     * slashes.
     */
    function makeRelative(path) {
        if (!path) {
            return '';
        }
        var a = path.match(/^\/*(.*)/);
        return a[1];
    }

    /**
     * Resolves a path against a base path (RFC 3986 5.2.2). The
     * algorithm used is essentially the one specified in the RFC
     * beginning with the 'if (R.path == "") then' statement except
     * that it does not pay attention to any query components.
     */
    function resolve(base, path) {
        var resolvedPath;
        if (!path) {
            resolvedPath = base;
        } else if (path.charAt(0) === '/') {
            resolvedPath =  removeDotSegments(path);
        } else {
            resolvedPath = mergePaths(base, path);
            //resolvedPath = removeDotSegments(resolvedPath);
        }
        return resolvedPath;
    }

    /**
     * Merges a base path and a path (RFC 3986 5.2.3).
     */
    function mergePaths(base, path) {
        // Handle null or undefined arguments.
        if (base == null) {
            base = '';
        }
        if (path == null) {
            path = '';
        }
        // Get everything up to and including the last slash. The following
        // also handles the case when no slash is in the base. (The index will
        // be -1, which, after adding one, will result in an empty substring.)
        base = base.substring(0, base.lastIndexOf('/') + 1);
        // Merge the base and the path.
        return base + path;
    }

    /**
     * Handles . and .. segments in the specified path (RFC 3986 5.2.4).
     */
    function removeDotSegments(path) {
        var ib = path.split(/\/+/); // input buffer (array of segments)
        var ob = []; // output buffer
        var n = ib.length;
        for (var i = 0; i < n; i++) {
            var s = ib[i];
            if (s === '..') {
                // preserve leading slash (ob[0] is empty == false)
                if ((ob.length > 1) || (ob.length > 0 && ob[0])) {
                    ob.pop();
                }
            } else if (s !== '.') {
                ob.push(s);
            }
        }
        return ob.join('/');
    }


	// parseUri 1.2.2
	// (c) Steven Levithan <stevenlevithan.com>
	// MIT License

	function parseUri (str) {
		var	o   = parseUri.options,
			m   = o.parser[o.strictMode ? "strict" : "loose"].exec(str),
			uri = {},
			i   = 14;

		while (i--) uri[o.key[i]] = m[i] || "";

		uri[o.q.name] = {};
		uri[o.key[12]].replace(o.q.parser, function ($0, $1, $2) {
			if ($1) uri[o.q.name][$1] = $2;
		});

		return uri;
	};

	parseUri.options = {
		strictMode: false,
		key: ["source","protocol","authority","userInfo","user","password","host","port","relative","path","directory","file","query","anchor"],
		q:   {
			name:   "queryKey",
			parser: /(?:^|&)([^&=]*)=?([^&]*)/g
		},
		parser: {
			strict: /^(?:([^:\/?#]+):)?(?:\/\/((?:(([^:@]*)(?::([^:@]*))?)?@)?([^:\/?#]*)(?::(\d*))?))?((((?:[^?#\/]*\/)*)([^?#]*))(?:\?([^#]*))?(?:#(.*))?)/,
			loose:  /^(?:(?![^:@]+:[^:@\/]*@)([^:\/?#.]+):)?(?:\/\/)?((?:(([^:@]*)(?::([^:@]*))?)?@)?([^:\/?#]*)(?::(\d*))?)(((\/(?:[^?#](?![^?#\/]*\.[^?#\/.]+(?:[?#]|$)))*\/?)?([^?#\/]*))(?:\?([^#]*))?(?:#(.*))?)/
		}
	};



/*
   A A L        Source code at:
   T C A   <http://www.attacklab.net/>
   T K B
*/

var Showdown={};
Showdown.converter=function(){
var _1;
var _2;
var _3;
var _4=0;
this.makeHtml=function(_5){
_1=new Array();
_2=new Array();
_3=new Array();
_5=_5.replace(/~/g,"~T");
_5=_5.replace(/\$/g,"~D");
_5=_5.replace(/\r\n/g,"\n");
_5=_5.replace(/\r/g,"\n");
_5="\n\n"+_5+"\n\n";
_5=_6(_5);
_5=_5.replace(/^[ \t]+$/mg,"");
_5=_7(_5);
_5=_8(_5);
_5=_9(_5);
_5=_a(_5);
_5=_5.replace(/~D/g,"$$");
_5=_5.replace(/~T/g,"~");
return _5;
};
var _8=function(_b){
var _b=_b.replace(/^[ ]{0,3}\[(.+)\]:[ \t]*\n?[ \t]*<?(\S+?)>?[ \t]*\n?[ \t]*(?:(\n*)["(](.+?)[")][ \t]*)?(?:\n+|\Z)/gm,function(_c,m1,m2,m3,m4){
m1=m1.toLowerCase();
_1[m1]=_11(m2);
if(m3){
return m3+m4;
}else{
if(m4){
_2[m1]=m4.replace(/"/g,"&quot;");
}
}
return "";
});
return _b;
};
var _7=function(_12){
_12=_12.replace(/\n/g,"\n\n");
var _13="p|div|h[1-6]|blockquote|pre|table|dl|ol|ul|script|noscript|form|fieldset|iframe|math|ins|del";
var _14="p|div|h[1-6]|blockquote|pre|table|dl|ol|ul|script|noscript|form|fieldset|iframe|math";
_12=_12.replace(/^(<(p|div|h[1-6]|blockquote|pre|table|dl|ol|ul|script|noscript|form|fieldset|iframe|math|ins|del)\b[^\r]*?\n<\/\2>[ \t]*(?=\n+))/gm,_15);
_12=_12.replace(/^(<(p|div|h[1-6]|blockquote|pre|table|dl|ol|ul|script|noscript|form|fieldset|iframe|math)\b[^\r]*?.*<\/\2>[ \t]*(?=\n+)\n)/gm,_15);
_12=_12.replace(/(\n[ ]{0,3}(<(hr)\b([^<>])*?\/?>)[ \t]*(?=\n{2,}))/g,_15);
_12=_12.replace(/(\n\n[ ]{0,3}<!(--[^\r]*?--\s*)+>[ \t]*(?=\n{2,}))/g,_15);
_12=_12.replace(/(?:\n\n)([ ]{0,3}(?:<([?%])[^\r]*?\2>)[ \t]*(?=\n{2,}))/g,_15);
_12=_12.replace(/\n\n/g,"\n");
return _12;
};
var _15=function(_16,m1){
var _18=m1;
_18=_18.replace(/\n\n/g,"\n");
_18=_18.replace(/^\n/,"");
_18=_18.replace(/\n+$/g,"");
_18="\n\n~K"+(_3.push(_18)-1)+"K\n\n";
return _18;
};
var _9=function(_19){
_19=_1a(_19);
var key=_1c("<hr />");
_19=_19.replace(/^[ ]{0,2}([ ]?\*[ ]?){3,}[ \t]*$/gm,key);
_19=_19.replace(/^[ ]{0,2}([ ]?\-[ ]?){3,}[ \t]*$/gm,key);
_19=_19.replace(/^[ ]{0,2}([ ]?\_[ ]?){3,}[ \t]*$/gm,key);
_19=_1d(_19);
_19=_1e(_19);
_19=_1f(_19);
_19=_7(_19);
_19=_20(_19);
return _19;
};
var _21=function(_22){
_22=_23(_22);
_22=_24(_22);
_22=_25(_22);
_22=_26(_22);
_22=_27(_22);
_22=_28(_22);
_22=_11(_22);
_22=_29(_22);
_22=_22.replace(/  +\n/g," <br />\n");
return _22;
};
var _24=function(_2a){
var _2b=/(<[a-z\/!$]("[^"]*"|'[^']*'|[^'">])*>|<!(--.*?--\s*)+>)/gi;
_2a=_2a.replace(_2b,function(_2c){
var tag=_2c.replace(/(.)<\/?code>(?=.)/g,"$1`");
tag=_2e(tag,"\\`*_");
return tag;
});
return _2a;
};
var _27=function(_2f){
_2f=_2f.replace(/(\[((?:\[[^\]]*\]|[^\[\]])*)\][ ]?(?:\n[ ]*)?\[(.*?)\])()()()()/g,_30);
_2f=_2f.replace(/(\[((?:\[[^\]]*\]|[^\[\]])*)\]\([ \t]*()<?(.*?)>?[ \t]*((['"])(.*?)\6[ \t]*)?\))/g,_30);
_2f=_2f.replace(/(\[([^\[\]]+)\])()()()()()/g,_30);
return _2f;
};
var _30=function(_31,m1,m2,m3,m4,m5,m6,m7){
if(m7==undefined){
m7="";
}
var _39=m1;
var _3a=m2;
var _3b=m3.toLowerCase();
var url=m4;
var _3d=m7;
if(url==""){
if(_3b==""){
_3b=_3a.toLowerCase().replace(/ ?\n/g," ");
}
url="#"+_3b;
if(_1[_3b]!=undefined){
url=_1[_3b];
if(_2[_3b]!=undefined){
_3d=_2[_3b];
}
}else{
if(_39.search(/\(\s*\)$/m)>-1){
url="";
}else{
return _39;
}
}
}
url=_2e(url,"*_");
var _3e="<a href=\""+url+"\"";
if(_3d!=""){
_3d=_3d.replace(/"/g,"&quot;");
_3d=_2e(_3d,"*_");
_3e+=" title=\""+_3d+"\"";
}
_3e+=">"+_3a+"</a>";
return _3e;
};
var _26=function(_3f){
_3f=_3f.replace(/(!\[(.*?)\][ ]?(?:\n[ ]*)?\[(.*?)\])()()()()/g,_40);
_3f=_3f.replace(/(!\[(.*?)\]\s?\([ \t]*()<?(\S+?)>?[ \t]*((['"])(.*?)\6[ \t]*)?\))/g,_40);
return _3f;
};
var _40=function(_41,m1,m2,m3,m4,m5,m6,m7){
var _49=m1;
var _4a=m2;
var _4b=m3.toLowerCase();
var url=m4;
var _4d=m7;
if(!_4d){
_4d="";
}
if(url==""){
if(_4b==""){
_4b=_4a.toLowerCase().replace(/ ?\n/g," ");
}
url="#"+_4b;
if(_1[_4b]!=undefined){
url=_1[_4b];
if(_2[_4b]!=undefined){
_4d=_2[_4b];
}
}else{
return _49;
}
}
_4a=_4a.replace(/"/g,"&quot;");
url=_2e(url,"*_");
var _4e="<img src=\""+url+"\" alt=\""+_4a+"\"";
_4d=_4d.replace(/"/g,"&quot;");
_4d=_2e(_4d,"*_");
_4e+=" title=\""+_4d+"\"";
_4e+=" />";
return _4e;
};
var _1a=function(_4f){
_4f=_4f.replace(/^(.+)[ \t]*\n=+[ \t]*\n+/gm,function(_50,m1){
return _1c("<h1>"+_21(m1)+"</h1>");
});
_4f=_4f.replace(/^(.+)[ \t]*\n-+[ \t]*\n+/gm,function(_52,m1){
return _1c("<h2>"+_21(m1)+"</h2>");
});
_4f=_4f.replace(/^(\#{1,6})[ \t]*(.+?)[ \t]*\#*\n+/gm,function(_54,m1,m2){
var _57=m1.length;
return _1c("<h"+_57+">"+_21(m2)+"</h"+_57+">");
});
return _4f;
};
var _58;
var _1d=function(_59){
_59+="~0";
var _5a=/^(([ ]{0,3}([*+-]|\d+[.])[ \t]+)[^\r]+?(~0|\n{2,}(?=\S)(?![ \t]*(?:[*+-]|\d+[.])[ \t]+)))/gm;
if(_4){
_59=_59.replace(_5a,function(_5b,m1,m2){
var _5e=m1;
var _5f=(m2.search(/[*+-]/g)>-1)?"ul":"ol";
_5e=_5e.replace(/\n{2,}/g,"\n\n\n");
var _60=_58(_5e);
_60=_60.replace(/\s+$/,"");
_60="<"+_5f+">"+_60+"</"+_5f+">\n";
return _60;
});
}else{
_5a=/(\n\n|^\n?)(([ ]{0,3}([*+-]|\d+[.])[ \t]+)[^\r]+?(~0|\n{2,}(?=\S)(?![ \t]*(?:[*+-]|\d+[.])[ \t]+)))/g;
_59=_59.replace(_5a,function(_61,m1,m2,m3){
var _65=m1;
var _66=m2;
var _67=(m3.search(/[*+-]/g)>-1)?"ul":"ol";
var _66=_66.replace(/\n{2,}/g,"\n\n\n");
var _68=_58(_66);
_68=_65+"<"+_67+">\n"+_68+"</"+_67+">\n";
return _68;
});
}
_59=_59.replace(/~0/,"");
return _59;
};
_58=function(_69){
_4++;
_69=_69.replace(/\n{2,}$/,"\n");
_69+="~0";
_69=_69.replace(/(\n)?(^[ \t]*)([*+-]|\d+[.])[ \t]+([^\r]+?(\n{1,2}))(?=\n*(~0|\2([*+-]|\d+[.])[ \t]+))/gm,function(_6a,m1,m2,m3,m4){
var _6f=m4;
var _70=m1;
var _71=m2;
if(_70||(_6f.search(/\n{2,}/)>-1)){
_6f=_9(_72(_6f));
}else{
_6f=_1d(_72(_6f));
_6f=_6f.replace(/\n$/,"");
_6f=_21(_6f);
}
return "<li>"+_6f+"</li>\n";
});
_69=_69.replace(/~0/g,"");
_4--;
return _69;
};
var _1e=function(_73){
_73+="~0";
_73=_73.replace(/(?:\n\n|^)((?:(?:[ ]{4}|\t).*\n+)+)(\n*[ ]{0,3}[^ \t\n]|(?=~0))/g,function(_74,m1,m2){
var _77=m1;
var _78=m2;
_77=_79(_72(_77));
_77=_6(_77);
_77=_77.replace(/^\n+/g,"");
_77=_77.replace(/\n+$/g,"");
_77="<pre><code>"+_77+"\n</code></pre>";
return _1c(_77)+_78;
});
_73=_73.replace(/~0/,"");
return _73;
};
var _1c=function(_7a){
_7a=_7a.replace(/(^\n+|\n+$)/g,"");
return "\n\n~K"+(_3.push(_7a)-1)+"K\n\n";
};
var _23=function(_7b){
_7b=_7b.replace(/(^|[^\\])(`+)([^\r]*?[^`])\2(?!`)/gm,function(_7c,m1,m2,m3,m4){
var c=m3;
c=c.replace(/^([ \t]*)/g,"");
c=c.replace(/[ \t]*$/g,"");
c=_79(c);
return m1+"<code>"+c+"</code>";
});
return _7b;
};
var _79=function(_82){
_82=_82.replace(/&/g,"&amp;");
_82=_82.replace(/</g,"&lt;");
_82=_82.replace(/>/g,"&gt;");
_82=_2e(_82,"*_{}[]\\",false);
return _82;
};
var _29=function(_83){
_83=_83.replace(/(\*\*|__)(?=\S)([^\r]*?\S[*_]*)\1/g,"<strong>$2</strong>");
_83=_83.replace(/(\*|_)(?=\S)([^\r]*?\S)\1/g,"<em>$2</em>");
return _83;
};
var _1f=function(_84){
_84=_84.replace(/((^[ \t]*>[ \t]?.+\n(.+\n)*\n*)+)/gm,function(_85,m1){
var bq=m1;
bq=bq.replace(/^[ \t]*>[ \t]?/gm,"~0");
bq=bq.replace(/~0/g,"");
bq=bq.replace(/^[ \t]+$/gm,"");
bq=_9(bq);
bq=bq.replace(/(^|\n)/g,"$1  ");
bq=bq.replace(/(\s*<pre>[^\r]+?<\/pre>)/gm,function(_88,m1){
var pre=m1;
pre=pre.replace(/^  /mg,"~0");
pre=pre.replace(/~0/g,"");
return pre;
});
return _1c("<blockquote>\n"+bq+"\n</blockquote>");
});
return _84;
};
var _20=function(_8b){
_8b=_8b.replace(/^\n+/g,"");
_8b=_8b.replace(/\n+$/g,"");
var _8c=_8b.split(/\n{2,}/g);
var _8d=new Array();
var end=_8c.length;
for(var i=0;i<end;i++){
var str=_8c[i];
if(str.search(/~K(\d+)K/g)>=0){
_8d.push(str);
}else{
if(str.search(/\S/)>=0){
str=_21(str);
str=str.replace(/^([ \t]*)/g,"<p>");
str+="</p>";
_8d.push(str);
}
}
}
end=_8d.length;
for(var i=0;i<end;i++){
while(_8d[i].search(/~K(\d+)K/)>=0){
var _91=_3[RegExp.$1];
_91=_91.replace(/\$/g,"$$$$");
_8d[i]=_8d[i].replace(/~K\d+K/,_91);
}
}
return _8d.join("\n\n");
};
var _11=function(_92){
_92=_92.replace(/&(?!#?[xX]?(?:[0-9a-fA-F]+|\w+);)/g,"&amp;");
_92=_92.replace(/<(?![a-z\/?\$!])/gi,"&lt;");
return _92;
};
var _25=function(_93){
_93=_93.replace(/\\(\\)/g,_94);
_93=_93.replace(/\\([`*_{}\[\]()>#+-.!])/g,_94);
return _93;
};
var _28=function(_95){
_95=_95.replace(/<((https?|ftp|dict):[^'">\s]+)>/gi,"<a href=\"$1\">$1</a>");
_95=_95.replace(/<(?:mailto:)?([-.\w]+\@[-a-z0-9]+(\.[-a-z0-9]+)*\.[a-z]+)>/gi,function(_96,m1){
return _98(_a(m1));
});
return _95;
};
var _98=function(_99){
function char2hex(ch){
var _9b="0123456789ABCDEF";
var dec=ch.charCodeAt(0);
return (_9b.charAt(dec>>4)+_9b.charAt(dec&15));
}
var _9d=[function(ch){
return "&#"+ch.charCodeAt(0)+";";
},function(ch){
return "&#x"+char2hex(ch)+";";
},function(ch){
return ch;
}];
_99="mailto:"+_99;
_99=_99.replace(/./g,function(ch){
if(ch=="@"){
ch=_9d[Math.floor(Math.random()*2)](ch);
}else{
if(ch!=":"){
var r=Math.random();
ch=(r>0.9?_9d[2](ch):r>0.45?_9d[1](ch):_9d[0](ch));
}
}
return ch;
});
_99="<a href=\""+_99+"\">"+_99+"</a>";
_99=_99.replace(/">.+:/g,"\">");
return _99;
};
var _a=function(_a3){
_a3=_a3.replace(/~E(\d+)E/g,function(_a4,m1){
var _a6=parseInt(m1);
return String.fromCharCode(_a6);
});
return _a3;
};
var _72=function(_a7){
_a7=_a7.replace(/^(\t|[ ]{1,4})/gm,"~0");
_a7=_a7.replace(/~0/g,"");
return _a7;
};
var _6=function(_a8){
_a8=_a8.replace(/\t(?=\t)/g,"    ");
_a8=_a8.replace(/\t/g,"~A~B");
_a8=_a8.replace(/~B(.+?)~A/g,function(_a9,m1,m2){
var _ac=m1;
var _ad=4-_ac.length%4;
for(var i=0;i<_ad;i++){
_ac+=" ";
}
return _ac;
});
_a8=_a8.replace(/~A/g,"    ");
_a8=_a8.replace(/~B/g,"");
return _a8;
};
var _2e=function(_af,_b0,_b1){
var _b2="(["+_b0.replace(/([\[\]\\])/g,"\\$1")+"])";
if(_b1){
_b2="\\\\"+_b2;
}
var _b3=new RegExp(_b2,"g");
_af=_af.replace(_b3,_94);
return _af;
};
var _94=function(_b4,m1){
var _b6=m1.charCodeAt(0);
return "~E"+_b6+"E";
};
};


/************ CHANGE: class overwrap *************/

/***************************************
*
*	Javascript Textile->HTML conversion
*
*	ben@ben-daglish.net (with thanks to John Hughes for improvements)
*   Issued under the "do what you like with it - I take no respnsibility" licence
****************************************/

var Textile={};
Textile.converter=function(){

var inpr,inbq,inbqq,html;
var aliases = new Array;
var alg={'>':'right','<':'left','=':'center','<>':'justify','~':'bottom','^':'top'};
var ent={"'":"&#8217;"," - ":" &#8211; ","--":"&#8212;"," x ":" &#215; ","\\.\\.\\.":"&#8230;","\\(C\\)":"&#169;","\\(R\\)":"&#174;","\\(TM\\)":"&#8482;"};
var tags={"b":"\\*\\*","i":"__","em":"_","strong":"\\*","cite":"\\?\\?","sup":"\\^","sub":"~","span":"\\%","del":"-","code":"@","ins":"\\+","del":"-"};
var le="\n\n";
var lstlev=0,lst="",elst="",intable=0,mm="";
var para = /^p(\S*)\.\s*(.*)/;
var rfn = /^fn(\d+)\.\s*(.*)/;
var bq = /^bq\.(\.)?\s*/;
var table=/^table\s*{(.*)}\..*/;
var trstyle = /^\{(\S+)\}\.\s*\|/;

this.makeHtml = function(t) {
	var lines = t.split(/\r?\n/);
	html="";
	inpr=inbq=inbqq=0;
	for(var i=0;i<lines.length;i++) {
		if(lines[i].indexOf("[") == 0) {
			var m = lines[i].indexOf("]");
			aliases[lines[i].substring(1,m)]=lines[i].substring(m+1);
		}
	}
	for(i=0;i<lines.length;i++) {
		if (lines[i].indexOf("[") == 0) {continue;}
		if(mm=para.exec(lines[i])){stp(1);inpr=1;html += lines[i].replace(para,"<p"+make_attr(mm[1])+">"+prep(mm[2]));continue;}
		if(mm = /^h(\d)(\S*)\.\s*(.*)/.exec(lines[i])){stp(1);html += tag("h"+mm[1],make_attr(mm[2]),prep(mm[3]))+le;continue;}
		if(mm=rfn.exec(lines[i])){stp(1);inpr=1;html+=lines[i].replace(rfn,'<p id="fn'+mm[1]+'"><sup>'+mm[1]+'<\/sup>'+prep(mm[2]));continue;}
		if (lines[i].indexOf("*") == 0) {lst="<ul>";elst="<\/ul>";}
		else if (lines[i].indexOf("#") == 0) {lst="<\ol>";elst="<\/ol>";}
		else {while (lstlev > 0) {html += elst;if(lstlev > 1){html += "<\/li>";}else{html+="\n";}html+="\n";lstlev--;}lst="";}
		if(lst) {
			stp(1);
			var m = /^([*#]+)\s*(.*)/.exec(lines[i]);
			var lev = m[1].length;
			while(lev < lstlev) {html += elst+"<\/li>\n";lstlev--;}
			while(lstlev < lev) {html=html.replace(/<\/li>\n$/,"\n");html += lst;lstlev++;}
			html += tag("li","",prep(m[2]))+"\n";
			continue;
		}
		if (lines[i].match(table)){stp(1);intable=1;html += lines[i].replace(table,'<table style="$1;">\n');continue;}
		if ((lines[i].indexOf("|") == 0)  || (lines[i].match(trstyle)) ) {
			stp(1);
			if(!intable) {html += "<table>\n";intable=1;}
			var rowst="";var trow="";
			var ts=trstyle.exec(lines[i]);
			if(ts){rowst=qat('style',ts[1]);lines[i]=lines[i].replace(trstyle,"\|");}
			var cells = lines[i].split("|");
			for(j=1;j<cells.length-1;j++) {
				var ttag="td";
				if(cells[j].indexOf("_.")==0) {ttag="th";cells[j]=cells[j].substring(2);}
				cells[j]=prep(cells[j]);
				var al=/^([<>=^~\/\\\{]+.*?)\.(.*)/.exec(cells[j]);
				var at="",st="";
				if(al != null) {
					cells[j]=al[2];
					var cs= /\\(\d+)/.exec(al[1]);if(cs != null){at +=qat('colspan',cs[1]);}
					var rs= /\/(\d+)/.exec(al[1]);if(rs != null){at +=qat('rowspan',rs[1]);}
					var va= /([\^~])/.exec(al[1]);if(va != null){st +="vertical-align:"+alg[va[1]]+";";}
					var ta= /(<>|=|<|>)/.exec(al[1]);if(ta != null){st +="text-align:"+alg[ta[1]]+";";}
					var is= /\{([^\}]+)\}/.exec(al[1]);if(is != null){st +=is[1];}
					if(st != ""){at+=qat('style',st);}					
				}
				trow += tag(ttag,at,cells[j]);
			}
			html += "\t"+tag("tr",rowst,trow)+"\n";
			continue;
		}
		if(intable) {html += "<\/table>"+le;intable=0;}

		if (lines[i]=="") {stp();}
		else if (!inpr) {
			if(mm=bq.exec(lines[i])){lines[i]=lines[i].replace(bq,"");html +="<blockquote>";inbq=1;if(mm[1]) {inbqq=1;}}
			html += "<p>"+prep(lines[i]);inpr=1;
		}
		else {html += prep(lines[i]);}
	}
	stp();
	return html;
}

function prep(m){
	for(i in ent) {m=m.replace(new RegExp(i,"g"),ent[i]);}
	for(i in tags) {
		m = make_tag(m,RegExp("^"+tags[i]+"(.+?)"+tags[i]),i,"");
		m = make_tag(m,RegExp(" "+tags[i]+"(.+?)"+tags[i]),i," ");
	}
	m=m.replace(/\[(\d+)\]/g,'<sup><a href="#fn$1">$1<\/a><\/sup>');
	m=m.replace(/([A-Z]+)\((.*?)\)/g,'<acronym title="$2">$1<\/acronym>');
	m=m.replace(/\"([^\"]+)\":((http|https|mailto):\S+)/g,'<a href="$2">$1<\/a>');
	m = make_image(m,/!([^!\s]+)!:(\S+)/);
	m = make_image(m,/!([^!\s]+)!/);
	m=m.replace(/"([^\"]+)":(\S+)/g,function($0,$1,$2){return tag("a",qat('href',aliases[$2]),$1)});
	m=m.replace(/(=)?"([^\"]+)"/g,function($0,$1,$2){return ($1)?$0:"&#8220;"+$2+"&#8221;"});
	return m;
}

function make_tag(s,re,t,sp) {
	while(m = re.exec(s)) {
		var st = make_attr(m[1]);
		m[1]=m[1].replace(/^[\[\{\(]\S+[\]\}\)]/g,"");
		m[1]=m[1].replace(/^[<>=()]+/,"");
		s = s.replace(re,sp+tag(t,st,m[1]));
	}
	return s;
}

function make_image(m,re) {
	var ma = re.exec(m);
	if(ma != null) {
		var attr="";var st="";
		var at = /\((.*)\)$/.exec(ma[1]);
		if(at != null) {attr = qat('alt',at[1])+qat("title",at[1]);ma[1]=ma[1].replace(/\((.*)\)$/,"");}
		if(ma[1].match(/^[><]/)) {st = "float:"+((ma[1].indexOf(">")==0)?"right;":"left;");ma[1]=ma[1].replace(/^[><]/,"");}
		var pdl = /(\(+)/.exec(ma[1]);if(pdl){st+="padding-left:"+pdl[1].length+"em;";}
		var pdr = /(\)+)/.exec(ma[1]);if(pdr){st+="padding-right:"+pdr[1].length+"em;";}
		if(st){attr += qat('style',st);}
		var im = '<img src="'+ma[1]+'"'+attr+" />";
		if(ma.length >2) {im=tag('a',qat('href',ma[2]),im);}
		m = m.replace(re,im);
	}
	return m;
}

function make_attr(s) {
	var st="";var at="";
	if(!s){return "";}
	var l=/\[(\w\w)\]/.exec(s);
	if(l != null) {at += qat('lang',l[1]);}
	var ci=/\((\S+)\)/.exec(s);
	if(ci != null) {
		s = s.replace(/\((\S+)\)/,"");
		at += ci[1].replace(/#(.*)$/,' id="$1"').replace(/^(\S+)/,' class="$1"');
	}
	var ta= /(<>|=|<|>)/.exec(s);if(ta){st +="text-align:"+alg[ta[1]]+";";}
	var ss=/\{(\S+)\}/.exec(s);if(ss){st += ss[1];if(!ss[1].match(/;$/)){st+= ";";}}
	var pdl = /(\(+)/.exec(s);if(pdl){st+="padding-left:"+pdl[1].length+"em;";}
	var pdr = /(\)+)/.exec(s);if(pdr){st+="padding-right:"+pdr[1].length+"em;";}
	if(st) {at += qat('style',st);}
	return at;
}

function qat(a,v){return ' '+a+'="'+v+'"';}
function tag(t,a,c) {return "<"+t+a+">"+c+"</"+t+">";}
function stp(b){if(b){inbqq=0;}if(inpr){html+="<\/p>"+le;inpr=0;}if(inbq && !inbqq){html+="<\/blockquote>"+le;inbq=0;}}
};




/************ CHANGE: method add makeHtml *************/

/*
  @author: remy sharp / http://remysharp.com
  @url: http://remysharp.com/2008/04/01/wiki-to-html-using-javascript/
  @license: Creative Commons License - ShareAlike http://creativecommons.org/licenses/by-sa/3.0/
  @version: 1.0
  
  Can extend String or be used stand alone - just change the flag at the top of the script.
*/

var WikiParser={};
WikiParser.converter=function(){

// the regex beast...
this.makeHtml=function(s){
    
    // lists need to be done using a function to allow for recusive calls
    function list(str) {
        return str.replace(/(?:(?:(?:^|\n)[\*#].*)+)/g, function (m) {  // (?=[\*#])
            var type = m.match(/(^|\n)#/) ? 'OL' : 'UL';
            // strip first layer of list
            m = m.replace(/(^|\n)[\*#][ ]{0,1}/g, "$1");
            m = list(m);
            return '<' + type + '><li>' + m.replace(/^\n/, '').split(/\n/).join('</li><li>') + '</li></' + type + '>';
        });
    }
    
    return list(s
        
        /* BLOCK ELEMENTS */
        .replace(/(?:^|\n+)([^# =\*<].+)(?:\n+|$)/gm, function (m, l) {
            if (l.match(/^\^+$/)) return l;
            return "\n<p>" + l + "</p>\n";
        })

        .replace(/(?:^|\n)[ ]{2}(.*)+/g, function (m, l) { // blockquotes
            if (l.match(/^\s+$/)) return m;
            return '<blockquote>' + l + '</pre>';
        })
        
        .replace(/((?:^|\n)[ ]+.*)+/g, function (m) { // code
            if (m.match(/^\s+$/)) return m;
            return '<pre>' + m.replace(/(^|\n)[ ]+/g, "$1") + '</pre>';
        })

        .replace(/(?:^|\n)([=]+)(.*)\1/g, function (m, l, t) { // headings
            return '<h' + l.length + '>' + t + '</h' + l.length + '>';
        })
    
        /* INLINE ELEMENTS */
        .replace(/'''(.*?)'''/g, function (m, l) { // bold
            return '<strong>' + l + '</strong>';
        })
    
        .replace(/''(.*?)''/g, function (m, l) { // italic
            return '<em>' + l + '</em>';
        })
    
        .replace(/[^\[](http[^\[\s]*)/g, function (m, l) { // normal link
            return '<a href="' + l + '">' + l + '</a>';
        })
    
        .replace(/[\[](http.*)[!\]]/g, function (m, l) { // external link
            var p = l.replace(/[\[\]]/g, '').split(/ /);
            var link = p.shift();
            return '<a href="' + link + '">' + (p.length ? p.join(' ') : link) + '</a>';
        })
    
        .replace(/\[\[(.*?)\]\]/g, function (m, l) { // internal link or image
            var p = l.split(/\|/);
            var link = p.shift();

            if (link.match(/^Image:(.*)/)) {
                // no support for images - since it looks up the source from the wiki db :-(
                return m;
            } else {
                return '<a href="' + link + '">' + (p.length ? p.join('|') : link) + '</a>';
            }
        })
    ); 
}

};



/************ CHANGE: method add makeHtml *************/

// ================================================================
//  jkl-dumper.js ---- JavaScript Object Dumper
//  Copyright 2005-2006 Kawasaki Yusuke <u-suke@kawa.net>
//  2005/05/18 - First Release
//  2006/09/04 - http://www.rfc-editor.org/rfc/rfc4627.txt
//  ===============================================================

/******************************************************************

    <script type="text/javascript" src="./jkl-dumper.js" charset="Shift_JIS"></script>
    <script><!--
        var data = {
            string: "string",
            array:  [ 1, 2, 3 ],
            hash:   { key1: "value1", key2: "value2" },
            data1:  null,
            data2:  true,
            data3:  false
        };
        var dumper = new JKL.Dumper();
        document.write( dumper.dump( data ) );
    //--></script>

******************************************************************/

if ( typeof(JKL) == 'undefined' ) JKL = function() {};

//  JKL.Dumper Constructor

JKL.Dumper = function () {
    return this;
};

JKL.Dumper.prototype.makeHtml = function ( txt ) {
    return this.dump(eval('('+txt+')'));
};

//  Dump the data into JSON format

JKL.Dumper.prototype.dump = function ( data, offset ) {
    if ( typeof(offset) == "undefined" ) offset = "";
    var nextoff = offset + "  ";
    switch ( typeof(data) ) {
    case "string":
        return '"'+this.escapeString(data)+'"';
        break;
    case "number":
        return data;
        break;
    case "boolean":
        return data ? "true" : "false";
        break;
    case "undefined":
        return "null";
        break;
    case "object":
        if ( data == null ) {
            return "null";
        } else if ( data.constructor == Array ) {
            var array = [];
            for ( var i=0; i<data.length; i++ ) {
                array[i] = this.dump( data[i], nextoff );
            }
            return "[\n"+nextoff+array.join( ",\n"+nextoff )+"\n"+offset+"]";
        } else {
            var array = [];
            for ( var key in data ) {
                var val = this.dump( data[key], nextoff );
//              if ( key.match( /[^A-Za-z0-9_]/ )) {
                    key = '"'+this.escapeString( key )+'"';
//              }
                array[array.length] = key+": "+val;
            }
            if ( array.length == 1 && ! array[0].match( /[\n\{\[]/ ) ) {
                return "{ "+array[0]+" }";
            }
            return "{\n"+nextoff+array.join( ",\n"+nextoff )+"\n"+offset+"}";
        }
        break;
    default:
        return data;
        // unsupported data type
        break;
    }
};

//  escape '\' and '"'

JKL.Dumper.prototype.escapeString = function ( str ) {
    return str.replace( /\\/g, "\\\\" ).replace( /\"/g, "\\\"" );
};

//  ===============================================================




    // converter
    var converter = {};
    converter.markdown = new Showdown.converter();
    converter.textile = new Textile.converter();
    converter.wiki = new WikiParser.converter();
    converter.json = new JKL.Dumper();
    
    var format_ext = {};
    format_ext['txt'] = 'markdown';
    format_ext['md'] = 'markdown';
    format_ext['mkd'] = 'markdown';
    format_ext['markdown'] = 'markdown';
    format_ext['tt'] = 'textile';
    format_ext['textile'] = 'textile';
    format_ext['wiki'] = 'wiki';
    format_ext['json'] = 'json';
    format_ext['html'] = 'html';
    format_ext['htm'] = 'html';
    
    // custom converter
    if (window['invisible_format']) {
        for (var key in window['invisible_format']) {
            var val = window['invisible_format'][key];
            converter[key] = val['converter'];
            for (var i=0; i<val['extension'].length; i++) {
                format_ext[val['extension'][i]] = key;
            }
            format_ext[key] = val['converter'];
        }
    }

})(jQuery);
