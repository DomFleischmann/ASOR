#include <iostream>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <pwd.h>

void error1() {
    int err;
    if((err = setuid(0)) != 0){
        std::cout << "ERROR err: "<< 
            err << " errno: " << strerror(errno) << "\n";
    }
}

void uname() {
    int err;
    utsname buf;
    if((err = uname(&buf)) != 0){
        std::cout << "ERROR err: "<< 
            err << " errno: " << strerror(errno) << "\n";
    } else {
        std::cout << buf.version << "\n";
    }
}

void mostrarErrores(){
    for(int i = 0; i < 255; i++){
        std::cout << i << " " << strerror(i) << "\n";
    }
}

void sysconf() {
    long ret;
    if((ret = sysconf(_SC_ARG_MAX)) == -1){
        std::cout << "ERROR err: "<< 
            ret << " errno: " << strerror(errno) << "\n";
    } else {
        std::cout << "ARG_MAX: " << ret << "\n";
    }

    if((ret = sysconf(_SC_CHILD_MAX)) == -1){
        std::cout << "ERROR err: "<< 
            ret << " errno: " << strerror(errno) << "\n";
    } else {
        std::cout << "CHILD_MAX: " << ret << "\n";
    }

    if((ret = sysconf(_SC_OPEN_MAX)) == -1){
        std::cout << "ERROR err: "<< 
            ret << " errno: " << strerror(errno) << "\n";
    } else {
        std::cout << "OPEN_MAX: " << ret << "\n";
    }
}

void pathconf() {
    long ret;
    if((ret = pathconf("/",_PC_LINK_MAX)) == -1){
         std::cout << "ERROR err: "<< 
            ret << " errno: " << strerror(errno) << "\n";
    } else {
        std::cout << "LNK_MAX: " << ret << "\n";
    }

    if((ret = pathconf("/",_PC_PATH_MAX)) == -1){
        std::cout << "ERROR err: "<< 
            ret << " errno: " << strerror(errno) << "\n";
    } else {
        std::cout << "PATH_MAX: " << ret << "\n";
    }

    if((ret = pathconf("/",_PC_NAME_MAX)) == -1){
        std::cout << "ERROR err: "<< 
            ret << " errno: " << strerror(errno) << "\n";
    } else {
        std::cout << "NAME_MAX: " << ret << "\n";
    }

}

void getuid1(){
    uid_t uid;
    if((uid = getuid()) == -1){
         std::cout << "ERROR err: "<< 
            uid << " errno: " << strerror(errno) << "\n";
    } else {
        std::cout << "UID: " << getpwuid(uid) << "\n";
    } 
}


int main() {
    getuid1();
    return 1;
}