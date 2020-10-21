注意 MAC 编译遇到 jni_md.h 找不到需要将该头文件拷贝到 jni.h 目录，示例命令：
sudo cp /Library/Java/JavaVirtualMachines/jdk1.7.0_72.jdk/Contents/Home/include/darwin/jni_md.h /Library/Java/JavaVirtualMachines/jdk1.7.0_72.jdk/Contents/Home/include
