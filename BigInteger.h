#ifndef BigInteger1
#define BigInteger1
struct BigInteger* initialize(int value);
struct BigInteger* add(struct BigInteger* num1, struct BigInteger* num2);
struct BigInteger* mul(struct BigInteger* num1, struct BigInteger* num2);
struct BigInteger* sub(struct BigInteger* num1, struct BigInteger* num2);
// struct BigInteger* div1(struct BigInteger* dividend, struct BigInteger* divisor);
void display(struct BigInteger* head);
int isGreaterOrEqual(struct BigInteger* num1, struct BigInteger* num2);
#endif


