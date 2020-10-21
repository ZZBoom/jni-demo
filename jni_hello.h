#include <cstdio> // C++ standard IO header
#include <jni.h>  // JNI header provided by JDK

#include "hello.h"

std::string jstring2string(JNIEnv *env, jstring jstr) {
  if (!jstr) {
    return "";
  }

  const char *str = env->GetStringUTFChars(jstr, 0);
  if (str == nullptr) {
    return "";
  } else {
    std::string ret(str);
    env->ReleaseStringUTFChars(jstr, str);
    return ret;
  }
}


class JniHello {
public:
  JniHello(JNIEnv *env, jobject obj) {
    jclass clazz = env->GetObjectClass(obj);
    jfieldID config = env->GetFieldID(clazz, "mMsg", "LmMsg;");
    printf("Get config\n");

    if (config != nullptr) {
      jobject config_obj = env->GetObjectField(obj, config);
      jclass msg_clazz = env->GetObjectClass(config_obj);
      jfieldID msg_info_config =
          env->GetFieldID(clazz, "mInfo", "Ljava/lang/String;");
      jstring msg_jstr =
          static_cast<jstring>(env->GetObjectField(obj, msg_info_config));
      auto msg_str = jstring2string(env, msg_jstr);

      jfieldID msg_type_config = env->GetFieldID(clazz, "mInfo", "LMsgType;");
      int type = env->GetIntField(obj, msg_type_config);
      Msg msg = {.mInfo = msg_str, .mType = static_cast<MsgType>(type)};
      hello_ = new Hello(msg);
    }
  }
  void print() { hello_->print(); }

private:
  Hello *hello_;
};

class CachedJavaVM {
public:
  static CachedJavaVM &Instance() {
    static CachedJavaVM instance;
    return instance;
  }
  void SetVM(JavaVM *vm) { vm_ = vm; }
  JavaVM *VM() { return vm_; }

private:
  JavaVM *vm_;
};

jfieldID getHandleField(JNIEnv *env, jobject obj) {
  jclass c = env->GetObjectClass(obj);
  // J is the type signature for long:
  return env->GetFieldID(c, "mContext", "J");
}

template <typename T> T *getHandle(JNIEnv *env, jobject obj) {
  jlong handle = env->GetLongField(obj, getHandleField(env, obj));
  return reinterpret_cast<T *>(handle);
}

