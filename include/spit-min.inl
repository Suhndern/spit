// check if compiler uses logical signed shifts
if constexpr (-1 >> 1 > 0) {
    return (x < y) ? x : y;
}
else {
    // perform <sizeof diff * byte - 1> arithmetic right-shifts
    // bitwise AND <diff> against right-shifted <diff>, then add <diff> to <y>
    const int diff = x - y;
    return y + (diff & diff >> sizeof diff * byte - 1);
}


