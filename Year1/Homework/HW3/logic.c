#include "logic.h"

bool cOut, tmpS, tmpC;
bool z0, z1, z2, z3, z4, z5, z6, z7;

bool norGate(bool a, bool b) {
    return !(a || b);
}

bool notGate(bool a){
    return norGate(a, a);
}

bool nandGate(bool a, bool b){
    return norGate(norGate(norGate(a, a), norGate(b, b)), norGate(norGate(a, a), norGate(b, b )));
}

bool xorGate(bool a, bool b){
    return norGate(norGate(a, b), norGate(norGate(a, a), norGate(b, b)));
}

bool xnorGate(bool a, bool b){
    return norGate(norGate(a, norGate(a, b)), norGate(norGate(a, b), b));
}

bool andGate(bool a, bool b){
    return norGate(norGate(a, a), norGate(b, b));
}

bool orGate(bool a, bool b){
    return norGate(norGate(a, b), norGate(a, b));
}

bool halfAdder(bool a, bool b){
    cOut = and(a, b);
    return xor(a, b)
}

bool fullAdder(bool a, bool b, bool c){
    cOut = or(and(xor(a, b), c), and(a, b));
    return xor(xor(a, b), c);
}

void output(bool a1, bool a2, bool a3, bool a4, bool b1, bool b2, bool b3, bool b4){
    printf("A = %d%d%d%d (2) = %d (10)\n", a4, a3, a2, a1, ((a4 * 2 * 2 * 2) + (a3 * 2 * 2) + (a2 * 2) + (a1)));
    printf("B = %d%d%d%d (2) = %d (10)\n", b4, b3, b2, b1, ((b4 * 2 * 2 * 2) + (b3 * 2 * 2) + (b2 * 2) + (b1)));
}

void multiply(bool a1, bool a2, bool a3, bool a4, bool b1, bool b2, bool b3, bool b4){
    output(a1, a2, a3, a4, b1, b2, b3, b4);
    z0 = andGate(a1, b1);
    z1 = halfAdder(andGate(a2, b1), andGate(a1, b2));
    tmpC = cOut;
    z2 = halfAdder(fullAdder(andGate(a3, b1), andGate(a2, b2), tmpC), andGate(a1, b3));
}