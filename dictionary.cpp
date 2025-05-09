#include "dictionary.h"
#include "settings.h"

namespace seneca {

    Dictionary::Dictionary() {}

    Dictionary::Dictionary(const char* filename) {
        Word w;

        std::ifstream eng_file;
        eng_file.open(filename);
        if(!eng_file.is_open()) {
            std::cerr << "ERROR OPENING FILE" << std::endl;
            return; //should put current function instance into empty state
        }

        std::string line{};
        while(std::getline(eng_file, line)) {
            wordCount++;
        }

        wordArr = std::make_unique<Word[]>(wordCount); //the size of the array is set
        eng_file.clear(); //reseting file state
        eng_file.seekg(0); //starting at top of file again

        int i{0};
        while (std::getline(eng_file, line) && i < wordCount) {
            size_t comma1 = line.find(',');
            size_t comma2 = line.find(',', comma1 + 1);

            if (comma1 != std::string::npos && comma2 != std::string::npos) {
                wordArr[i].m_word = line.substr(0, comma1);
                std::string posString = line.substr(comma1 + 1, comma2 - comma1 - 1);
                wordArr[i].m_definition = line.substr(comma2 + 1);
                
                wordArr[i].m_pos = parsePOS(posString);
            }
            i++;
        }
    }

    PartOfSpeech Dictionary::parsePOS(std::string& pos) {

        if(pos == "n." || pos == "n. pl.") { return PartOfSpeech::Noun; }
        if(pos == "adv.") { return PartOfSpeech::Adverb; }
        if(pos == "a.") { return PartOfSpeech::Adjective; }
        if(pos == "v." || pos == "v. i." || pos == "v. t." || pos == "v. t. & i.") { return PartOfSpeech::Verb; }
        if(pos == "prep.") { return PartOfSpeech::Preposition; }
        if(pos == "pron.") { return PartOfSpeech::Pronoun; }
        if(pos == "conj.") { return PartOfSpeech::Conjunction; }
        if(pos == "interj.") { return PartOfSpeech::Interjection; }

        return PartOfSpeech::Unknown;
    }

    void Dictionary::searchWord(const char* word) {
        bool found = false;
        std::string wordString = word; //to get number of chars word takes up
        size_t indentWord = wordString.length(); //getting length of word
        int matchCounter{ 0 };

        const char* posStrings[] = {
            "Unknown", "Noun", "Pronoun", "Adjective", "Adverb",
            "Verb", "Preposition", "Conjunction", "Interjection"
        };

        for(size_t i = 0; i < wordCount; i++) {
            if(wordArr[i].m_word == word) {
                found = true;
                if (matchCounter == 0) {
                    std::cout << wordArr[i].m_word;
                }
                else {
                    std::cout << std::string(indentWord, ' '); //printing blank word 
                }

                if (g_settings.m_verbose && wordArr[i].m_pos != PartOfSpeech::Unknown) { //only prints pos if known
                    std::cout << " - (" << posStrings[static_cast<int>(wordArr[i].m_pos)] << ")";
                }
                else {
                    std::cout << " -";
                }
                std::cout << " " << wordArr[i].m_definition << std::endl;

                if (!g_settings.m_show_all) {
                    break; //will only display the first definition if permitted
                }
                matchCounter++;
            }
        }

        if(!found) {
            std::cout << "Word '" << word << "' " << "was not found in the dictionary." << std::endl;
        }
    }

    Dictionary::~Dictionary() {}

    Dictionary::Dictionary(const Dictionary& src) : wordCount(src.wordCount) {
        wordArr = std::make_unique<Word[]>(wordCount);
        for (size_t i = 0; i < src.wordCount; ++i) { // Corrected loop condition
            wordArr[i].m_word = src.wordArr[i].m_word;
            wordArr[i].m_definition = src.wordArr[i].m_definition;
            wordArr[i].m_pos = src.wordArr[i].m_pos;
        }
    }

    Dictionary& Dictionary::operator=(const Dictionary& src) {
        if (this == &src) {
            return *this;
        }

        wordCount = src.wordCount;
        wordArr = std::make_unique<Word[]>(wordCount);
        for (size_t i = 0; i < src.wordCount; ++i) { // Corrected loop condition
            wordArr[i].m_word = src.wordArr[i].m_word;
            wordArr[i].m_definition = src.wordArr[i].m_definition;
            wordArr[i].m_pos = src.wordArr[i].m_pos;
        }
        return *this;
    }

    Dictionary::Dictionary(Dictionary&& src) noexcept : wordArr(std::move(src.wordArr)), wordCount(src.wordCount) {
        src.wordCount = 0;
    }

    Dictionary& Dictionary::operator=(Dictionary&& src) noexcept {
        if (this != &src) {
            wordArr = std::move(src.wordArr);
            wordCount = src.wordCount;
            src.wordCount = 0;
        }
        return *this;
    }

}

