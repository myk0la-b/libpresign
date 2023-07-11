#include "module.h"


extern "C" {
    static PyObject *
    get(PyObject *self, PyObject *args, PyObject *kwargs) {
        char *access_key_id = (char*) malloc(sizeof(char) * 100);
        char *secret_access_key = (char*) malloc(sizeof(char) * 200);
        char *bucket = (char*) malloc(sizeof(char) * 100);
        char *key = (char*) malloc(sizeof(char) * 100);
        char *region = (char*) malloc(sizeof(char) * 100);
        unsigned int expires = 3600;

        region = (char*)"us-east-1";

        static char *kwlist[] = {(char*)"access_key_id", (char*)"secret_access_key", (char*)"bucket", (char*)"key", (char*)"region", (char*)"expires",  NULL};

        if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ssss|sI:libpresign.get", kwlist, &access_key_id, &secret_access_key, &bucket, &key, &region, &expires)) {
            printf("error");
            return PyUnicode_FromString("None");
        }

        return PyUnicode_FromString(generatePresignedURL(access_key_id, secret_access_key, region, bucket, key, expires).c_str());
    }
}