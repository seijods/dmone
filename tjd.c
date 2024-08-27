#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#define MAX_LEN 100

// ひらがなとモールス信号の対応表
typedef struct {
    wchar_t *hiragana;
    char *morse;
} MorseCode;

MorseCode morse_table[] = {
    {L"い", ".-"},
    {L"ろ", ".-.-"},
    {L"は", "-..."},
    {L"に", ".-.-"},
    {L"ほ", "-.."},
    {L"へ", "."},
    {L"と", "..-.."},
    //ここまで//
    {L"く", "..-."},
    {L"け", "-.-.."},
    {L"こ", "--."},
    {L"さ", ".-.-"},
    {L"し", "--.-"},
    {L"す", "---."},
    {L"せ", "---"},
    {L"そ", "-.-"},
    {L"た", "-."},
    {L"ち", "..-"},
    {L"つ", ".--."},
    {L"て", ".-..."},
    {L"と", "..-.."},
    {L"な", ".-."},
    {L"に", "-.-.-"},
    {L"ぬ", "...."},
    {L"ね", "--.--"},
    {L"の", ".-.-."},
    {L"は", "-..."},
    {L"ひ", "--..-"},
    {L"ふ", "--.."},
    {L"へ", "."},
    {L"ほ", "-.."},
    {L"ま", "-..-"},
    {L"み", "..-.-"},
    {L"む", "-"},
    {L"め", "-...-"},
    {L"も", "-..-."},
    {L"や", ".--"},
    {L"ゆ", "-..--"},
    {L"よ", "--"},
    {L"ら", "..."},
    {L"り", "--.-."},
    {L"る", "-.--."},
    {L"れ", ".---"},
    {L"ろ", "---"},
    {L"わ", "-.-"},
    {L"を", ".---."},
    {L"ん", "--.--"},
    {L"が", "-.-.."},
    {L"ぎ", "-.--.."},
    {L"ぐ", "..-..."},
    {L"げ", "-.-..."},
    {L"ご", "--.."},
    {L"ざ", ".-.-."},
    {L"じ", "--.-.."},
    {L"ず", "---.."},
    {L"ぜ", "---..."},
    {L"ぞ", "-.-.."},
    {L"だ", "-.."},
    {L"ぢ", "..-.."},
    {L"づ", ".--.."},
    {L"で", ".-...."},
    {L"ど", "..-..."},
    {L"ば", "-..."},
    {L"び", "--..-."},
    {L"ぶ", "--..."},
    {L"べ", ".-"},
    {L"ぼ", "-..-"},
    {L"ぱ", "-..."},
    {L"ぴ", "--..-.."},
    {L"ぷ", "--...."},
    {L"ぺ", ".-.."},
    {L"ぽ", "-..-."}
};

// ひらがなをモールス信号に変換する関数
char* hiragana_to_morse(wchar_t hiragana) {
    for (int i = 0; i < sizeof(morse_table) / sizeof(morse_table[0]); i++) {
        if (hiragana == *morse_table[i].hiragana) {
            return morse_table[i].morse;
        }
    }
    return NULL; // 対応するモールス信号が見つからない場合
}

void convert_to_morse(const wchar_t *input) {
    char *morse;

    for (int i = 0; i < wcslen(input); i++) {
        morse = hiragana_to_morse(input[i]);
        if (morse != NULL) {
            printf("%s", morse);
            if (i < wcslen(input) - 1) {
                printf(" "); // 次の文字がある場合はスペースを追加
            }
        } else {
            printf("? "); // 未対応の文字があれば "?" を出力
        }
    }
    printf("\n");
}

int main() {
    setlocale(LC_CTYPE, "");  // ロケールの設定

    wchar_t input[MAX_LEN];
    
    wprintf(L"ひらがなの文字列を入力してください: ");
    fgetws(input, MAX_LEN, stdin);

    // 改行文字を除去
    input[wcslen(input) - 1] = L'\0';

    printf("モールス信号: ");
    convert_to_morse(input);

    return 0;
}
