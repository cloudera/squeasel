# Note on fork

This is a fork of Mongoose, branched at the last commit of Mongoose that
was released as MIT license. Newer versions of Mongoose are now licensed
as GPLv2, so we cannot use them in our projects.

If you are developing this fork, please *do not* look at any upstream
Mongoose development.

If you are migrating from the original Mongoose project, you can define
MONGOOSE_COMPATIBLE before including squeasel.h, and the original names
of the APIs will continue to work.

Windows support has been removed.

# Project Mission

Project mission is to provide easy to use, powerful, embeddable web server.

# Overview

Squeasel keeps the balance between functionality and
simplicity by carefully selected list of features:

- Liberal, commercial-friendly
  [MIT license](http://en.wikipedia.org/wiki/MIT_License)
- Works on Windows, Mac, UNIX, iPhone, Android, and many other platforms
- Scripting and database support (Lua Server Pages + Sqlite, see
  [page.lp](https://github.com/cloudera/squeasel/blob/master/test/page.lp) ),
  which provides ready to go, powerful web development platform in
  one single-click executable with **no dependencies**: forget LAMP!
- Support for CGI, SSL, SSI, Digest (MD5) authorization, Websocket, WEbDAV
- Resumed download, URL rewrite, file blacklist, IP-based ACL, Windows service
- Download speed limit based on client subnet or URI pattern
- Simple and clean embedding API,
  [squeasel.h](https://github.com/cloudera/squeasel/blob/master/squeasel.h).
  The source is in single
  [squeasel.c](https://github.com/cloudera/squeasel/blob/master/squeasel.c) file
  to make things easy. Embedding examples:
  [hello.c](https://github.com/cloudera/squeasel/blob/master/examples/hello.c),
  [post.c](https://github.com/cloudera/squeasel/blob/master/examples/post.c),
  [upload.c](https://github.com/cloudera/squeasel/blob/master/examples/upload.c),
  [websocket.c](https://github.com/cloudera/squeasel/blob/master/examples/websocket.c)
- HTTP client capable of sending arbitrary HTTP/HTTPS requests
- [User Manual](https://github.com/cloudera/squeasel/blob/master/UserManual.md)

Note that Windows and MacOS binaries have following 3rd party software
compiled in:
  <a href="http://wolfssl.com">WolfSSL lightweight SSL library</a>,
  <a href="http://sqlite.org">SQLite embedded database</a>,
  <a href="http://lua.org">Lua embedded scripting engine</a>.
