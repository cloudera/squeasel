// Some portions Copyright (c) 2004-2012 Sergey Lyubka
// Some portions Copyright (c) 2013 Cloudera Inc.
// This file is a part of squeasel project, https://github.com/cloudera/squeasel

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#include <io.h>
#define strtoll strtol
typedef __int64 int64_t;
#else
#include <inttypes.h>
#include <unistd.h>
#endif // !_WIN32

#include "squeasel.h"

static int begin_request_handler(struct sq_connection *conn) {
  if (!strcmp(sq_get_request_info(conn)->uri, "/handle_post_request")) {
    sq_printf(conn, "%s", "HTTP/1.0 200 OK\r\n\r\n");
    sq_upload(conn, "/tmp");
  } else {
    // Show HTML form. Make sure it has enctype="multipart/form-data" attr.
    static const char *html_form =
      "<html><body>Upload example."
      "<form method=\"POST\" action=\"/handle_post_request\" "
      "  enctype=\"multipart/form-data\">"
      "<input type=\"file\" name=\"file\" /> <br/>"
      "<input type=\"submit\" value=\"Upload\" />"
      "</form></body></html>";

    sq_printf(conn, "HTTP/1.0 200 OK\r\n"
              "Content-Length: %d\r\n"
              "Content-Type: text/html\r\n\r\n%s",
              (int) strlen(html_form), html_form);
  }

  // Mark request as processed
  return 1;
}

static void upload_handler(struct sq_connection *conn, const char *path) {
  sq_printf(conn, "Saved [%s]", path);
}

int main(void) {
  struct sq_context *ctx;
  const char *options[] = {"listening_ports", "8080", NULL};
  struct sq_callbacks callbacks;

  memset(&callbacks, 0, sizeof(callbacks));
  callbacks.begin_request = begin_request_handler;
  callbacks.upload = upload_handler;
  ctx = sq_start(&callbacks, NULL, options);
  getchar();  // Wait until user hits "enter"
  sq_stop(ctx);

  return 0;
}
