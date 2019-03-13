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

// This native method calls Kotlin method
extern "C" JNIEXPORT void JNICALL
Java_com_gpetuhov_android_samplendk_MainActivity_calculate(
        JNIEnv *env,
        jobject pThis) {

    // jobject is the reference to the caller object (in this example - MainActivity)

    // This is our result. We have to pass it to Kotlin via callback.
    jint result = 156;

    // First, find MainActivity class
    jclass clazz = env->FindClass("com/gpetuhov/android/samplendk/MainActivity");

    // Then get ID of the method with "onCalculationsComplete" name.
    // (I)V means that method takes integer and returns void.
    jmethodID methodId = env->GetMethodID(clazz, "onCalculationsComplete", "(I)V");

    // And at last call this method
    env->CallVoidMethod(pThis, methodId, result);
}

#endif // MY_INCLUDES