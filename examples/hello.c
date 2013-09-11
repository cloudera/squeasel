#include <stdio.h>
#include <string.h>
#include "squeasel.h"

// This function will be called by squeasel on every new request.
static int begin_request_handler(struct sq_connection *conn) {
  const struct sq_request_info *request_info = sq_get_request_info(conn);
  char content[100];

  // Prepare the message we're going to send
  int content_length = snprintf(content, sizeof(content),
                                "Hello from squeasel! Remote port: %d",
                                request_info->remote_port);

  // Send HTTP reply to the client
  sq_printf(conn,
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: %d\r\n"        // Always set Content-Length
            "\r\n"
            "%s",
            content_length, content);

  // Returning non-zero tells squeasel that our function has replied to
  // the client, and squeasel should not send client any more data.
  return 1;
}

int main(void) {
  struct sq_context *ctx;
  struct sq_callbacks callbacks;

  // List of options. Last element must be NULL.
  const char *options[] = {"listening_ports", "8080", NULL};

  // Prepare callbacks structure. We have only one callback, the rest are NULL.
  memset(&callbacks, 0, sizeof(callbacks));
  callbacks.begin_request = begin_request_handler;

  // Start the web server.
  ctx = sq_start(&callbacks, NULL, options);

  // Wait until user hits "enter". Server is running in separate thread.
  // Navigating to http://localhost:8080 will invoke begin_request_handler().
  getchar();

  // Stop the server.
  sq_stop(ctx);

  return 0;
}
