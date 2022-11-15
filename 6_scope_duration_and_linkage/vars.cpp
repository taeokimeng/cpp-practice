int g_a; // non-constant globals have external linkage by default

extern const int g_b{1};
extern constexpr int g_c{2}; // constexpr cannot be forward declared

int g_d = 3;
extern const int g_e = 4;
// not allowed: constexpr variables can't be forward declared
/* extern constexpr int g_f; */ 
