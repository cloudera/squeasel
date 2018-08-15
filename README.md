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

# How do I contribute code?
You need to first sign and return an
[ICLA](https://github.com/cloudera/native-toolchain/blob/icla/Cloudera%20ICLA_25APR2018.pdf)
and
[CCLA](https://github.com/cloudera/native-toolchain/blob/icla/Cloudera%20CCLA_25APR2018.pdf)
before we can accept and redistribute your contribution. Once these are submitted you are
free to start contributing to squeasel. Submit these to CLA@cloudera.com.

## Find
We use Github issues to track bugs for this project. Find an issue that you would like to
work on (or file one if you have discovered a new issue!). If no-one is working on it,
assign it to yourself only if you intend to work on it shortly.

It’s a good idea to discuss your intended approach on the issue. You are much more
likely to have your patch reviewed and committed if you’ve already got buy-in from the
squeasel community before you start.

## Fix
Now start coding! As you are writing your patch, please keep the following things in mind:

First, please include tests with your patch. If your patch adds a feature or fixes a bug
and does not include tests, it will generally not be accepted. If you are unsure how to
write tests for a particular component, please ask on the issue for guidance.

Second, please keep your patch narrowly targeted to the problem described by the issue.
It’s better for everyone if we maintain discipline about the scope of each patch. In
general, if you find a bug while working on a specific feature, file a issue for the bug,
check if you can assign it to yourself and fix it independently of the feature. This helps
us to differentiate between bug fixes and features and allows us to build stable
maintenance releases.

Finally, please write a good, clear commit message, with a short, descriptive title and
a message that is exactly long enough to explain what the problem was, and how it was
fixed.

Please create a pull request on github with your patch.
