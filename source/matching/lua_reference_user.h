#ifndef W3D_LUA_REFERENCE_USER_H
#define W3D_LUA_REFERENCE_USER_H

/* GameCube reference-build hook observed at 0x802cd7dc. The allocation
 * supplied by the original engine has extra state storage at offset 0x58.
 * Its broader purpose remains unknown. Do not enable this hook in an
 * unmodified upstream host runtime whose lua_State allocation lacks it.
 */
#define lua_userstateopen(state) \
    (*(unsigned int *)((unsigned char *)(state) + 0x58) = 0U)

#endif
