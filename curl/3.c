#include <stdio.h>
#include <pthread.h>
#include <curl/curl.h>

#define NUMT 4

/*
  List of URLs to fetch.

  If you intend to use a SSL-based protocol here you MUST setup the OpenSSL
  callback functions as described here:

  http://www.openssl.org/docs/crypto/threads.html#DESCRIPTION

*/
const char * const urls[NUMT]= {
  "http://fe.qiyi.domain:8867/works/574ea9d2e08b091842a52f21",
};

static void *pull_one_url(void *url)
{
  CURL *curl;

  curl = curl_easy_init();
  curl_easy_setopt(curl, CURLOPT_PROXY, "127.0.0.1:8890");
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_perform(curl); /* ignores error */
  curl_easy_cleanup(curl);

  return NULL;
}


/*
   int pthread_create(pthread_t *new_thread_ID,
   const pthread_attr_t *attr,
   void * (*start_func)(void *), void *arg);
*/

int main(int argc, char **argv)
{
  pthread_t tid[NUMT];
  int i;
  int error;

  /* Must initialize libcurl before any threads are started */
  curl_global_init(CURL_GLOBAL_ALL);

  for(i=0; i< NUMT; i++) {
    error = pthread_create(&tid[i],
                           NULL, /* default attributes please */
                           pull_one_url,
                           (void *)urls[i]);
    if(0 != error)
      fprintf(stderr, "Couldn't run thread number %d, errno %d\n", i, error);
    else
      fprintf(stderr, "Thread %d, gets %s\n", i, urls[i]);
  }

  printf("helloworld!!!!!!!");

  /* now wait for all threads to terminate */
  for(i=0; i< NUMT; i++) {
    error = pthread_join(tid[i], NULL);
    fprintf(stderr, "Thread %d terminated\n", i);
  }

  return 0;
}
