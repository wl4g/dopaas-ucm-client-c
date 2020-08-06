#include <stdio.h>

#include "scm_client.h"

//#define BASE_URL "http://scm.sunwuu.uat:14043//scm-server/watch?cluster=nginx&instance.host=127.0.0.1&instance.endpoint=8080"
//#define BASE_URL "http://localhost:14043/scm-server/watch?cluster=nginx&instance.host=127.0.0.1&instance.endpoint=8080"
#define BASE_URL "https://www.zhihu.com/api/v4/questions/323921618/answers"

//TODO refresh
void refresh(char* result){
    printf("refresh success: %s",result);

    cJSON *root = cJSON_Parse(result);
    //printf("%s\n",cJSON_Print(root));

    cJSON *paging = cJSON_GetObjectItem(root, "paging");
    //printf("result: \n%s\n", cJSON_Print(paging));

    int totals = cJSON_GetObjectItem(paging, "totals")->valueint;
    //printf("%d\n", totals);

    cJSON_Delete(root);

}


int main() {
    watch(BASE_URL,refresh);
    return 0;
}



