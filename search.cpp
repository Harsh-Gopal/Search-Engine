{\rtf1\ansi\ansicpg1252\cocoartf2757
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <iostream>\
#include <fstream>\
#include <string>\
#include <map>\
#include <vector>\
#include <algorithm>\
#include <sstream>\
\
// Function to tokenize a string into words\
std::vector<std::string> tokenize(const std::string& text) \{\
    std::vector<std::string> words;\
    std::istringstream iss(text);\
    std::string word;\
    while (iss >> word) \{\
        words.push_back(word);\
    \}\
    return words;\
\}\
\
int main() \{\
    std::map<std::string, std::vector<std::string>> index;\
\
    // Read and index web pages\
    std::string page1 = "This is the content of page 1. It contains some keywords like C++, search, and engine.";\
    std::string page2 = "Page 2 has different content with C++ examples and coding.";\
\
    index["page1"] = tokenize(page1);\
    index["page2"] = tokenize(page2);\
\
    while (true) \{\
        std::string query;\
        std::cout << "Enter a search query (or type 'exit' to quit): ";\
        std::getline(std::cin, query);\
\
        if (query == "exit") \{\
            break;\
        \}\
\
        std::vector<std::string> queryWords = tokenize(query);\
        std::map<std::string, int> resultScores;\
\
        // Perform a simple search by counting the number of matching words\
        for (const auto& entry : index) \{\
            int score = 0;\
            for (const std::string& queryWord : queryWords) \{\
                score += std::count(entry.second.begin(), entry.second.end(), queryWord);\
            \}\
            if (score > 0) \{\
                resultScores[entry.first] = score;\
            \}\
        \}\
\
        // Sort results by score\
        std::vector<std::pair<std::string, int>> results(resultScores.begin(), resultScores.end());\
        std::sort(results.begin(), results.end(), [](const auto& a, const auto& b) \{\
            return a.second > b.second;\
        \});\
\
        // Display search results\
        if (results.empty()) \{\
            std::cout << "No matching pages found." << std::endl;\
        \} else \{\
            std::cout << "Search results:" << std::endl;\
            for (const auto& result : results) \{\
                std::cout << result.first << " (Score: " << result.second << ")" << std::endl;\
            \}\
        \}\
    \}\
\
    return 0;\
\}\
}