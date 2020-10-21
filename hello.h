#include <cstdio>
#include <string>

enum MsgType { Warn, Info };

struct Msg {
  std::string mInfo;
  MsgType mType;
};

class Hello {
public:
  Hello(Msg msg) : msg_(msg) {}
  void print() {
    if (msg_.mType == MsgType::Info) {
      printf("info\n");
    } else if (msg_.mType == MsgType::Warn) {
      printf("Warn\n");
    } else {
      printf("Not known\n");
    }
    printf("info: %s\n", msg_.mInfo.c_str());
  }

private:
  Msg msg_;
};
