//#include <iostream>

#include <vector>
#include <filesystem>
#include <iostream>

#define PRINT

namespace fs = std::filesystem;

std::vector<fs::path> get_paths() {
    fs::path dir = fs::current_path();
    std::vector<fs::path> files;

    for (const auto &entry : fs::directory_iterator(dir)) {
        // TODO: Format check
        if (entry.is_regular_file())
            files.push_back(entry);
    }

#ifdef PRINT
    std::cout << dir.generic_string() << ":" << std::endl;
#endif

    return files;
}

int main() {

    std::vector<fs::path> files = get_paths();

#ifdef PRINT
    for (int i = 0; i < files.size(); i++)
        std::cout << files.at(i).generic_string() << std::endl;
#endif

	return 0;
}