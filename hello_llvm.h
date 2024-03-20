// #ifndef SANDBOXCPP_LLVM
// #define SANDBOXCPP_LLVM

// #include <stddef.h>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <variant>
// #include <expected>
// #include <regex>
// #include <cassert>

// #include <unicode/unistr.h>
// #include <unicode/regex.h>

// UErrorCode re_keyword_status = U_ZERO_ERROR;
// UErrorCode re_ident_status = U_ZERO_ERROR;
// UErrorCode re_decimal_status = U_ZERO_ERROR;
// icu::RegexMatcher re_keyword(icu::UnicodeString::fromUTF8(R"(^(auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while)\b)"), 0, re_keyword_status);
// icu::RegexMatcher re_ident(icu::UnicodeString::fromUTF8(R"(^[A-Za-z_][A-Za-z0-9_]*)"), 0, re_ident_status);
// icu::RegexMatcher re_decimal(icu::UnicodeString::fromUTF8(R"(^([0-9]+\.[0-9]+|[0-9]+\.|\.[0-9]+))"), 0, re_decimal_status);

// void assert_regex_construction() {
//     assert(U_SUCCESS(re_keyword_status));
//     assert(U_SUCCESS(re_ident_status));
//     assert(U_SUCCESS(re_decimal_status));
// }

// // std::regex re_keyword(R"(^(auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while)\b)");
// // std::regex re_ident(R"(^[A-Za-z_][A-Za-z0-9_]*)");
// // std::regex re_decimal(R"(^([0-9]+\.[0-9]+|[0-9]+\.|\.[0-9]+))");

// struct UnicodeStringView
// {
//     icu::UnicodeString &s;
//     size_t start;
//     size_t len;
// };

// enum TokenTag
// {
//     syntax,
//     keyword,
//     ident,
//     num,
// };

// struct Token
// {
//     TokenTag tag;

//     // UnicodeStringView -> TokenTag:: syntax, keyword, ident
//     // double ->  TokenTag:: num
//     std::variant<UnicodeStringView, double> variant;
// };

// std::expected<std::pair<Token, size_t>, size_t> lex_token(icu::UnicodeString &src, size_t pos)
// {
//     src = src;
//     pos = pos;

//     return std::unexpected(0);
// }

// std::expected<std::vector<Token>, size_t> lex(icu::UnicodeString &src)
// {
//     assert_regex_construction(); // just a sanity check to make sure the regexes didn't fail to construct

//     if (src.isEmpty())
//     {
//         return std::vector<Token>();
//     }

//     std::vector<Token> tokens{};
//     size_t pos = 0;

//     while (true)
//     {
//         for (UChar32 ch = src.char32At(pos); ch == U' ' || ch == U'\n'; ch = src.char32At(++pos))
//         {
//         }

//         if (src.char32At(pos) != 0xffff)
//         {
//             break;
//         }

//         std::expected<std::pair<Token, size_t>, size_t> token_result = lex_token(src, pos);
//         if (!token_result.has_value())
//         {
//             return std::unexpected(token_result.error());
//         }

//         std::pair<Token, size_t> pair = std::move(token_result.value()); // is this still a copy?
//         Token token = pair.first;                                        // can copying be avoided here?
//         size_t next_pos = pair.second;

//         tokens.push_back(token);
//         pos = next_pos;
//     }

//     return tokens;
// }

// #endif
