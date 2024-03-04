//
// Created by flits on 3/3/24.
//

#include "CircuitInfo.h"
#include "getImage.h"

#include <iostream>
#include <curl/curl.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cctype>


CircuitInfo::CircuitInfo() {

}

CircuitInfo::~CircuitInfo() {

}

int CircuitInfo::circuit() {
    std::string url = "https://ergast.com/api/f1/2023/circuits.json";
    std::string response = getRequest(url);
    std::cout << "Response: " << response << std::endl;

    // Correct JSON for readability
    std::string correctedJson = correctJson(response);

    std::ofstream fileSave("tempCircuit.json", std::ios::trunc);
    fileSave << correctedJson;
    fileSave.close();

    // Read JSON data from file
    std::ifstream file("tempCircuit.json");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string data = buffer.str();

    // Parse JSON
    std::istringstream stream(data);
    std::vector<std::string> circuit, country, circuitLength;
    while(stream) { // iterate through the JSON data
        std::string token;
        stream >> token;
        if(token == "\"circuitId\":") {
            std::string circuitId;
            stream >> std::quoted(circuitId);
            circuit.push_back(circuitId);
            std::cout << "Circuit ID: " << circuitId << std::endl;
        } else if(token == "\"country\":") {
            std::string countryName;
            stream >> std::quoted(countryName);
            country.push_back(countryName);
            std::cout << "Country: " << countryName << std::endl;
        }
    }
    for(int i = 0; i < circuit.size(); i++) {
        circuitImage(getF1CircuitName(i, 2023));

        circuitLength.push_back(findCircuitLength(i, 2023));
    }

    for(int i = 0; i < circuit.size(); i++) {
        std::cout << "Circuit: " << circuit[i] << std::endl;
        std::cout << "Country: " << country[i] << std::endl;
        std::cout << "Circuit length: " << circuitLength[i] << std::endl;
    }

    return 0;
}

std::string CircuitInfo::findInHtml(std::string html) { // find the length of the circuit in the html page of the circuit on the F1 website
    std::string extracted_data;
    // Find the position of the starting and ending substrings
    size_t start_pos = html.find("<p class=\"f1-bold--stat\">");
    size_t end_pos = html.find("<span class=\"misc--label\">");

    // Check if both substrings are found
    if (start_pos != std::string::npos && end_pos != std::string::npos) {
        // Extract the data between the substrings
        extracted_data = html.substr(start_pos + sizeof("<p class=\"misc--label\">Circuit Length</p><p class=\"f1-bold--stat\">") - 1,
                                                  end_pos - (start_pos + sizeof("<p class=\"f1-bold--stat\">") - 1));

        std::cout << "Extracted data: " << extracted_data << std::endl;
    } else {
        std::cout << "Substrings not found in the input string." << std::endl;
    }
    return extracted_data;
}

std::string capitaliseFirstLetter(const std::string& input) {
    if (!input.empty()) {
        std::string result = input;
        result[0] = std::toupper(static_cast<unsigned char>(result[0]));

        return result;
    } else {
        return input;  // Return empty string if input is empty
    }
}

std::string CircuitInfo::getF1CircuitName(int circuitNr, int year)
{
    std::string circuitName;
    std::string url = "https://www.formula1.com/en/racing/" + std::to_string(year) + ".html";
    std::string html = getRequest(url);
    //std::cout << "Response: " << html << std::endl;

    size_t start_pos = 0;
    size_t end_pos = 0;
    int i = 0;
    while(i <= circuitNr + 1) // + 1 because the first circuit is testing
    {
        start_pos = html.find("<a href=\"/en/racing/" + std::to_string(year) + "/", end_pos);
        end_pos = html.find(".html\"", start_pos);
        circuitName = html.substr(start_pos + sizeof("<a href=\"/en/racing/2023/") - 1, end_pos - (start_pos + sizeof("<a href=\"/en/racing/2023/") - 1)); // 2023 can be used here since it doesn't matter for the length
        i++;
    }

    return circuitName;
}

std::string CircuitInfo::findCircuitLength(int circuitNr, int year) {
    std::cout << "Circuit number: " << circuitNr << std::endl;
    std::string circuitName = getF1CircuitName(circuitNr, year);
    std::cout << "Circuit name: " << circuitName << std::endl;
    std::string circuitUrl = "https://www.formula1.com/en/racing/2023/" + circuitName + "/Circuit.html";
    std::string html = getRequest(circuitUrl);
    std::cout << "Circuit URL: " << circuitUrl << std::endl;

    return findInHtml(html);
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

int CircuitInfo::circuitImage(std::string circuit) {
    std::string url = "https://media.formula1.com/image/upload/f_auto/q_auto/v1677244985/content/dam/fom-website/2018-redesign-assets/Circuit%20maps%2016x9/" + circuit + "_Circuit.png.transform/7col/image.png";
    getImage image;
    image.getTheImage(url, circuit);
    return 0;
}

std::string CircuitInfo::correctJson(const std::string& input) {
    std::istringstream stream(input);
    std::ostringstream beautified;

    int indentLevel = 0;
    char ch;

    while (stream.get(ch)) {
        switch (ch) {
            case '{':
            case '[':
                beautified << ch << "\n" << std::setw(++indentLevel * 2) << "";
                break;
            case '}':
            case ']':
                beautified << "\n" << std::setw(--indentLevel * 2) << "" << ch;
                break;
            case ',':
                beautified << ch << "\n" << std::setw(indentLevel * 2) << "";
                break;
            case ':':
                beautified << ": ";
                break;
            default:
                beautified << ch;
        }
    }

    return beautified.str();
}