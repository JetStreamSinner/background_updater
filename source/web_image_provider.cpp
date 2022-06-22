#include "web_image_provider.h"
#include "utils.h"
#include <cstring>
#include <curl/curl.h>
#include <sstream>

struct MemoryStructure {
    char *buffer;
    size_t size;
};

std::size_t write_callback(void *content_buffer, std::size_t size, std::size_t nmemb, void *target_buffer) {
    std::size_t reallocate_size = size * nmemb;

    MemoryStructure *memory = (MemoryStructure *) target_buffer;

    char *updated_buffer = (char *) realloc(memory->buffer, memory->size + reallocate_size + 1);

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


WebImageProvider::WebImageProvider(const std::string &url) {
    set_source(url);
}

void WebImageProvider::set_source(const std::string &url) {
    _url = url;
}

std::string WebImageProvider::get_source() const {
    return _url;
}

Image WebImageProvider::get_image_data() const {
    CURL *curl_handle = curl_easy_init();

    if (!curl_handle) {
        throw std::runtime_error(error_formatter("Cannot create curl handle"));
    }

    CURLcode result;
    MemoryStructure chunk;
    chunk.buffer = (char *) malloc(1);
    chunk.size = 0;
    curl_easy_setopt(curl_handle, CURLOPT_URL, _url.c_str());
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *) &chunk);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    result = curl_easy_perform(curl_handle);
    curl_easy_cleanup(curl_handle);

    const bool chunk_empty = chunk.size == 0;
    if (chunk_empty) {
        free(chunk.buffer);
        return Image();
    }

    BytesArray image_buffer(chunk.buffer, chunk.size);
    Image output(image_buffer);
    free(chunk.buffer);
    return output;
}