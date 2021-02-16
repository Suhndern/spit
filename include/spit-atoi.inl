// stop if view is empty
if (str.empty())
    return 0;

// store char width
const int width = sizeof str[0];

// initialize 8-byte or <str.size()> limit
const int lim = spit::min(8, str.size() * width);

auto result = 0ULL;
// add <str[i]> to byte <i * width> of <result>
for (int i = 0; i * width < lim; i++) {
    result += (0ULL + str[i]) << i * width * byte;
}

return result;
