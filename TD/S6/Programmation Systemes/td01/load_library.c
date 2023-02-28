#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

static void *handle;
void (*sort_handler)(int [], int);

void load_library(char *library_name) {
    handle = dlopen(library_name,RTLD_LAZY);
    char *error;

    if(!handle){
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    dlerror();

    *(void **) (&sort_handler) = dlsym(handle,"sort");

    error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }
}

void clean_library() {
    dlclose(handle);
}

void sort(int list[], int size) {
    sort_handler(list,size);
}