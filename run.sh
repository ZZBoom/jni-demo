g++ -dynamiclib -std=c++11 jni_hello.cc -I /Library/Java/JavaVirtualMachines/jdk1.8.0_202.jdk/Contents/Home/include -o libhello.dylib
javac HelloMain.java
java HelloMain
