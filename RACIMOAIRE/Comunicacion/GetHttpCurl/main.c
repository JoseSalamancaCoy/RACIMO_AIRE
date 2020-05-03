#include <stdio.h>
#include <curl/curl.h>

int main()
{
    CURL *hnd = curl_easy_init();

    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(hnd, CURLOPT_URL, "http://racimo.mpsig.com:3000/racimohub/v013dev/fechahora");

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Postman-Token: 6dee4892-6c57-4773-9135-c59e7593ffdd");
    headers = curl_slist_append(headers, "Cache-Control: no-cache");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);
    CURLcode ret = curl_easy_perform(hnd);
    curl_easy_cleanup(hnd);
    return ;
}
