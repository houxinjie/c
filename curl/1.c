#include <stdio.h>
#include <curl/curl.h>

int main(void){
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_PROXY, "127.0.0.1:8890");
        curl_easy_setopt(curl, CURLOPT_URL, "http://fe.qiyi.domain:8867/works/574ea9d2e08b091842a52f21");
        res = curl_easy_perform(curl);

        /*
        if(CURLE_OK == res){
            char *ct;
            res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
            if((CURLE_OK == res) && ct){
                printf("We received Content-Type: %s\n", ct);
            }
        }
        */

        curl_easy_cleanup(curl);

    }

    return 0;

}
