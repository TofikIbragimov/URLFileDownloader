#include <iostream>
#include "asio.hpp"

class FileDownloader {
private:
    std::string url;

public:
    FileDownloader(const std::string& url) : url(url) {}


    std::string get_url() {return url;}
    void set_url() {}
    
};