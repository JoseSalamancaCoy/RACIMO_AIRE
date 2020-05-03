#include <stdio.h>
#include <curl/curl.h>
int main()
{
    printf("Hello World!\n");
    CURL *hnd = curl_easy_init();

    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(hnd, CURLOPT_URL, "http://racimo.mpsig.com:3000/racimohub/v013dev/datasets");

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Postman-Token: d75df676-a5e1-448a-8b70-177609f83454");
    headers = curl_slist_append(headers, "Cache-Control: no-cache");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

    curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, "{\n        \"id_estacion\": \"uis-10\",\n        \"nombre_estacion\": \"UIS-10\",\n        \"clase\": \"Calidad de Aire\",\n        \"tipo\": \"profesional de bajo costo\",\n        \"activa\": true,\n        \"id_red\": 1,\n        \"descripcion\": \"Estación de pruebas con José Luis\",\n        \"longitud\": \"-73.12194\",\n        \"latitud\": \"7.140129\",\n        \"mediciones\": [\n            {\n                \"fecha_hora_med\": \"2018-08-17T12:28:00.000Z\",\n                \"id_parametro\": \"h\",\n                \"valor\": 40\n            },\n            {\n                \"fecha_hora_med\": \"2018-08-17T12:28:00.000Z\",\n                \"id_parametro\": \"p\",\n                \"valor\": 565\n            },\n            {\n                \"fecha_hora_med\": \"2018-08-17T12:28:00.000Z\",\n                \"id_parametro\": \"t\",\n                \"valor\": 18.8\n            },\n            {\n                \"fecha_hora_med\": \"2018-08-17T12:28:00.000Z\",\n                \"id_parametro\": \"pm10\",\n                \"valor\": 10\n            },\n            {\n                \"fecha_hora_med\": \"2018-08-17T12:28:00.000Z\",\n                \"id_parametro\": \"pm25\",\n                \"valor\": 30\n            }\n        ]\n    }");

    CURLcode ret = curl_easy_perform(hnd);
    return 0;
}
