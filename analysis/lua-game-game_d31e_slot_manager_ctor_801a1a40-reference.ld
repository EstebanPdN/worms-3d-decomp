/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__14SessionManager)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
__builtin_new = 0x801fe1d8;
__vt_14SessionManager = 0x804139c0;
__vt_5ConnA = 0x804139a0;
__vt_5ConnB = 0x80413980;
__vt_5Iface = 0x804139e0;
gDest = 0x8045ce2c;
insert_unique__Q24_STLt8_Rb_tree5ZP10SignalBaseZP10SignalBaseZQ24_STLt9_Identity1ZP10SignalBaseZQ24_STLt4less1ZP10SignalBaseZQ24_STLt9allocator1ZP10SignalBaseRCP10SignalBase = 0x80352710;
malloc = 0x80212fd4;
onA__4Dest = 0x80352868;
onB__4DestPv = 0x8035288c;
w3d_cx10b_global_service_append_8021008c = 0x8021008c;
w3d_local_static_801ea954 = 0x801ea954;
SECTIONS {
  .text.__14SessionManager 0x801a1a40 : { *(.text.__14SessionManager) }
  .rodata 0x803a9b84 : { *(.rodata) }
  .sdata 0x804ab74c (NOLOAD) : {
    . = 0x0; gManager = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
