cmake_minimum_required(VERSION 3.14)
project(xcloud-devops-scm-client-c C)

set(CMAKE_C_STANDARD 99)
#set(CMAKE_CXX_STANDARD 11)

#[[add_library(xcloud-devops-scm-client-c scm_client.c scm_client.h
        http.c
        http.h
        http_parser.c
        http_parser.h
        krypton.c
        krypton.h)]]



set(SOURCE_FILES
        http
        http/http.h
        http/http.c
        http/http_parser.c
        http/http_parser.h
        http/krypton.c
        http/krypton.h
        http/cJSON.c
        http/cJSON.h
        http/api.c
        http/api.h
        scm_client.c
        scm_client.h
        test.c
        )

#add_executable(xcloud-devops-scm-client-test test.c)

add_executable(xcloud-devops-scm-client-c ${SOURCE_FILES})