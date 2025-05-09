#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include <string>     // Must come before any use of std::string
#include <memory>
#include <fstream>
#include <iostream>

namespace seneca {

    enum class PartOfSpeech {
        Unknown,
        Noun,
        Pronoun,
        Adjective,
        Adverb,
        Verb,
        Preposition,
        Conjunction,
        Interjection,
    };

    struct Word {
        std::string m_word;
        std::string m_definition;
        PartOfSpeech m_pos = PartOfSpeech::Unknown;
    };

    class Dictionary {
        std::unique_ptr<Word[]> wordArr;
        size_t wordCount{0};
    public:
        Dictionary();
        ~Dictionary();
        Dictionary(const char* filename);
        void searchWord(const std::string word);
        PartOfSpeech parsePOS(std::string& pos);

        Dictionary& operator=(Dictionary&& src) noexcept;
        Dictionary(Dictionary&& src) noexcept;
        Dictionary& operator=(const Dictionary& src);
        Dictionary(const Dictionary& src);
        void wrapper(const std::string& prefix, const std::string& text, size_t lineWidth = 80);
    };

}

#endif // SENECA_DICTIONARY_H
