#include <jni.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "Bypass.h" 

const char* MY_SERIAL = "GE4H45ZTTKH6Q4J7"; // आपका सीरियल लॉक

void* Bikash_Private_Thread(void*) {
    sleep(15); // 15 सेकंड का डिले
    Disable_Garena_Log(); 
    Apply_Features();      
    return NULL;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_bikash_panel_MainActivity_StartPanel(JNIEnv* env, jobject thiz, jstring deviceSerial) {
    const char *serial = env->GetStringUTFChars(deviceSerial, 0);
    if (strcmp(serial, MY_SERIAL) == 0) {
        pthread_t ptid;
        pthread_create(&ptid, NULL, Bikash_Private_Thread, NULL);
        return env->NewStringUTF("Access Granted: Welcome Vikas Sir");
    } else {
        return env->NewStringUTF("Access Denied");
    }
}
