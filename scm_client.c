#include <stdio.h>

#include "scm_client.h"
#include <sys/time.h>


//#define BASE_URL "http://scm.sunwuu.uat:14043//scm-server/watch?cluster=nginx&instance.host=127.0.0.1&instance.endpoint=8080"
//#define BASE_URL "http://localhost:14043/scm-server/watch?cluster=nginx&instance.host=127.0.0.1&instance.endpoint=8080"
#define BASE_URL "https://www.zhihu.com/api/v4/questions/323921618/answers"

void test2() {
    ft_http_init();
    ft_http_client_t *client = ft_http_new();
    ft_http_set_timeout(client, 30000);//set time out

    while (1) {

        printf("%ld:%s %s\n", getCurrentTime(), "request start",BASE_URL);
        char *result = ft_http_sync_request(client, BASE_URL, M_GET);
        int status_code = ft_http_get_status_code(client);

        printf("%ld:%s statusCode:%d\n", getCurrentTime(), "request end", status_code);
        if (status_code == 200) {//OK
            cJSON *root = cJSON_Parse(result);
            //printf("%s\n",cJSON_Print(root));

            cJSON *paging = cJSON_GetObjectItem(root, "paging");
            printf("result: \n%s\n", cJSON_Print(paging));

            int totals = cJSON_GetObjectItem(paging, "totals")->valueint;
            //printf("%d\n", totals);

            cJSON_Delete(root);
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


    ft_http_destroy(client);
    ft_http_exit(client);
    ft_http_deinit();

}

long getCurrentTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}


