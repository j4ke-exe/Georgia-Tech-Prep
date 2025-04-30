#include "http.h"
#include <stdio.h>

char *http_to_str(HttpErrorCode code) {
  switch (code) {
    case HTTP_BAD_REQUEST:
      return "400 Bad Request";
    case HTTP_UNAUTHORIZED:
      return "401 Unauthorized";
    case HTTP_NOT_FOUND:
      return "404 Not Found";
    case HTTP_TEAPOT:
      return "418 I AM A TEAPOT!";
    case HTTP_INTERNAL_SERVER_ERROR:
      return "500 Internal Server Error";
    default:
      return "Unknown HTTP status code";
  }
}
