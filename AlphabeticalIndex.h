#include "Page.h"
#include "Line.h"
#include "Book.h"

#include <string>
#include <sstream>

int defineNumberOfLines(int numberOfPage, int numberOfLines, int numberOfLinesInTheFirstPage, int numberOfLinesInTheTenthPage)
{
    int result = 0;
    if (numberOfPage == 1)
    {
        result = numberOfLinesInTheFirstPage;
    }
    else if (numberOfPage % 10 == 0)
    {
        result = numberOfLinesInTheTenthPage;
    }
    else
    {
        result = numberOfLines;
    }
    return result;
}

Book alphabeticalIndex(const std::string& input, int sizeOfLine, int numberOfLines) {
    Book book;
    Page page;
    Line line;

    std::istringstream wordsStream(input);
    std::string word;
    int currentLineLength = 0;
    int lineCount = 0;
    int pageCount = 1;

    int numberOfLinesInTheFirstPage = numberOfLines / 2;
    int numberOfLinesInTheTenthPage = 3 * numberOfLines / 4;
    int limitNumberOfLines = numberOfLinesInTheFirstPage;

    while (wordsStream >> word) {
        if (word.length() > sizeOfLine) {
            if (currentLineLength > 0) {
                page.append(line);
                lineCount++;
                line = Line();
                currentLineLength = 0;
            }
            for (size_t i = 0; i < word.length(); i += sizeOfLine) {
                std::string part = word.substr(i, sizeOfLine);
                line.append(part);
                currentLineLength += part.length();
                if (++lineCount >= limitNumberOfLines) {
                    book.append(page);
                    page = Page();
                    lineCount = 0;
                    pageCount += 1;
                    limitNumberOfLines = defineNumberOfLines(pageCount, numberOfLines, numberOfLinesInTheFirstPage, numberOfLinesInTheTenthPage);
                }
            }
        }
        else {
            if (currentLineLength + word.length() + 1 > sizeOfLine) {
                if (currentLineLength > 0) {
                    page.append(line);
                    lineCount++;
                    line = Line();
                    currentLineLength = 0;
                }
                if (lineCount >= limitNumberOfLines) {
                    book.append(page);
                    page = Page();
                    lineCount = 0;
                    pageCount += 1;
                    limitNumberOfLines = defineNumberOfLines(pageCount, numberOfLines, numberOfLinesInTheFirstPage, numberOfLinesInTheTenthPage);
                }
            }
            if (currentLineLength > 0) {
                line.append(" ");
                currentLineLength++;
            }
            line.append(word);
            currentLineLength += word.length();
        }
    }
    if (currentLineLength > 0) {
        page.append(line);
        lineCount++;
    }
    if (lineCount > 0) {
        book.append(page);
    }

    return book;
}

