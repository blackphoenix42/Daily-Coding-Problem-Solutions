/*
This problem was asked by Microsoft.

Implement a URL shortener with the following methods:

shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.
restore(short), which expands the shortened string into the original url. If no such shortened string exists, return null.
Hint: What if we enter the same URL twice?

*/

#include <bits/stdc++.h>
using namespace std;

class URLShortener
{
private:
    unordered_map<string, string> urlMap;
    unordered_map<string, string> reverseMap;
    const string characters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string generateShortUrl()
    {
        srand(time(0));
        string shortUrl;
        for (int i = 0; i < 6; ++i)
        {
            shortUrl += characters[rand() % characters.size()];
        }
        return shortUrl;
    }

public:
    string shorten(const string &url)
    {
        if (reverseMap.find(url) != reverseMap.end())
        {
            return reverseMap[url];
        }

        string shortUrl = generateShortUrl();
        while (urlMap.find(shortUrl) != urlMap.end())
        {
            shortUrl = generateShortUrl();
        }

        urlMap[shortUrl] = url;
        reverseMap[url] = shortUrl;

        return shortUrl;
    }

    string restore(const string &shortUrl)
    {
        if (urlMap.find(shortUrl) != urlMap.end())
        {
            return urlMap[shortUrl];
        }
        return "";
    }
};

int main()
{
    URLShortener urlShortener;

    string originalUrl = "https://github.com/blackphoenix42/Daily-Coding-Problem";
    string shortUrl = urlShortener.shorten(originalUrl);
    cout << "Original URL: " << originalUrl << endl;
    cout << "Shortened URL: " << shortUrl << endl;

    string restoredUrl = urlShortener.restore(shortUrl);
    cout << "Restored URL: " << restoredUrl << endl;

    return 0;
}