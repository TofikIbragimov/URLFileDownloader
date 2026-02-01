#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <queue>
#include <regex>
#include <string>
#include <thread>
#include <vector>

namespace fs = std::filesystem;

void printHelp() {
    std::cerr << "Usage: .\\URLFileDownloader [OPTIONS] [FILE_PATH] [FOLDER_PATH] [NUMBER_OF_THREADS]" << std::endl
              << "Options:" << std::endl
              << "  -h, --help     Show this help message" << std::endl;
}

std::string now_time() {
    using namespace std::chrono;
    auto tp = system_clock::now();
    auto t = system_clock::to_time_t(tp);
    auto ms = duration_cast<milliseconds>(tp.time_since_epoch()) % 1000;

    std::tm tm{};
#ifdef _WIN32
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S")
        << "." << std::setw(3) << std::setfill('0') << ms.count();
    return oss.str();
}

void log(const std::string& msg) {
    std::cout << "[" << now_time() << "] " << msg << std::endl;
}

std::string sanitize_filename(const std::string& name) {
    static const std::regex invalid(R"([<>:"/\\|?*\x00-\x1F])");
    return std::regex_replace(name, invalid, "_");
}

fs::path make_unique_path(const fs::path& dir, const std::string& filename) {
    fs::path p = dir / filename;
    if (!fs::exists(p))
        return p;

    std::string stem = p.stem().string();
    std::string ext = p.extension().string();

    for (int i = 1;; ++i) {
        fs::path candidate = dir / (stem + "(" + std::to_string(i) + ")" + ext);
        if (!fs::exists(candidate))
            return candidate;
    }
}

int main(int argc, char* argv[]) {
    try {
        for (int i = 1; i < argc; i++)
        {
            std::string arg = argv[i];
            if (arg == "--help" || arg == "-h") {
                printHelp();
                return 0;
            } 
        }
        if (argc != 4) {
            std::cerr << "ERROR!!!" << std::endl;
            printHelp();
            return 1;
        }

        fs::path url_file = argv[1];
        fs::path out_dir = argv[2];
        int threads = std::stoi(argv[3]);

        log("Program started");
        log("URL file: " + url_file.string());
        log("Output dir: " + out_dir.string());
        log("Threads: " + std::to_string(threads));

        fs::create_directories(out_dir);

        
    } catch (const std::exception& e) {
        log(std::string("Fatal error: ") + e.what());
        return 1;
    }
}