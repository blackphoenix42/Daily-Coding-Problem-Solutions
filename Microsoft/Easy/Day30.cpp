/*
This problem was asked Microsoft.

Using a read7() method that returns 7 characters from a file, implement readN(n) which reads n characters.

For example, given a file with the content “Hello world”, three read7() returns “Hello w”, “orld” and then “”.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FileReader
{
private:
    string fileContent;
    int filePointer;

    char leftover[7]; // Buffer to store leftover chars from previous read7
    int leftoverSize = 0;
    int leftoverIndex = 0;

public:
    FileReader(string content) : fileContent(content), filePointer(0) {}

    // Simulates reading 7 chars from file
    int read7(char *buf)
    {
        int i = 0;
        while (i < 7 && filePointer < fileContent.size())
        {
            buf[i++] = fileContent[filePointer++];
        }
        return i;
    }

    // Reads n characters from file using read7, supports multiple calls
    int readN(char *buf, int n)
    {
        int totalRead = 0;

        // Use leftover characters first
        while (leftoverSize > 0 && totalRead < n)
        {
            buf[totalRead++] = leftover[leftoverIndex++];
            leftoverSize--;
        }

        // Fetch new data using read7
        while (totalRead < n)
        {
            char temp[7];
            int charsRead = read7(temp);

            if (charsRead == 0)
                break;

            int toCopy = min(charsRead, n - totalRead);

            // Copy needed chars to buf
            for (int i = 0; i < toCopy; ++i)
            {
                buf[totalRead++] = temp[i];
            }

            // Save any extra chars in leftover buffer
            if (charsRead > toCopy)
            {
                for (int i = toCopy; i < charsRead; ++i)
                {
                    leftover[i - toCopy] = temp[i];
                }
                leftoverSize = charsRead - toCopy;
                leftoverIndex = 0;
            }
        }

        return totalRead;
    }
};

int main()
{
    FileReader reader("Hello world");

    char buf1[100];
    int read1 = reader.readN(buf1, 5);
    buf1[read1] = '\0';
    cout << "First read (5): " << buf1 << endl;

    char buf2[100];
    int read2 = reader.readN(buf2, 4);
    buf2[read2] = '\0';
    cout << "Second read (4): " << buf2 << endl;

    char buf3[100];
    int read3 = reader.readN(buf3, 5);
    buf3[read3] = '\0';
    cout << "Third read (5): " << buf3 << endl;

    return 0;
}
