//
// Created by flits on 3/3/24.
//

#include "CircuitInfo.h"
#include "getImage.h"

#include <iostream>
#include <curl/curl.h>
#include <algorithm>


CircuitInfo::CircuitInfo() {

}

CircuitInfo::~CircuitInfo() {

}

int CircuitInfo::circuit() {
    std::string circuit = "Saudi Arabia";
    // TODO: get all circuits in the order of the season
    if(getCircuit(circuit)) {
        std::cout << "Circuit not found" << std::endl;
    }

    return 0;
}

size_t WriteCallbackCircuit(void* contents, size_t size, size_t nmemb, std::string* output) // function to write the response from the API
{
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

std::string CircuitInfo::getRequest(const std::string &url) {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    std::string response;

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallbackCircuit);
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

std::string CircuitInfo::correctCircuit(const std::string& input) { // function to replace spaces with underscores
    std::string output = input;
    std::replace(output.begin(), output.end(), ' ', '_');
    return output;
}

int CircuitInfo::getCircuit(std::string circuit) {
    std::string correctedCircuit = correctCircuit(circuit);
    std::string url = "https://ergast.com/api/f1/circuits/" + correctedCircuit + ".json";
    std::cout << "URL: " << url << std::endl;
    std::string response = getRequest(url);

    circuitImage(correctedCircuit); // retrieve the image of the circuit
    return 0;
}

int CircuitInfo::circuitImage(std::string circuit) {
    std::string url = "https://media.formula1.com/image/upload/f_auto/q_auto/v1677244985/content/dam/fom-website/2018-redesign-assets/Circuit%20maps%2016x9/" + circuit + "_Circuit.png.transform/7col/image.png";
    getImage image;
    image.getTheImage(url, circuit);
    return 0;
}
