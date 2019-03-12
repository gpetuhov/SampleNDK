// To prevent multiple includes we can wrap includes in ifndef - endif block
#ifndef MY_INCLUDES
#define MY_INCLUDES

// <file> - provided with compiler
// "file" - your own header files
#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_gpetuhov_android_samplendk_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jint JNICALL
Java_com_gpetuhov_android_samplendk_MainActivity_addFromJNI(
        JNIEnv *env,
        jobject /* this */,
        jint x,
        jint y) {
    return x + y;
}

#endif // MY_INCLUDES