#ifndef RAMENGINE_UTILS_HPP
#define RAMENGINE_UTILS_HPP

std::filesystem::path Utils::exePath;

void Utils::setExePath(const char* path){

    exePath = std::filesystem::path(path);

}

std::filesystem::path Utils::getExePath(){

    return exePath;

}

std::string Utils::getPath(const char* path){

    std::string filePath = exePath.parent_path() / path;

    return filePath;

}


#endif //RAMENGINE_UTILS_HPP
