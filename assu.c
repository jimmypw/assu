#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *concatenate(size_t size, char *array[size], const char *joint){
    size_t jlen, lens[size];
    size_t i, total_size = (size-1) * (jlen=strlen(joint)) + 1;
    char *result, *p;


    for(i=0;i<size;++i){
        total_size += (lens[i]=strlen(array[i]));
    }
    p = result = malloc(total_size);
    for(i=0;i<size;++i){
        memcpy(p, array[i], lens[i]);
        p += lens[i];
        if(i<size-1){
            memcpy(p, joint, jlen);
            p += jlen;
        }
    }
    *p = '\0';
    return result;
}

int main(int argc, char * argv[]) {
    char **newargv = &argv[1];
    int newargc = argc - 1;
    char *command = NULL;
    
    command = concatenate(newargc, newargv, " ");
    
    seteuid(0);
    setuid(0);
    system(command);
    
    memset(command, 0, strlen(command));
    free(command);
    command = NULL;
}

