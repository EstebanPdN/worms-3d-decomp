/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__8Renderer)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
__3Svc = 0x80209ccc;
__5ItemAi = 0x801bddf0;
__5ItemBi = 0x801bdfe4;
__7FullTag = 0x801e81c8;
__builtin_new = 0x801fe1d8;
__vt_4Base = 0x80413d30;
__vt_4Dest = 0x80413ca8;
__vt_5ConnB = 0x80413c88;
__vt_8HasSlots = 0x80413a38;
__vt_8Renderer = 0x80413cc0;
alloc_80212fd4 = 0x80212fd4;
atexit = 0x802ed7e0;
f_803aa0ec = 0x803aa0ec;
free = 0x802134fc;
free_802134fc = 0x802134fc;
insert_unique__Q24_STLt8_Rb_tree5ZP10SignalBaseZP10SignalBaseZQ24_STLt9_Identity1ZP10SignalBaseZQ24_STLt4less1ZP10SignalBaseZQ24_STLt9allocator1ZP10SignalBaseRCP10SignalBase = 0x80352710;
k_80363b54 = 0x80363b54;
k_80363bf4 = 0x80363bf4;
k_80363c44 = 0x80363c44;
malloc = 0x80212fd4;
memcpy_802eee50 = 0x802eee50;
memmove = 0x802eeef4;
onB__4DestPv = 0x80355690;
w3d_d26k_initialise_class_80210370 = 0x80210370;
w3d_local_static_801ea954 = 0x801ea954;
w3d_r24b_invoke_ready_callback_8020fcb4 = 0x8020fcb4;
SECTIONS {
  .text.__8Renderer 0x801a81c4 : { *(.text.__8Renderer) }
  .rodata 0x803aa0a4 : { *(.rodata) }
  .bss 0x8045ce4c : { *(.bss) }
  .sbss 0x804b0338 : { *(.sbss) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
