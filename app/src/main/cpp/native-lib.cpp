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

// Last segment of the native method name must be the same
// as the name of the "external" method in Java/Kotlin.
// First part of the name is the FULL name of the class
// that contains the "external" method.
// JNIEnv points to helper functions.
// jobject is an instance of the class that contains "external" method.

// To pass parameters between Java/Kotlin and native methods
// we must use special types (jint, jdouble, jboolean etc).
extern "C" JNIEXPORT jint JNICALL
Java_com_gpetuhov_android_samplendk_MainActivity_addFromJNI(
        JNIEnv *env,
        jobject /* this */,
        jint x,
        jint y) {
    return x + y;
}

#endif // MY_INCLUDES