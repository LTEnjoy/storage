(function(){/* 
 
 Copyright The Closure Library Authors. 
 SPDX-License-Identifier: Apache-2.0 
*/ 
function aa(a){var b=0;return function(){return b<a.length?{done:!1,value:a[b++]}:{done:!0}}}function m(a){var b="undefined"!=typeof Symbol&&Symbol.iterator&&a[Symbol.iterator];return b?b.call(a):{next:aa(a)}}function ba(a){if(!(a instanceof Array)){a=m(a);for(var b,c=[];!(b=a.next()).done;)c.push(b.value);a=c}return a} 
function da(a){a=["object"==typeof window&&window,"object"==typeof self&&self,"object"==typeof global&&global,a];for(var b=0;b<a.length;++b){var c=a[b];if(c&&c.Math==Math)return c}return globalThis}var ea=da(this),fa="function"==typeof Object.defineProperties?Object.defineProperty:function(a,b,c){a!=Array.prototype&&a!=Object.prototype&&(a[b]=c.value)}; 
function ha(a,b){if(b){var c=ea;a=a.split(".");for(var d=0;d<a.length-1;d++){var e=a[d];e in c||(c[e]={});c=c[e]}a=a[a.length-1];d=c[a];b=b(d);b!=d&&null!=b&&fa(c,a,{configurable:!0,writable:!0,value:b})}}ha("globalThis",function(a){return a||ea}); 
ha("String.prototype.startsWith",function(a){return a?a:function(b,c){if(null==this)throw new TypeError("The 'this' value for String.prototype.startsWith must not be null or undefined");if(b instanceof RegExp)throw new TypeError("First argument to String.prototype.startsWith must not be a regular expression");var d=this.length,e=b.length;c=Math.max(0,Math.min(c|0,this.length));for(var f=0;f<e&&c<d;)if(this[c++]!=b[f++])return!1;return f>=e}});var n=this||self; 
function q(a){var b=typeof a;if("object"==b)if(a){if(a instanceof Array)return"array";if(a instanceof Object)return b;var c=Object.prototype.toString.call(a);if("[object Window]"==c)return"object";if("[object Array]"==c||"number"==typeof a.length&&"undefined"!=typeof a.splice&&"undefined"!=typeof a.propertyIsEnumerable&&!a.propertyIsEnumerable("splice"))return"array";if("[object Function]"==c||"undefined"!=typeof a.call&&"undefined"!=typeof a.propertyIsEnumerable&&!a.propertyIsEnumerable("call"))return"function"}else return"null"; 
else if("function"==b&&"undefined"==typeof a.call)return"object";return b}function r(a){return"function"==q(a)}var ia="closure_uid_"+(1E9*Math.random()>>>0),ka=0,la=Date.now||function(){return+new Date};function t(a,b){function c(){}c.prototype=b.prototype;a.prototype=new c;a.prototype.constructor=a};var ma=Array.prototype.forEach?function(a,b){Array.prototype.forEach.call(a,b,void 0)}:function(a,b){for(var c=a.length,d="string"===typeof a?a.split(""):a,e=0;e<c;e++)e in d&&b.call(void 0,d[e],e,a)};function na(a,b){a:{for(var c=a.length,d="string"===typeof a?a.split(""):a,e=0;e<c;e++)if(e in d&&b.call(void 0,d[e],e,a)){b=e;break a}b=-1}return 0>b?null:"string"===typeof a?a.charAt(b):a[b]};function oa(a){var b=!1,c;return function(){b||(c=a(),b=!0);return c}};var u;a:{var qa=n.navigator;if(qa){var ra=qa.userAgent;if(ra){u=ra;break a}}u=""};function v(a,b){this.b=a===sa&&b||"";this.c=ta}v.prototype.f=!0;v.prototype.a=function(){return this.b.toString()};var ua=/^(?:(?:https?|mailto|ftp):|[^:/?#]*(?:[/?#]|$))/i;function va(a){if(a instanceof v)return a;a="object"==typeof a&&a.f?a.a():String(a);ua.test(a)||(a="about:invalid#zClosurez");return new v(sa,a)}var ta={},sa={};function wa(){return-1!=u.indexOf("iPhone")&&-1==u.indexOf("iPod")&&-1==u.indexOf("iPad")};function xa(a){xa[" "](a);return a}xa[" "]=function(){};var ya=wa(),za=-1!=u.indexOf("iPad");var Aa=wa()||-1!=u.indexOf("iPod"),Ba=-1!=u.indexOf("iPad");function w(a,b){this.b=a;this.f=b;this.a={};this.c=!0;if(0<this.b.length){for(a=0;a<this.b.length;a++){b=this.b[a];var c=b[0];this.a[c.toString()]=new Ca(c,b[1])}this.c=!0}}w.prototype.h=function(){if(this.c){if(this.f){var a=this.a,b;for(b in a)if(Object.prototype.hasOwnProperty.call(a,b)){var c=a[b].a;c&&c.h()}}}else{this.b.length=0;a=x(this);a.sort();for(b=0;b<a.length;b++){var d=this.a[a[b]];(c=d.a)&&c.h();this.b.push([d.key,d.value])}this.c=!0}return this.b};function A(a){this.a=0;this.b=a} 
A.prototype.next=function(){return this.a<this.b.length?{done:!1,value:this.b[this.a++]}:{done:!0,value:void 0}};"undefined"!=typeof Symbol&&(A.prototype[Symbol.iterator]=function(){return this});w.prototype.entries=function(){var a=[],b=x(this);b.sort();for(var c=0;c<b.length;c++){var d=this.a[b[c]];a.push([d.key,B(this,d)])}return new A(a)};w.prototype.keys=function(){var a=[],b=x(this);b.sort();for(var c=0;c<b.length;c++)a.push(this.a[b[c]].key);return new A(a)}; 
w.prototype.values=function(){var a=[],b=x(this);b.sort();for(var c=0;c<b.length;c++)a.push(B(this,this.a[b[c]]));return new A(a)};function Da(a,b){var c=x(a);c.sort();for(var d=0;d<c.length;d++){var e=a.a[c[d]];b.call(void 0,B(a,e),e.key,a)}}w.prototype.set=function(a,b){var c=new Ca(a);this.f?(c.a=b,c.value=b.h()):c.value=b;this.a[a.toString()]=c;this.c=!1;return this};function B(a,b){return a.f?(b.a||(b.a=new a.f(b.value)),b.a):b.value} 
w.prototype.get=function(a){if(a=this.a[a.toString()])return B(this,a)};w.prototype.has=function(a){return a.toString()in this.a};function x(a){a=a.a;var b=[],c;for(c in a)Object.prototype.hasOwnProperty.call(a,c)&&b.push(c);return b}function Ca(a,b){this.key=a;this.value=b;this.a=void 0};function C(){}var Ea="function"==typeof Uint8Array;function D(a,b,c){a.a=null;b||(b=[]);a.o=void 0;a.f=-1;a.b=b;a:{if(b=a.b.length){--b;var d=a.b[b];if(!(null===d||"object"!=typeof d||Array.isArray(d)||Ea&&d instanceof Uint8Array)){a.g=b-a.f;a.c=d;break a}}a.g=Number.MAX_VALUE}a.i={};if(c)for(b=0;b<c.length;b++)d=c[b],d<a.g?(d+=a.f,a.b[d]=a.b[d]||E):(Fa(a),a.c[d]=a.c[d]||E)}var E=[];function Fa(a){var b=a.g+a.f;a.b[b]||(a.c=a.b[b]={})} 
function F(a,b){if(b<a.g){b+=a.f;var c=a.b[b];return c===E?a.b[b]=[]:c}if(a.c)return c=a.c[b],c===E?a.c[b]=[]:c}function G(a,b,c){a=F(a,b);return null==a?c:a}function H(a,b){a=F(a,b);a=null==a?a:!!a;return null==a?!1:a}function I(a,b,c){a.a||(a.a={});if(b in a.a)return a.a[b];var d=F(a,b);d||(d=[],J(a,b,d));return a.a[b]=new w(d,c)}function J(a,b,c){b<a.g?a.b[b+a.f]=c:(Fa(a),a.c[b]=c)}function Ga(a){var b=Ha;a.a||(a.a={});if(!a.a[8]){var c=F(a,8);c&&(a.a[8]=new b(c))}return a.a[8]} 
function Ia(a){if(a.a)for(var b in a.a){var c=a.a[b];if("array"==q(c))for(var d=0;d<c.length;d++)c[d]&&c[d].h();else c&&c.h()}}C.prototype.h=function(){Ia(this);return this.b};C.prototype.toString=function(){Ia(this);return this.b.toString()}; 
function K(a){if(Array.isArray(a)){for(var b=Array(a.length),c=0;c<a.length;c++){var d=a[c];null!=d&&(b[c]="object"==typeof d?K(d):d)}return b}if(Ea&&a instanceof Uint8Array)return new Uint8Array(a);b={};for(c in a)d=a[c],null!=d&&(b[c]="object"==typeof d?K(d):d);return b};function Ja(a){D(this,a,null)}t(Ja,C);function L(a){D(this,a,Ka)}t(L,C);function Ha(a){D(this,a,null)}t(Ha,C);var Ka=[6,7];function La(a){D(this,a,Ma)}t(La,C);var Ma=[7];var M=document,N=window;var Na={capture:!0},Oa={passive:!0},Pa=oa(function(){var a=!1;try{var b=Object.defineProperty({},"passive",{get:function(){a=!0}});n.addEventListener("test",null,b)}catch(c){}return a});function Qa(a){return a?a.passive&&Pa()?a:a.capture||!1:!1}function P(a,b,c,d){a.addEventListener&&a.addEventListener(b,c,Qa(d))}function Ra(a,b,c){a.removeEventListener&&a.removeEventListener(b,c,Qa(void 0))};function Sa(a,b,c){if(Array.isArray(b))for(var d=0;d<b.length;d++)Sa(a,String(b[d]),c);else null!=b&&c.push(a+(""===b?"":"="+encodeURIComponent(String(b))))};function Q(a){try{var b;if(b=!!a&&null!=a.location.href)a:{try{xa(a.foo);b=!0;break a}catch(c){}b=!1}return b}catch(c){return!1}}function Ta(a,b){if(a)for(var c in a)Object.prototype.hasOwnProperty.call(a,c)&&b.call(void 0,a[c],c,a)}function Ua(a){"complete"===M.readyState||"interactive"===M.readyState?a():M.addEventListener("DOMContentLoaded",a)};function R(a,b,c){Va(a,b,void 0===c?null:c)}function Va(a,b,c){a.google_image_requests||(a.google_image_requests=[]);var d=a.document.createElement("img");if(c){var e=function(f){c&&c(f);Ra(d,"load",e);Ra(d,"error",e)};P(d,"load",e);P(d,"error",e)}d.src=b;a.google_image_requests.push(d)};var Wa=/^((market|itms|intent|itms-appss):\/\/)/i;function S(a,b,c){b=b instanceof v||!Wa.test(b)?b:new v(sa,b);"about:invalid#zClosurez"===(b instanceof v?b:va(b)).a()&&c(String(b));c=b instanceof v?b:va(b);c instanceof v&&c.constructor===v&&c.c===ta?c=c.b:(q(c),c="type_error:SafeUrl");a.href=c} 
function T(a){var b=(Xa()?"http:":"https:")+"//pagead2.googlesyndication.com/pagead/gen_204";return function(c){c={id:"unsafeurl",ctx:a,url:c};var d=[];for(e in c)Sa(e,c[e],d);var e=d.join("&");if(e){c=b.indexOf("#");0>c&&(c=b.length);d=b.indexOf("?");if(0>d||d>c){d=c;var f=""}else f=b.substring(d+1,c);c=[b.substr(0,d),f,b.substr(c)];d=c[1];c[1]=e?d?d+"&"+e:e:d;e=c[0]+(c[1]?"?"+c[1]:"")+c[2]}else e=b;navigator.sendBeacon&&navigator.sendBeacon(e,"")}};function Xa(){var a=void 0===a?N:a;return"http:"===a.location.protocol}var Ya=!!window.google_async_iframe_id,U=Ya&&window.parent||window;function Za(a){try{return M.querySelectorAll("*["+a+"]")}catch(b){return[]}};function $a(a,b){var c=void 0===c?{}:c;this.error=a;this.context=b.context;this.msg=b.message||"";this.id=b.id||"jserror";this.meta=c};var ab=/^https?:\/\/(\w|-)+\.cdn\.ampproject\.(net|org)(\?|\/|$)/;function bb(a,b){this.a=a;this.b=b}function cb(a,b){this.url=a;this.s=!!b;this.depth=null};function db(){this.c="&";this.f=!1;this.b={};this.g=0;this.a=[]}function eb(a,b){var c={};c[a]=b;return[c]}function fb(a,b,c,d,e){var f=[];Ta(a,function(h,k){(h=gb(h,b,c,d,e))&&f.push(k+"="+h)});return f.join(b)} 
function gb(a,b,c,d,e){if(null==a)return"";b=b||"&";c=c||",$";"string"==typeof c&&(c=c.split(""));if(a instanceof Array){if(d=d||0,d<c.length){for(var f=[],h=0;h<a.length;h++)f.push(gb(a[h],b,c,d+1,e));return f.join(c[d])}}else if("object"==typeof a)return e=e||0,2>e?encodeURIComponent(fb(a,b,c,d,e+1)):"...";return encodeURIComponent(String(a))}function V(a,b,c,d){a.a.push(b);a.b[b]=eb(c,d)} 
function ib(a,b,c){b=b+"//pagead2.googlesyndication.com"+c;var d=jb(a)-c.length;if(0>d)return"";a.a.sort(function(p,y){return p-y});c=null;for(var e="",f=0;f<a.a.length;f++)for(var h=a.a[f],k=a.b[h],g=0;g<k.length;g++){if(!d){c=null==c?h:c;break}var l=fb(k[g],a.c,",$");if(l){l=e+l;if(d>=l.length){d-=l.length;b+=l;e=a.c;break}a.f&&(e=d,l[e-1]==a.c&&--e,b+=l.substr(0,e),e=a.c,d=0);c=null==c?h:c}}a="";null!=c&&(a=e+"trn="+c);return b+a} 
function jb(a){var b=1,c;for(c in a.b)b=c.length>b?c.length:b;return 3997-b-a.c.length-1};function kb(){this.b=Xa()?"http:":"https:";this.a=Math.random()}function lb(){var a=W,b=X.google_srt;0<=b&&1>=b&&(a.a=b)}function nb(a,b,c,d,e,f){if((d?a.a:Math.random())<(e||.01))try{if(c instanceof db)var h=c;else h=new db,Ta(c,function(g,l){var p=h,y=p.g++;g=eb(l,g);p.a.push(y);p.b[y]=g});var k=ib(h,a.b,"/pagead/gen_204?id="+b+"&");k&&("undefined"===typeof f?R(n,k):R(n,k,f))}catch(g){}};var ob=null;function pb(){var a=n.performance;return a&&a.now&&a.timing?Math.floor(a.now()+a.timing.navigationStart):la()}function qb(){var a=void 0===a?n:a;return(a=a.performance)&&a.now?a.now():null};function rb(a,b,c){this.label=a;this.type=b;this.value=c;this.duration=0;this.uniqueId=Math.random();this.slotId=void 0};var Y=n.performance,sb=!!(Y&&Y.mark&&Y.measure&&Y.clearMarks),Z=oa(function(){var a;if(a=sb){var b;if(null===ob){ob="";try{a="";try{a=n.top.location.hash}catch(c){a=n.location.hash}a&&(ob=(b=a.match(/\bdeid=([\d,]+)/))?b[1]:"")}catch(c){}}b=ob;a=!!b.indexOf&&0<=b.indexOf("1337")}return a}); 
function tb(){var a=X;this.b=[];this.c=a||n;var b=null;a&&(a.google_js_reporting_queue=a.google_js_reporting_queue||[],this.b=a.google_js_reporting_queue,b=a.google_measure_js_timing);this.a=Z()||(null!=b?b:1>Math.random())}function ub(a){a&&Y&&Z()&&(Y.clearMarks("goog_"+a.label+"_"+a.uniqueId+"_start"),Y.clearMarks("goog_"+a.label+"_"+a.uniqueId+"_end"))} 
tb.prototype.start=function(a,b){if(!this.a)return null;var c=qb()||pb();a=new rb(a,b,c);b="goog_"+a.label+"_"+a.uniqueId+"_start";Y&&Z()&&Y.mark(b);return a};function vb(){var a=wb;this.c=W;this.b=null;this.i=this.g;this.a=void 0===a?null:a;this.f=!1}vb.prototype.pinger=function(){return this.c}; 
function xb(a,b,c){try{if(a.a&&a.a.a){var d=a.a.start(b.toString(),3);var e=c();var f=a.a;c=d;if(f.a&&"number"===typeof c.value){var h=qb()||pb();c.duration=h-c.value;var k="goog_"+c.label+"_"+c.uniqueId+"_end";Y&&Z()&&Y.mark(k);!f.a||2048<f.b.length||f.b.push(c)}}else e=c()}catch(g){f=!0;try{ub(d),f=a.i(b,new $a(g,{message:yb(g)}),void 0,void 0)}catch(l){a.g(217,l)}if(!f)throw g;}return e} 
function zb(a,b){var c=Ab;return function(d){for(var e=[],f=0;f<arguments.length;++f)e[f]=arguments[f];return xb(c,a,function(){return b.apply(void 0,e)})}} 
vb.prototype.g=function(a,b,c,d,e){e=e||"jserror";try{var f=new db;f.f=!0;V(f,1,"context",a);b.error&&b.meta&&b.id||(b=new $a(b,{message:yb(b)}));b.msg&&V(f,2,"msg",b.msg.substring(0,512));var h=b.meta||{};if(this.b)try{this.b(h)}catch(ca){}if(d)try{d(h)}catch(ca){}b=[h];f.a.push(3);f.b[3]=b;d=n;b=[];h=null;do{var k=d;if(Q(k)){var g=k.location.href;h=k.document&&k.document.referrer||null}else g=h,h=null;b.push(new cb(g||""));try{d=k.parent}catch(ca){d=null}}while(d&&k!=d);g=0;for(var l=b.length-1;g<= 
l;++g)b[g].depth=l-g;k=n;if(k.location&&k.location.ancestorOrigins&&k.location.ancestorOrigins.length==b.length-1)for(l=1;l<b.length;++l){var p=b[l];p.url||(p.url=k.location.ancestorOrigins[l-1]||"",p.s=!0)}var y=new cb(n.location.href,!1);k=null;var pa=b.length-1;for(p=pa;0<=p;--p){var z=b[p];!k&&ab.test(z.url)&&(k=z);if(z.url&&!z.s){y=z;break}}z=null;var Ob=b.length&&b[pa].url;0!=y.depth&&Ob&&(z=b[pa]);var O=new bb(y,z);O.b&&V(f,4,"top",O.b.url||"");V(f,5,"url",O.a.url||"");nb(this.c,e,f,this.f, 
c)}catch(ca){try{nb(this.c,e,{context:"ecmserr",rctx:a,msg:yb(ca),url:O&&O.a.url},this.f,c)}catch(Vb){}}return!0};function yb(a){var b=a.toString();a.name&&-1==b.indexOf(a.name)&&(b+=": "+a.name);a.message&&-1==b.indexOf(a.message)&&(b+=": "+a.message);if(a.stack){a=a.stack;try{-1==a.indexOf(b)&&(a=b+"\n"+a);for(var c;a!=c;)c=a,a=a.replace(/((https?:\/..*\/)[^\/:]*:\d+(?:.|\n)*)\2/,"$1");b=a.replace(/\n */g,"\n")}catch(d){}}return b};var W,Ab,Bb;if(Ya&&!Q(U)){var Cb="."+M.domain;try{for(;2<Cb.split(".").length&&!Q(U);)M.domain=Cb=Cb.substr(Cb.indexOf(".")+1),U=window.parent}catch(a){}Q(U)||(U=window)}var X=U,wb=new tb;function Db(){if(!X.google_measure_js_timing){var a=wb;a.a=!1;a.b!=a.c.google_js_reporting_queue&&(Z()&&ma(a.b,ub),a.b.length=0)}} 
(function(){W=new kb;"number"!==typeof X.google_srt&&(X.google_srt=Math.random());lb();Ab=new vb;Ab.b=function(b){var c=N.jerExpIds;if("array"==q(c)&&0!==c.length){var d=b.eid;if(d){c=ba(d.split(",")).concat(ba(c));d={};for(var e=0,f=0;f<c.length;){var h=c[f++];var k=h;var g=typeof k;k="object"==g&&null!=k||"function"==g?"o"+(Object.prototype.hasOwnProperty.call(k,ia)&&k[ia]||(k[ia]=++ka)):(typeof k).charAt(0)+k;Object.prototype.hasOwnProperty.call(d,k)||(d[k]=!0,c[e++]=h)}c.length=e;b.eid=c.join(",")}else b.eid= 
c.join(",")}Bb&&(b.jc=Bb);(c=N.jerUserAgent)&&(b.useragent=c)};Ab.f=!0;"complete"==X.document.readyState?Db():wb.a&&P(X,"load",function(){Db()});var a=M.currentScript;Bb=a?a.dataset.jc:""})();function Eb(a,b){return zb(a,b)}function Fb(a){nb(W,"gdn-asoch",a,!0,void 0,void 0)};function Gb(a){if(!a||/[?&]dsh=1(&|$)/.test(a))return null;if(/[?&]ae=1(&|$)/.test(a)){var b=/[?&]adurl=([^&]+)/.exec(a);if(!b)return null;var c=b.index;try{return{l:a.slice(0,c)+"&act=1"+a.slice(c),finalUrl:decodeURIComponent(b[1])}}catch(e){return null}}if(0<a.indexOf("&ae=2")){b=a;c="";var d=a.indexOf("&adurl=");0<d&&(b=a.slice(0,d),c=a.slice(d));return{l:b+"&act=1"+c,finalUrl:b+"&dct=1"+c}}return null};function Hb(a){var b=Ib(a.href);S(a,b.j,T(599))}function Ib(a){var b=Gb(a);return b?navigator.sendBeacon?navigator.sendBeacon(Jb(b.l,"&ri=1"),"")?{j:b.finalUrl,m:!0}:{j:Jb(a,"&ri=2"),m:!1}:{j:Jb(a,"&ri=16"),m:!1}:{j:a,m:!1}}function Jb(a,b){var c=a.search(/&adurl=/);return 0>c?a+b:a.slice(0,c)+b+a.slice(c)};function Kb(a,b){b=G(a,2,"")||b;if(!b)return"";var c=/[?&]adurl=([^&]+)/.exec(b);if(!c)return b;var d=[b.slice(0,c.index+1)];Da(I(a,4,null),function(e,f){d.push(encodeURIComponent(f)+"="+encodeURIComponent(e)+"&")});d.push(b.slice(c.index+1));return d.join("")} 
function Lb(a){var b=Za("data-asoch-targets");a=I(a,1,L);for(var c=[],d=0;d<b.length;++d){for(var e=b[d].getAttribute("data-asoch-targets"),f=e.split(","),h=!0,k=m(f),g=k.next();!g.done;g=k.next())if(!a.has(g.value)){h=!1;break}if(h){h=a.get(f[0]);for(e=1;e<f.length;++e){k=a.get(f[e]);h=(new h.constructor(K(h.h()))).h();k=k.h();g=Math.max(h.length,k.length);for(var l=0;l<g;++l)null==h[l]&&(h[l]=k[l]);h=new L(h)}f=I(h,4,null);null!=F(h,5)&&f.set("nb",G(h,5,0).toString());c.push({element:b[d],data:h})}else Fb({type:1, 
data:e})}return c}function Mb(a){a=m(a);for(var b=a.next();!b.done;b=a.next()){var c=b.value;b=c.data;if("A"==c.element.tagName&&!H(b,1)){c=c.element;var d=Kb(b,c.href);0<d.length&&(S(c,d,T(609)),c.target||(c.target=null!=F(b,11)?G(b,11,""):"_top"))}}};function Nb(){var a=this,b=Za("data-asoch-meta");1!==b.length?Fb({type:2,data:b.length}):(this.b=new La(JSON.parse(b[0].getAttribute("data-asoch-meta"))||[]),this.a=Lb(this.b),this.f=-Infinity,this.c=G(this.b,5,"")||"",this.u=!1,this.o=Aa||ya||Ba||za,this.i=this.g=null,H(this.b,3)||(Mb(this.a),J(this.b,3,!0)),Pb(this.a),P(M,"click",Eb(557,function(c){a:if(!c.defaultPrevented||a.g===c){for(var d,e,f=c.target;(!d||!e)&&f;){e||"A"!=f.tagName||(e=f);if(!d&&("A"==f.tagName||f.hasAttribute("data-asoch-targets"))){var h= 
Qb(a.a,f);h&&(d=h.data)}f=f.parentElement}if(f=d&&!H(d,1)){if(c.defaultPrevented){f=d;if(a.g===c&&a.i){h=new Ja(a.i);d=G(f,9,"");var k="";switch(G(h,4,1)){case 2:if(G(h,2,0))k="blocked_fast_click";else if(G(h,1,"")||G(h,7,""))k="blocked_border_click";break;case 3:var g=void 0===g?M:g;g=g.getElementById?g.getElementById("common_15click_anchor"):null;r(window.copfcChm)&&g&&(f=new f.constructor(K(f.h())),J(f,5,12),I(f,4,null).set("nb",(12).toString()),(h=Qb(a.a,g))?h.data=f:a.a.push({element:g,data:f}), 
e&&(Rb(a,c,e,f),J(f,2,e.href)),window.copfcChm(c,Kb(f,g.href)));k="onepointfiveclick_first_click"}d&&k&&Sb(d+"&label="+k)}break a}g=m(F(d,6));for(h=g.next();!h.done;h=g.next())Sb(h.value)}if(e&&f){g=e;e=f?d:null;(d=Qb(a.a,g))?d=d.data:(d=new L,J(d,2,g.href),J(d,11,g.target||"_top"),a.a.push({element:g,data:d}));d=Kb(e||d,G(d,2,""));0<d.length&&(S(g,d,T(557)),g.target||(g.target=e&&null!=F(e,11)?G(e,11,""):"_top"));H(a.b,9)?(d=g.href,d=(f=/[?&]adurl=([^&]+)/.exec(d))?[d.slice(0,f.index),d.slice(f.index)]: 
[d,""],S(g,d[0],T(557)),Rb(a,c,g,e),S(g,g.href+d[1],T(557))):Rb(a,c,g,e);d=(f=H(a.b,2))&&300<Date.now()-a.f;if(window.oneAfmaInstance)b:{c.preventDefault?c.preventDefault():c.returnValue=!1,c=window.oneAfmaInstance,g=c.appendClickSignals(g.href),g=c.logScionEventAndAddParam(g);if(e&&null!=F(e,8)&&(h=Ga(e),a.o&&H(h,5)&&null!=F(h,4))){c.click(g);c.openInAppStore(G(h,4,""));break b}e&&null!=F(e,8)&&Tb(g,e,c)||(f&&(f=g,g=c.click,(e=Gb(f))?(d&&(f=e.l,h=f.search(/&adurl=/),g(0>h?f+"&ri=1":f.slice(0,h)+ 
"&ri=1"+f.slice(h))),g=e.finalUrl):g=f),g.startsWith("intent:")?c.openIntentOrNativeApp(g):c.openSystemBrowser(g,{useFirstPackage:!0,useRunningProcess:!0}))}else d&&(c=H(a.b,8),e=a.f,c?300>Date.now()-(void 0===e?-1:e)||((c=g.getAttribute("data-orig-async-clicktrack-url"))?(c=Ib(c),S(g,c.j,T(599))):(g.setAttribute("data-orig-async-clicktrack-url",g.href),Hb(g))):Hb(g));d&&(a.f=Date.now())}}}),Na),this.c&&r(window.ss)&&P(M.body,"mouseover",Eb(626,function(){window.ss(a.c,0)}),Oa),window.googqscp&&r(window.googqscp.registerCallback)&& 
window.googqscp.registerCallback(function(c,d){a.g=c;a.i=d}))}function Rb(a,b,c,d){for(var e;!c.id;)if(e="asoch-id-"+(Math.floor(2147483648*Math.random()).toString(36)+Math.abs(Math.floor(2147483648*Math.random())^la()).toString(36)),!M.getElementById(e)){c.id=e;break}e=c.id;r(window.xy)&&window.xy(b,c,M.body);r(window.mb)&&window.mb(c);r(window.bgz)&&window.bgz(e);r(window.ja)&&window.ja(e,d?G(d,5,0):0);a.c&&r(window.ss)&&(a.u?window.ss(e,1,a.c):window.ss(a.c,1))} 
function Ub(){Ua(Eb(556,function(){new Nb}))}function Sb(a){N.fetch?N.fetch(a,{method:"GET",keepalive:!0,mode:"no-cors"}).then(function(b){b.ok||R(N,a)}):R(N,a)} 
function Tb(a,b,c){var d=Ga(b),e=G(d,2,"");Da(I(b,10,null),function(f,h){var k=e;h=encodeURIComponent(h);var g=encodeURIComponent(f);f=new RegExp("[?&]"+h+"=([^&]+)");var l=f.exec(k);console.log(l);h=h+"="+g;e=l?k.replace(f,l[0].charAt(0)+h):k.replace("?","?"+h+"&")});return c.redirectForStoreU2({clickUrl:a,trackingUrl:G(d,3,""),finalUrl:e,pingFunc:c.click,openFunc:c.openIntentOrNativeApp})}function Qb(a,b){return na(a,function(c){return c.element===b})} 
function Pb(a){a=m(a);for(var b=a.next();!b.done;b=a.next()){var c=b.value;"A"==c.element.tagName&&(b=c.element,c=c.data,null==F(c,2)&&J(c,2,b.href))}};Eb(555,function(){return Ub()})();}).call(this);
