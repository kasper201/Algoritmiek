#include "driverinfo.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <curl/curl.h>
#include <algorithm>

std::string requestPath()
{
    std::string path;
    std::cout << "Enter the path to the JSON file: ";
    std::cin >> path;
    return path;
}

driverinfo::driverinfo()
{

}

driverinfo::~driverinfo()
{
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output)
{
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

std::string driverinfo::getRequest(const std::string &url) {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    std::string response;

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return response;
}

int driverinfo::driver() {
    // Specify the path to your JSON file
    std::string filePath = "C:\\Users\\Kasper\\Downloads\\Agoritmiek\\.idea\\httpRequests\\2024-02-26T141655.200.json";

    filePath = requestPath();

    // Read JSON data from file
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string jsonData = buffer.str();

    // Parse JSON
    std::istringstream stream(jsonData);
    std::vector<std::string> givenNames, familyNames, nationalities, permanentNumbers, fullNames;
    while (stream) {
        std::string token;
        stream >> token;
        if (token == "\"givenName\":") {
            std::string givenName;
            stream >> std::quoted(givenName);
            givenNames.push_back(givenName);
        } else if (token == "\"familyName\":") {
            std::string familyName;
            stream >> std::quoted(familyName);
            familyNames.push_back(familyName);
        } else if (token == "\"nationality\":") {
            std::string nationality;
            stream >> std::quoted(nationality);
            nationalities.push_back(nationality);
        } else if(token == "\"permanentNumber\":") {
            std::string permanentNumber;
            stream >> std::quoted(permanentNumber);
            permanentNumbers.push_back(permanentNumber);
        }
    }

    for(int i = 0; i < familyNames.size(); i++) {
        getTeam(familyNames[i]);
    }

    // Print names and nationalities
    for (size_t i = 0; i < givenNames.size(); ++i) {
        fullNames.push_back(givenNames[i] + " " + familyNames[i]);
        std::cout << i << " - Nationality: " << nationalities[i] << " full name: " << fullNames[i] << " Permanent number: " << permanentNumbers[i] << " Team: " << teams[familyNames[i]][i] << std::endl;
    }

    return 0;
}

void driverinfo::getTeam(std::string driver) {
    std::replace(driver.begin(), driver.end(), ' ', '_');
    std::string url = "http://ergast.com/api/f1/drivers/" + driver + "/constructors.json";
    std::cout << "URL: " << url << std::endl;
    std::string response = getRequest(url);
    std::cout << response << std::endl;

    std::istringstream stream(response);
    while (stream) {
        std::string token;
        stream >> token;
        if (token == "\"name\":") {
            std::string team;
            stream >> std::ws;
            stream >> std::quoted(team);
            teams[driver].push_back(team);
            std::cout << "Team: " << team << std::endl;
            std::cout << "Team: " << teams[driver].back() << std::endl;
        }
    }

    for (size_t i = 0; i < teams[driver].size(); i++) {
        std::cout << "Team: " << teams[driver][i] << std::endl;
    };
}