#ifndef FLANCK_TOKEN_H
#define FLANCK_TOKEN_H
enum class Token {
    Open, //[
    Close, //]
    Value, //binary value
    Divider, //:
    Eof, //end of file
};
#endif //FLANCK_TOKEN_H
