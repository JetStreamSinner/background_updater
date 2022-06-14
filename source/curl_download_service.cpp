#include "curl_download_service.h"
#include <cstring>
#include <curl/curl.h>

struct MemoryStructure {
    char * buffer;
    size_t size;
};

std::size_t write_callback(void * content_buffer, std::size_t size, std::size_t nmemb, void * target_buffer) {
    std::size_t reallocate_size = size * nmemb;

    MemoryStructure * memory = (MemoryStructure *)target_buffer;

    char * updated_buffer = (char*)realloc(memory->buffer, memory->size + reallocate_size + 1);

    if (!updated_buffer) {
        // Not enough memory
        return 0;
    }

    memory->buffer = updated_buffer;
    std::memcpy(&(memory->buffer[memory->size]), content_buffer, reallocate_size);
    memory->size += reallocate_size;
    memory->buffer[memory->size] = 0;

    return reallocate_size;
}


CURLDownloadService::CURLDownloadService(const std::string &url) {
    set_source(url);
}

void CURLDownloadService::set_source(const std::string &url) {
    _url = url;
}

std::string CURLDownloadService::get_source() const {
    return _url;
}

std::string CURLDownloadService::get_image_data() const {
    CURL * curl_handle = curl_easy_init();
    if (curl_handle) {
        CURLcode result;
        MemoryStructure chunk;
        chunk.buffer = (char*)malloc(1);
        chunk.size = 0;
        curl_easy_setopt(curl_handle, CURLOPT_URL, _url.c_str());
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void*)&chunk);
        curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

        result = curl_easy_perform(curl_handle);

        std::string output(chunk.buffer, chunk.size - 1);

        curl_easy_cleanup(curl_handle);
        free(chunk.buffer);
        return output;
    }
    return "";
}