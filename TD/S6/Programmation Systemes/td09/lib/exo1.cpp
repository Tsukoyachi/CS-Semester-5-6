#include <sys/types.h>
#include <unistd.h>
#include "exo1.h"

JNIEXPORT jint JNICALL Java_exo1_getPid(JNIEnv *, jclass) {
    return getpid();
}