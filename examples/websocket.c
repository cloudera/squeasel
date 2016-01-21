// Some portions Copyright (c) 2004-2012 Sergey Lyubka
// Some portions Copyright (c) 2013 Cloudera Inc.
// This file is a part of squeasel project, https://github.com/cloudera/squeasel

#include <stdio.h>
#include <string.h>
#include "squeasel.h"

static void websocket_ready_handler(struct sq_connection *conn) {
  static const char *message = "server ready";
  sq_websocket_write(conn, WEBSOCKET_OPCODE_TEXT, message, strlen(message));
}

// Arguments:
//   flags: first byte of websocket frame, see websocket RFC,
//          http://tools.ietf.org/html/rfc6455, section 5.2
//   data, data_len: payload data. Mask, if any, is already applied.
static int websocket_data_handler(struct sq_connection *conn, int flags,
                                  char *data, size_t data_len) {
  (void) flags; // Unused
  sq_websocket_write(conn, WEBSOCKET_OPCODE_TEXT, data, data_len);

  // Returning zero means stoping websocket conversation.
  // Close the conversation if client has sent us "exit" string.
  return memcmp(data, "exit", 4);
}

int main(void) {
  struct sq_context *ctx;
  struct sq_callbacks callbacks;
  const char *options[] = {
    "listening_ports", "8080",
    "document_root", "websocket_html_root",
    NULL
  };

  memset(&callbacks, 0, sizeof(callbacks));
  callbacks.websocket_ready = websocket_ready_handler;
  callbacks.websocket_data = websocket_data_handler;
  ctx = sq_start(&callbacks, NULL, options);
  getchar();  // Wait until user hits "enter"
  sq_stop(ctx);

  return 0;
}
