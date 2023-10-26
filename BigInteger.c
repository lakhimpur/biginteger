#include <stdlib.h>
#include <stdio.h>
#include "BigInteger.h"

struct BigInteger {
    int value;
    struct BigInteger* next;
};

struct BigInteger* initialize(int val) {
    struct BigInteger* newNode = (struct BigInteger*)malloc(sizeof(struct BigInteger));
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

struct BigInteger* add(struct BigInteger* num1, struct BigInteger* num2) {
    struct BigInteger* dummyHead = initialize(0);
    struct BigInteger* current = dummyHead;
    int carry = 0;

    while (num1 || num2) {
        int x = num1 ? num1->value : 0;
        int y = num2 ? num2->value : 0;
        int sum = x + y + carry;

        carry = sum / 10;
        current->next = initialize(sum % 10);
        current = current->next;

        if (num1) num1 = num1->next;
        if (num2) num2 = num2->next;
    }

    if (carry > 0) {
        current->next = initialize(carry);
    }

    return dummyHead->next;
}

struct BigInteger* mul(struct BigInteger* num1, struct BigInteger* num2) {
    struct BigInteger* result = initialize(0);

    while (num1) {
        struct BigInteger* current = result;
        int carry = 0;
        struct BigInteger* num2Copy = num2;

        while (num2Copy || carry) {
            int x = num1->value;
            int y = num2Copy ? num2Copy->value : 0;
            int product = x * y + carry;

            if (current->next) {
                product += current->next->value;
                current->next->value = product % 10;
            } else {
                current->next = initialize(product % 10);
            }

            carry = product / 10;

            if (num2Copy) num2Copy = num2Copy->next;
            if (!current->next) {
                current->next = initialize(0);
            }

            current = current->next;
        }

        num1 = num1->next;
        result = add(result, initialize(0));
    }

    return result;
}

void display(struct BigInteger* head) {
    if (head == NULL) {
        return;
    }
    display(head->next);
    printf("%d", head->value);
}

struct BigInteger* sub(struct BigInteger* num1, struct BigInteger* num2) {
    struct BigInteger* dummyHead = (struct BigInteger*)malloc(sizeof(struct BigInteger));
    struct BigInteger* current = dummyHead;
    int borrow = 0;

    while (num1 || num2) {
        int x = num1 ? num1->value : 0;
        int y = num2 ? num2->value : 0;
        int difference = x - y - borrow;

        if (difference < 0) {
            difference += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        current->next = (struct BigInteger*)malloc(sizeof(struct BigInteger));
        current->next->value = difference;
        current->next->next = NULL;
        current = current->next;

        if (num1) num1 = num1->next;
        if (num2) num2 = num2->next;
    }

    struct BigInteger* result = dummyHead->next;
    free(dummyHead);
    return result;
}

// struct BigInteger* div1(struct BigInteger* dividend, struct BigInteger* divisor) {
//     if (divisor == NULL || divisor->value == 0) {
//         printf("Error: Division by zero\n");
//         return NULL;
//     }

//     struct BigInteger* result = initialize(0);
//     struct BigInteger* current = result;
//     struct BigInteger* temp;

//     while (dividend != NULL) {
//         int quotient = 0;
//         while (dividend != NULL && isGreaterOrEqual(dividend, divisor)) {
//             dividend = sub(dividend, divisor);
//             quotient++;
//         }

//         current->value = quotient;
//         if (dividend != NULL) {
//             temp = initialize(0);
//             current->next = temp;
//             current = current->next;
//         }
//     }

//     return result;
// }
