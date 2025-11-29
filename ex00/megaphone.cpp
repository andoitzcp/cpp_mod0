#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    i = 1;
    while(i < argc)
    {
        j = 0;
        while (argv[i][j] != '\0')
            std::cout <<(char) std::toupper(argv[i][j++]);
        i++;
    }
    std::cout << std::endl;
    return(0);
}

// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <locale>
// #include <cwctype>  // Missing include for std::towupper

// int main() {
//     std::setlocale(LC_ALL, "es_ES.utf8");
//     std::wstring text = L"hola holañ!";
//     std::transform(text.begin(), text.end(), text.begin(),
//                    [](wchar_t c) { return std::towupper(c); });
//     std::wcout << L"Uppercase: " << text << std::endl;
//     return 0;
// }
