#include <stdio.h>

#include "scm_client.h"
#include <sys/time.h>



typedef int (*callback)(char*);

/*
 * watch
 */
void watch(const char* url, callback p) {
    ft_http_client_t *client = http_init();
    while (1) {
        printf("%ld:%s %s\n", getCurrentTime(), "request start",url);
        char *result = ft_http_sync_request(client, url, M_GET);
        int status_code = ft_http_get_status_code(client);
        printf("%ld:%s statusCode:%d\n", getCurrentTime(), "request end", status_code);
        if (status_code == 200) {//OK
            (*p)(result);
        } else if (status_code == 103) {//CHECKPOINT
            //TODO
        } else if (status_code == 304) {//NOT_MODIFIED
            //TODO
        } else {
            break;
        }

        printf("%ld:%s\n", getCurrentTime(), "waiting......");
        usleep(10000000);
    }
    http_deinit(client);
}

/**
 * http init
 * @return
 */
ft_http_client_t* http_init(){
    ft_http_init();
    ft_http_client_t *client = ft_http_new();
    ft_http_set_timeout(client, 30000);//set time out
    return client;
}

/*
 * http deinit
 */
void http_deinit(ft_http_client_t *client){
    ft_http_destroy(client);
    ft_http_exit(client);
    ft_http_deinit();
}

long getCurrentTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}


