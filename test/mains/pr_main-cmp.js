(function(){
  var __global_exports = {};
  try{throw new SyntaxError( "syntax error, unexpected $end in file /var/samba/back/mocha/test/mains/pr_main.js line : 24" )}catch(e){throw new Error(e);};__global_exports["/var/samba/back/mocha/test/jspp-modules/EventDelegator.js"] = (function(){
    var exports = {};
    Class("EventDelegator")(function (self, privates) {
      var events = {
            mousemove : "mousemove",
            mousedown : "mousedown",
            mouseup : "mouseup",
            click : "click"
          },
          addEvent = (document.addEventListener)? function (obj, type, fn) {
            obj.addEventListener(type, fn, false);
          } : (function () {
            var _eventObject = function (e) {
                  if (!this.preventDefault) {
                    return new _eventObject(e);
                  }
                  this.isPreventDefault = false, this.isStopPropagation = false, this.oevent = e;
                  this.type = e.type;
                  this.timeStamp = +(new Date);
                  _addProps(this, e);
                },
                e_props = "altKey attrChange attrName bubbles button cancelable charCode clientX clientY ctrlKey currentTarget data detail eventPhase fromElement handler keyCode layerX layerY metaKey newValue offsetX offsetY originalTarget pageX pageY prevValue relatedNode relatedTarget screenX screenY shiftKey srcElement target toElement view wheelDelta which".split(" "),
                _addProps = function (e, o) {
                  var iter = e_props.length,
                      DOC = document,
                      ROOT = DOC.htmlElement,
                      body = DOC.body,
                      tp;
                  while ((tp = e_props[--iter])) {
                    e[tp] = o[tp];
                  }
                  e.attrName = o.attrName || o.propertyName || null;
                  if (!e.target) {
                    e.target = e.srcElement || DOC;
                  }
                  if (e.target.nodeType === 3) {
                    e.target = e.target.parentNode;
                  }
                  if (!e.relatedTarget && e.fromElement) {
                    e.relatedTarget = e.fromElement === e.target? e.toElement : e.fromElement;
                  }
                  if (e.pageX === null && e.clientX !== null) {
                    e.pageX = e.clientX + (ROOT && ROOT.scrollLeft || body && body.scrollLeft || 0) + (ROOT && ROOT.clientLeft || body && body.clientLeft || 0);
                    e.pageY = e.clientY + (ROOT && ROOT.scrollTop || body && body.scrollTop || 0) + (ROOT && ROOT.clientTop || body && body.clientTop || 0);
                  }
                  if (e.pageX === null && e.clientX !== null) {
                    e.pageX = e.clientX + (ROOT && ROOT.scrollLeft || body && body.scrollLeft || 0) + (ROOT && ROOT.clientLeft || body && body.clientLeft || 0);
                    e.pageY = e.clientY + (ROOT && ROOT.scrollTop || body && body.scrollTop || 0) + (ROOT && ROOT.clientTop || body && body.clientTop || 0);
                  }
                  if (!e.metaKey && e.ctrlKey) {
                    e.metaKey = e.ctrlKey;
                  }
                  if (!e.which && e.button !== undefined) {
                    e.which = (e.button & 1? 1 : (e.button & 2? 3 : (e.button & 4? 2 : 0)));
                  }
                };
            _eventObject.prototype = {
              preventDefault : function () {
                this.oevent.returnValue = false;
                this.isPreventDefault = true;
                return false;
              },
              stopPropagation : function () {
                this.oevent.cancelBubble = true;
                this.isStopPropagation = true;
                return false;
              }
            };
            return function (obj, type, fn) {
              if (!obj.eventCache || !(type  in  obj.eventCache)) {
                var event = function (e) {
                      var cache = obj.eventCache[type];
                      for (var i = 0,len = cache.length; i < len; ++i) {
                        cache[i].call(obj, _eventObject(e));
                      }
                    };
                obj.eventCache = {};
                obj.eventCache[type] = [ fn ];
                obj.attachEvent("on" + type, event);
                destroy(function () {
                  obj.detachEvent("on" + type, event);
                  obj.eventCache[type].length = 0;
                  obj = null;
                  event = null;
                });
              } else {
                obj.eventCache[type].push(fn);
              }
            };
          })(),
          delegatorUtil = {
            iodata : {
              "id" : {},
              "class" : {}
            },
            hasTargetAttributes : function PRI_hasTargetAttributes(elem) {
              if (!elem) {
                return 0x04;
              }
              var is_id = delegatorUtil.hasAttribute(elem, "id"),
                  is_class = delegatorUtil.hasAttribute(elem, "class");
              if (is_id && is_class) {
                return 0x01;
              } else if (is_id) {
                return 0x02;
              } else if (is_class) {
                return 0x03;
              } else {
                return 0x04;
              }
            },
            hasAttribute : ("hasAttribute"  in  document.getElementsByTagName("head")[0])? function (elem, attr) {
              return elem.hasAttribute(attr);
            } : function (elem, attr) {
              return elem[attr] !== null || elem[attr].length > 0;
            },
            procRegistry : {},
            checkID : function (elem, e, that) {
              var elem_id = elem.id,
                  dat = delegatorUtil.iodata.id,
                  type = null,
                  fns = null,
                  is_run = null;
              if ((type = dat[elem_id])) {
                if ((fns = type[e.type])) {
                  fns.forEach(function (fn) {
                    if (fn[1] === that.guid) {
                      fn[0].call(elem, e);
                      is_run = true;
                    }
                  });
                }
              }
              return is_run;
            },
            checkClass : function (elem, e, that) {
              var elem_class = elem.className,
                  dat = delegatorUtil.iodata["class"],
                  type = null,
                  fns = null,
                  is_run = null;
              elem_class = elem_class.split(" ");
              for (var i = 0,len = elem_class.length; i < len; ++i) {
                if ((type = dat[(elem_class[i].trim())])) {
                  if ((fns = type[e.type])) {
                    fns.forEach(function (fn) {
                      if (fn[1] === that.guid) {
                        e.stopPropagation();
                        fn[0].call(elem, e);
                        is_run = true;
                      }
                    });
                  }
                }
              }
              return is_run;
            },
            runBothEvent : function (target, e, that) {
              delegatorUtil.checkID(target, e, that);
              delegatorUtil.checkClass(target, e, that);
            },
            recieveEvent : function (e) {
              var target = e.target,
                  types = delegatorUtil.hasTargetAttributes(target),
                  ret;
              switch (types) {
                case 0x01 :
                  delegatorUtil.runBothEvent(target, e, this);
                  break;case 0x02 :
                  delegatorUtil.checkID(target, e, this);
                  break;case 0x03 :
                  delegatorUtil.checkClass(target, e, this);
                  break;default :
                  return ; {
                  
                }
              }
            },
            entry : {},
            postExit : function postExit() {
              var cache = delegatorUtil.eventCache;
              cache.forEach(function (fn) {
                fn();
              });
              delegatorUtil.iodata["class"] = null;
              delegatorUtil.iodata["id"] = null;
              delegatorUtil = null;
              if (document.addEventListener) {
                window.removeEventListener("unload", postExit, false);
              }
            },
            eventCache : [  ]
          },
          addDelegator = function (type, elem) {
            if (!elem.guid) {
              elem.guid = guidgen();
            }
            addEvent(elem, type, delegatorUtil.recieveEvent, false);
            if (document.addEventListener) {
              delegatorUtil.eventCache.push(function () {
                elem.removeEventListener(type, delegatorUtil.recieveEvent, false);
              });
            }
          };
      destroy(function () {
        delegatorUtil.postExit();
      });
      self.__init__ = function setup(type, elems) {
        if (typeOf(type) === "Array") {
          return type.forEach(function (d) {
            setup.call(this, d, elems);
          }.bind(this));
        }
        if (elems.nodeType) {
          addDelegator(type, elems);
          privates(this, {
            target : [ elems ]
          });
        } else {
          Array.prototype.forEach.call(elems, function (elem) {
            addDelegator(type, elem);
          });
          privates(this, {
            target : elems
          });
        }
      }, self.addDelegator = function PB_addReciever(proc_obj) {
        Array.prototype.forEach.call(privates(this).target, function (d, i) {
          level(delegatorUtil.iodata[proc_obj.type], proc_obj.name + "." + proc_obj.eventType, function (obj, prop) {
            obj[prop] = [  ];
            return obj[prop];
          }).push([ proc_obj.reciever, d.guid ]);
        });
      };
    });
    
    return exports;
  })();
  __global_exports["/var/samba/back/mocha/test/jspp-modules/Notificator.js"] = (function(){
    var exports = {};
    Class("Notificator")(function (self, privates) {
      var shift = Array.prototype.shift;
      var observer = {
            update : function (id, args) {
              if (this.pool[id]) {
                for (var i = 0,pool = this.pool[id],len = this.pool[id].length; i < len; i += 2) {
                  pool[i].apply(null, args);
                }
              }
            },
            updateByKey : function (id, args) {
              var key = shift.call(args);
              if (this.pool[id]) {
                for (var i = 0,pool = this.pool[id],len = this.pool[id].length; i < len; i += 2) {
                  if (pool[i + 1] === key) {
                    pool[i].apply(null, args);
                  }
                }
              }
            },
            pool : {}
          };
      destroy(function () {
        observer.pool.length = 0;
        delete observer.pool;
      });
      self.__init__ = function () {
        privates(this, {
          _subjectId : guidgen()
        });
      };
      self.connect = function (key, fn) {
        debug :  {
          assert.True(baseTypeOf(key) === "String", "The first arguments of Notificator::connect must be a type of String.");
          assert.True(baseTypeOf(fn) === "Function", "The second arguments of Notificator::connect must be a type of String.");
        }
        level(observer.pool, privates(this)._subjectId, function (o, n) {
          o[n] = [  ];
          return o[n];
        }).push(fn, key);
      };
      self.disconnect = function (fn) {
        debug :  {
          assert.True(baseTypeOf(fn) === "Function", "The first arguments of Notificator::connect must be a type of String.");
        }
        observer.pool[privates(this)._subjectId].splice(observer.pool.indexOf(fn), 2);
      };
      self.notify = function () {
        observer.update(privates(this)._subjectId, arguments);
      };
      self.notifyForKey = function () {
        observer.updateByKey(privates(this)._subjectId, arguments);
      };
    });
    
    return exports;
  })();
  __global_exports["/var/samba/back/mocha/test/jspp-modules/Mutex.js"] = (function(){
    var exports = {};
    Class("Mutex")(function (self, privates) {
      self.__init__ = Mutex_new;
      self.scopeLock = Mutex_scopeLock;
      self.scopeUnlock = Mutex_scopeUnLock;
      self.wait = Mutex_wait;
      self.isLocked = Mutex_isLocked;
      function Mutex_new() {
        privates(this, {
          mutexQueue : [  ],
          _scoped_lock : false
        });
      }
      function Mutex_scopeLock() {
        privates(this)._scoped_lock = true;
      }
      function Mutex_scopeUnLock() {
        var privateVar = privates(this);
        privateVar._scoped_lock = false;
        return (privateVar.mutexQueue.length > 0)? privateVar.mutexQueue.shift() : null;
      }
      function Mutex_wait(arg) {
        privates(this).mutexQueue.push(arg);
      }
      function Mutex_isLocked() {
        return privates(this)._scoped_lock;
      }
    });
    
    return exports;
  })();
  __global_exports["/var/samba/back/mocha/test/jspp-modules/Request.js"] = (function(){
    var exports = {};
    var Notificator = __global_exports["./Notificator"].Notificator,
        Mutex = __global_exports["./Mutex"].Mutex;
    Class("Request", Mutex)(function (self, privates) {
      var rxml = /xml/i,
          rjson = /json/i,
          rget = /get/i,
          rpost = /post/i,
          NOOP = function () {
          };
      self.__init__ = Request_new;
      self.send = Request_send;
      self.addListener = Request_addListener;
      self.abort = abort;
      self.dispose = dispose;
      function Request_new() {
        this.__super__();
        privates(this, {
          ioNotificator : Notificator(),
          connectionObject : JSPP_XMLHttpRequest()
        });
      }
      self.COMPLETE = "complete";
      self.PROGRESS = "progress";
      self.ERROR = "error";
      function Request_addListener(name, fn) {
        var privateVar = privates(this);
        privateVar[name] = true;
        privateVar.ioNotificator.connect(name, fn);
      }
      function Request_send(obj) {
        var privateVar = privates(this);
        if (this.isLocked()) {
          return this.wait(obj);
        }
        var req = privateVar.connectionObject,
            send_type = obj.type || "POST",
            data = (obj.data)? serializeHelper.call(this, obj.data) : null,
            url = (obj.url || "/"),
            get_param = (rget.test(send_type) && data)? ("?" + data) : "";
        req.abort();
        req.open(send_type, url + get_param, (isDef(obj.asyncc))? obj.async : true);
        if (obj.mime && req.overrideMimeType) {
          req.overrideMimeType(obj.mime);
        }
        if (obj.header && req.setRequestHeader) {
          req.setRequestHeader.apply(req, obj.header);
        }
        if ("onprogress"  in  req && privateVar.progress) {
          req.onprogress = function (e) {
            privateVar.ioNotificator.notifyForKey("progress", e.position, e.totalSize, (e.position / e.totalSize) * 100);
          }.bind(this);
        }
        if ("onload"  in  req && privateVar.complete) {
          req.onload = function (e) {
            req.onload = null;
            callbackHelper.call(this, obj, req);
          }.bind(this);
          if ("onerror"  in  req) {
            req.onerror = function () {
              req.onerror = NOOP;
              callHelper.call(this, obj, req);
            }.bind(this);
          }
        } else if (privateVar.complete) {
          req.onreadystatechange = function (e) {
            if (req.readyState === 4) {
              req.onreadystatechange = NOOP;
              callbackHelper.call(this, obj, req);
            }
          }.bind(this);
        }
        this.scopeLock();
        if (rpost.test(send_type) && obj.data) {
          req.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
          req.send(data);
        } else {
          req.send("");
        }
      }
      function abort() {
        var privateVar = privates(this);
        privateVar.connectionObject.abort();
        privateVar.mutexQueue.length = 0;
      }
      function dispose() {
        var privateVar = privates(this);
        privateVar.connectionObject.abort();
        privateVar.connectionObject = null;
        privateVar.mutexQueue.length = 0;
      }
      function serializeHelper(param) {
        var type = typeof param,
            param_arr,
            tp,
            tv,
            param_str = "";
        if (type === "string") {
          param_arr = param.split("&");
          for (var i = 0,len = param_arr.length; i < len; ++i) {
            tp = param_arr[i].split("=");
            if (tp[1]) {
              tv = encodeURIComponent(tp[1]);
            } else {
              tv = "";
            }
            param_str += "&" + tp[0] + "=" + tv;
          }
          return param_str.slice(1, param_str.length);
        } else if (type === "object") {
          for (i in param) {
            param_str += "&" + i + "=" + encodeURIComponent(param[i]);
          }
          return param_str.slice(1, param_str.length);
        }
      }
      function callbackHelper(obj, req) {
        if (req.status === 200) {
          var privateVar = privates(this);
          if (obj.name) {
            privateVar.ioNotificator.notifyForKey(obj.name, (!obj.dataType)? req.responseText : (rxml.test(obj.dataType))? req.responseXML : (rjson.test(obj.dataType))? JSON.parse(req.responseText) : req.responseText);
          } else {
            privateVar.ioNotificator.notifyForKey(this.COMPLETE, (!obj.dataType)? req.responseText : (rxml.test(obj.dataType))? req.responseXML : (rjson.test(obj.dataType))? JSON.parse(req.responseText) : req.responseText);
          }
        } else {
          privateVar.ioNotificator.notifyForKey(this.ERROR, obj, (!obj.dataType)? req.responseText : (rxml.test(obj.dataType))? req.responseXML : (rjson.test(obj.dataType))? JSON.parse(req.responseText) : req.responseText);
        }
        ioQueueHelper.call(this);
      }
      function ioQueueHelper() {
        var wait = this.scopeUnlock();
        if (wait) {
          this.send(wait);
        }
      }
    });
    
    return exports;
  })();
  __global_exports["/var/samba/back/mocha/test/3rd-modules/Info.js"] = (function(){
    var exports = {};
    var Request = __global_exports["Request"].Request;
    Class("Info")(function (self, privates) {
      function send(req, privateVar) {
        req.addListener("complete", function (data) {
          privateVar.info = data;
        });
        req.addListener("error", function () {
          if (privateVar.tried < 5) {
            privateVar.tried++;
            send(req, privateVar);
          }
        });
        req.send({
          url : "src/info.json",
          dataType : "json",
          type : "GET"
        });
      }
      
      self.__singleton__ = true;
      self.__init__ = function () {
        privates(this, {});
        var req = Request(),
            privateVar = privates(this);
        privateVar.tried = 0;
        send(req, privateVar);
      };
      self.get = function () {
        return privates(this).info;
      };
    });
    
    return exports;
  })();
  __global_exports["/var/samba/back/mocha/test/3rd-modules/RollController.js"] = (function(){
    var exports = {};
    var EventDelegator = __global_exports["EventDelegator"].EventDelegator,
        Info = __global_exports["./Info"].Info;
    Class("RollController")(function (self, privates) {
      var LIST_SIZE = 440,
          LARGE_SIZE = 490,
          SEMI_LARGE_SIZE = 460,
          DIFF = (SEMI_LARGE_SIZE + LIST_SIZE) + ((LARGE_SIZE + LIST_SIZE) / 2),
          ADD = (SEMI_LARGE_SIZE + LIST_SIZE) * 2 + (LARGE_SIZE + LIST_SIZE),
          LARGE_CLASS = "large",
          SEMI_LARGE_CLASS = "semiLarge",
          NO_IMAGE = "src/img/noimage.jpg";
      var calcCenter = function () {
            var privateVar = privates(this),
                centerSize = LARGE_SIZE + (SEMI_LARGE_SIZE * 2),
                isEven = privateVar.listCounts % 2 === 0,
                max = (isEven)? privateVar.maxWidth : privateVar.maxWidth + LIST_SIZE,
                ulNegate = (privateVar.windowWidth + max) / 2 + LIST_SIZE / 2;
            privateVar.centerConstNum = (privateVar.windowWidth + LIST_SIZE) / 2 + LIST_SIZE;
            privateVar.rollList.css("marginLeft", ulNegate + "px");
            addClassToCenter(privateVar, ulNegate, max);
          },
          addClassToCenter = function (privateVar, ulNegate, max) {
            var index = (max + (-1 * parseFloat(privateVar.rollList.css("marginLeft"))) + privateVar.centerConstNum) / LIST_SIZE;
            privateVar.rollList.css({
              "marginLeft" : (ulNegate + DIFF) + "px",
              width : privateVar.maxWidth + ADD + 20
            });
            privateVar.defNegate = ulNegate;
            setCenterClass(index + 1);
            privateVar.currentLarge = toInteger(index + 1);
            setText(privateVar);
          },
          setCenterClass = function (index) {
            $("#rollList li").eq(index).addClass(LARGE_CLASS).end().eq(index + 1).addClass(SEMI_LARGE_CLASS).end().eq(index + 1).addClass(SEMI_LARGE_CLASS).end();
          },
          setText = function (privateVar) {
            var text = $(("#rollList li." + LARGE_CLASS)).attr("info-data"),
                sptext = text.split(":");
            privateVar.title.text(sptext[0]);
            privateVar.tools.text(sptext[1]);
          },
          loadImage = function (data, callback) {
            var image = (new Image);
            image.onload = function () {
              callback(image);
            };
            if (data.src === "no") {
              data.src = NO_IMAGE;
              image.className = "noImage";
            }
            image.className += " imageData";
            image.src = data.src;
            image.alt = (data.alt)? data.alt : "";
          };
      self.__singleton__ = true;
      self.__init__ = function () {
        var rollList = $("#rollList"),
            lists = $("li", rollList),
            that = this,
            showCaseEvent,
            privateVar;
        privates(this, {
          rollList : rollList,
          lists : lists,
          listCounts : lists.length,
          maxWidth : LIST_SIZE * lists.length,
          windowWidth : $(window).width(),
          prevent : false,
          title : $("#title"),
          tools : $("#tools"),
          showCase : $("#showCase"),
          bigImage : $("#bigImage"),
          pbar : $("#progressBar"),
          name : $("#infoName"),
          about : $("#infoAbout"),
          use : $("#infoUse")
        });
        calcCenter.call(this);
        privateVar = privates(this);
        $(window).bind("resize", function () {
          privateVar.windowWidth = $(window).width();
          privateVar.rollList.removeClass(LARGE_CLASS).removeClass(SEMI_LARGE_CLASS);
          calcCenter.call(this);
        }.bind(this));
        showCaseEvent = EventDelegator("click", privateVar.rollList);
        $("#close").bind("click", function () {
          privateVar.showCase.fadeOut(600);
          privateVar.bigImage.find("img.imageData").remove();
        });
        showCaseEvent.addDelegator({
          type : "class",
          name : "showDetail",
          eventType : "click",
          reciever : function (e) {
            e.preventDefault();
            that.showDetail($(this));
          }
        });
      };
      self.prev = function (mul) {
        mul = (typeof (mul) === "number")? mul : 1;
        var privateVar = privates(this),
            index = privateVar.currentLarge,
            left = parseFloat(privateVar.rollList.css("marginLeft")) + (LIST_SIZE * mul),
            that = this;
        if (privateVar.prevent === true) {
          return false;
        }
        $("#rollList li").removeClass(LARGE_CLASS).removeClass(SEMI_LARGE_CLASS);
        privateVar.prevent = true;
        privateVar.rollList.animate({
          "marginLeft" : left
        }, 500, function () {
          privateVar.rollList.css("marginLeft", left + (mul * LIST_SIZE));
          setCenterClass((index + mul));
          for (var i = 0; i < mul; ++i) {
            privateVar.rollList.prepend($("#rollList li").eq(privateVar.listCounts + 1));
          }
          setText(privateVar);
          privateVar.prevent = false;
        });
      };
      self.next = function (mul) {
        mul = (typeof (mul) === "number")? mul : 1;
        var privateVar = privates(this),
            index = privateVar.currentLarge,
            left = parseFloat(privateVar.rollList.css("marginLeft")) + (mul * LIST_SIZE),
            that = this;
        if (privateVar.prevent === true) {
          return false;
        }
        $("#rollList li").removeClass(LARGE_CLASS).removeClass(SEMI_LARGE_CLASS);
        privateVar.prevent = true;
        privateVar.rollList.animate({
          "marginLeft" : left
        }, 500, function () {
          privateVar.rollList.css("marginLeft", left + (mul * LIST_SIZE));
          setCenterClass((index + mul));
          privateVar.currentLarge = index;
          for (var i = 0; i < mul; ++i) {
            privateVar.rollList.append($("#rollList li").eq(0));
          }
          setText(privateVar);
          privateVar.prevent = false;
        });
      };
      self.showDetail = function (target) {
        target = (target[0].nodeName === "LI")? target : target.parents("li");
        if (target.hasClass(LARGE_CLASS)) {
          var privateVar = privates(this),
              urlData = target.attr("url-data").split(","),
              info = Info().get()[urlData[1]];
          privateVar.name.html(info.name);
          privateVar.about.html(info.about);
          privateVar.use.html(info.use);
          privateVar.pbar.show();
          privateVar.showCase.height($(document).height() + 150).fadeIn(600, function () {
            loadImage({
              src : urlData[0]
            }, function (image) {
              privateVar.pbar.fadeOut(200, function () {
                image.style.display = "none";
                privateVar.bigImage.append(image);
                $(image).fadeIn(200);
              });
            });
          });
        } else {
          var privateVar = privates(this),
              index = target.index(),
              diff = privateVar.currentLarge + index;
          if (diff < 0) {
            diff = diff * -1;
            this.next(diff);
          } else {
            this.prev(diff);
          }
        }
      };
    });
    
    return exports;
  })();
  __global_exports["/var/samba/back/mocha/test/3rd-modules/Base.js"] = (function(){
    var exports = {};
    Class("Base")(function (self, privates) {
      self.__static__.init = function () {
        $("img[src*=_off]").bind("mouseover", function () {
          this.src = this.src.replace("_off", "_on");
        }).bind("mouseout", function () {
          this.src = this.src.replace("_on", "_off");
        });
      };
    });
    
    return exports;
  })();
})();