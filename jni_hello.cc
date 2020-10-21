#include "jni_hello.h"

JNIEXPORT jlong JNICALL Java_Jni_construct(JNIEnv *env, jobject obj) {
  auto hello = new JniHello(env, obj);
  printf("Construct hello object %p.\n", hello);
  return reinterpret_cast<jlong>(hello);
}

JNIEXPORT void JNICALL Java_Jni_print(JNIEnv *env, jobject obj) {
  auto hello = getHandle<JniHello>(env, obj);
  hello->print();
}

static JNINativeMethod methods[] = {
    {"construt", "()J", (void *)Java_Jni_construct},
    {"print", "()V", (void *)Java_Jni_print},
};

static int register_native_methods(JNIEnv *env, const char *className,
                                   JNINativeMethod *gMethods, int numMethods) {
  jclass clazz;
  clazz = env->FindClass(className);
  if (clazz == NULL) {
    return JNI_FALSE;
  }
  if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
    return JNI_FALSE;
  }
  return JNI_TRUE;
}

int register_natives(JNIEnv *env) {
  static const char *class_path_name = "HelloJni";
  if (!register_native_methods(env, class_path_name, methods,
                               sizeof(methods) / sizeof(methods[0]))) {
    return JNI_FALSE;
  }
  return JNI_TRUE;
}

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
  JNIEnv *env;
  if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
    return JNI_ERR;
  }

  if (register_natives(env) != JNI_TRUE) {
    return JNI_ERR;
  }

  printf("load library.\n");
  CachedJavaVM::Instance().SetVM(vm);

  return JNI_VERSION_1_6;
}
