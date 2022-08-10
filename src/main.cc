#include "echo.h"

#include "gflags/gflags.h"
#include "muduo/base/Logging.h"
#include "muduo/net/EventLoop.h"

#include <unistd.h>

DEFINE_int32(http_port, 0, "http port number");

int main(int argc, char* argv[]) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  LOG_INFO << "pid = " << getpid() << ", http_port = " << FLAGS_http_port;
  muduo::net::EventLoop loop;
  muduo::net::InetAddress listenAddr(FLAGS_http_port);
  EchoServer server(&loop, listenAddr);
  server.start();
  loop.loop();
}