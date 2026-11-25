/* Minimal declarations for controlled freestanding reference compilation.
 * No libc implementation is provided by these headers.
 */
#ifndef W3D_REFERENCE_ASSERT_H
#define W3D_REFERENCE_ASSERT_H
#ifdef NDEBUG
#define assert(expression) ((void)0)
#else
void __w3d_reference_assert_failure(const char *, const char *, int);
#define assert(expression) ((expression) ? (void)0 : __w3d_reference_assert_failure(#expression, __FILE__, __LINE__))
#endif
#endif
